/*
     ____ __     ____   ___    ____ __         (((((()
    | |_  \ \  /   ) ) | |  ) | |_  \ \  /  \(@)- /
    |_|__  \_\/  __)_) |_|_/  |_|__  \_\/   /(@)- \
                                               ((())))
 *//**
 *  \file  sensor.c
 *  \brief  ev3dev-c Sensors example.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#include <string.h>
#include <stdio.h>
#include "ev3.h"
#include "ev3_port.h"
#include "ev3_sensor.h"

// WIN32 /////////////////////////////////////////
#ifdef __WIN32__

#include <windows.h>
#include <conio.h>

#define CHAR_ENTER  '\x0D'

/* Non-blocking console input */
static int __getch( void )
{
	return ( kbhit() ? _getch() : EOF );
}

static void getch_init( void )
{
}

static void getch_uninit( void )
{
}

// UNIX //////////////////////////////////////////
#else

#include <unistd.h>
#include <termios.h>

#define Sleep( msec ) usleep(( msec ) * 1000 )

#define CHAR_ENTER  '\x0A'

/* Non-blocking console input */
static int __getch( void )
{
	return fgetc( stdin );
}

static struct termios getch_o_attr;

static void getch_init( void )
{
	struct termios n_attr;

	/* Set terminal to raw mode */
	tcgetattr( fileno( stdin ), &getch_o_attr );
	memcpy( &n_attr, &getch_o_attr, sizeof( struct termios ));
	n_attr.c_lflag &= ~( ECHO | ICANON );
	n_attr.c_cc[ VTIME ] = 0;
	n_attr.c_cc[ VMIN  ] = 0;
	tcsetattr( fileno( stdin ), TCSANOW, &n_attr );
}

static void getch_uninit( void )
{
	/* Restore original terminal attributes */
	tcsetattr( fileno( stdin ), TCSANOW, &getch_o_attr );
}

//////////////////////////////////////////////////
#endif

const char const *color[] = { "?", "BLACK", "BLUE", "GREEN", "YELLOW", "RED", "WHITE", "BROWN" };
#define COLOR_COUNT  (( int )( sizeof( color ) / sizeof( color[ 0 ])))

static bool __pressed( uint8_t sn )
{
	int val;

	if ( sn == SENSOR__NONE_ ) return ( __getch() == CHAR_ENTER );

	return ( get_sensor_value( 0, sn, &val ) && ( val != 0 ));
}

int main( void )
{
	char s[ 256 ];
	int val;
	uint32_t n, i, ii;
	uint8_t sn_touch;
	uint8_t sn_color;

	printf( "Waiting the EV3 brick online...\n" );
	if ( ev3_init() < 1 ) return ( 1 );

	printf( "*** ( EV3 ) Hello! ***\n" );
	ev3_sensor_init();
	getch_init();

	printf( "Found sensors:\n" );
	for ( i = 0; i < SENSOR_DESC__LIMIT_; i++ ) {
		if ( ev3_sensor[ i ].type_inx != SENSOR_TYPE__NONE_ ) {
			printf( "  type = %s\n", ev3_sensor_type( ev3_sensor[ i ].type_inx ));
			printf( "  port = %s\n", ev3_sensor_port_name( i, s ));
			if ( get_sensor_mode( i, s, sizeof( s ))) {
				printf( "  mode = %s\n", s );
			}
			if ( get_sensor_num_values( i, &n )) {
				for ( ii = 0; ii < n; ii++ ) {
					if ( get_sensor_value( ii, i, &val )) {
						printf( "  value%d = %d\n", ii, val );
					}
				}
			}
		}
	}
	if ( ev3_search_sensor( LEGO_EV3_TOUCH, &sn_touch, 0 )) {
		printf( "TOUCH sensor is found, press BUTTON for EXIT...\n" );
	} else {
		printf( "TOUCH sensor is NOT found, press ENTER for EXIT...\n" );
	}
	if ( ev3_search_sensor( LEGO_EV3_COLOR, &sn_color, 0 )) {
		printf( "COLOR sensor is found, reading COLOR...\n" );
		set_sensor_mode( sn_color, "COL-COLOR" );
		for ( ; ; ) {
			if ( !get_sensor_value( 0, sn_color, &val ) || ( val < 0 ) || ( val >= COLOR_COUNT )) {
				val = 0;
			}
			printf( "\r(%s)", color[ val ]);
			fflush( stdout );
			if ( __pressed( sn_touch )) break;
			Sleep( 200 );
			printf( "\r        " );
			fflush( stdout );
			if ( __pressed( sn_touch )) break;
			Sleep( 200 );
		}
	} else {
		printf( "COLOR sensor is NOT found\n" );
		while ( !__pressed( sn_touch )) Sleep( 100 );
	}
	getch_uninit();
	ev3_uninit();
	printf( "\n*** ( EV3 ) Bye! ***\n" );

	return ( 0 );
}
