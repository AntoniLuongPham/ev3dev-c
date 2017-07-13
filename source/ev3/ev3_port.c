
/*  ev3_port.c was generated by yup.py (yupp) 1.0c2
    out of ev3_port.yu-c 
 *//**
 *  \file  ev3_port.c (ev3_port.yu-c)
 *  \brief  EV3 Ports.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#define EV3_PORT_IMPLEMENT

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "modp_numtoa.h"
#include "ev3.h"
#include "ev3_port.h"

#define PATH_PREF_LEN  25
#define DESC_SPOT  "///"

#define PATH_ADDRESS  "/sys/class/lego-port/port" DESC_SPOT "address"
#define PATH_DRIVER_NAME  "/sys/class/lego-port/port" DESC_SPOT "driver_name"
#define PATH_MODE  "/sys/class/lego-port/port" DESC_SPOT "mode"
#define PATH_MODES  "/sys/class/lego-port/port" DESC_SPOT "modes"
#define PATH_SET_DEVICE  "/sys/class/lego-port/port" DESC_SPOT "set_device"
#define PATH_STATUS  "/sys/class/lego-port/port" DESC_SPOT "status"

size_t get_port_address( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_ADDRESS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_port_driver_name( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_DRIVER_NAME;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t get_port_mode( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_MODE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_port_mode( uint8_t sn, char *value )
{
	char s[] = PATH_MODE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t multi_set_port_mode( uint8_t *sn, char *value )
{
	char s[] = PATH_MODE;

	return ev3_multi_write_char_array( sn, PATH_PREF_LEN, s, value );
}

size_t get_port_modes( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_MODES;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

size_t set_port_set_device( uint8_t sn, char *value )
{
	char s[] = PATH_SET_DEVICE;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_write_char_array( s, value );
}

size_t multi_set_port_set_device( uint8_t *sn, char *value )
{
	char s[] = PATH_SET_DEVICE;

	return ev3_multi_write_char_array( sn, PATH_PREF_LEN, s, value );
}

size_t get_port_status( uint8_t sn, char *buf, size_t sz )
{
	char s[] = PATH_STATUS;
	*modp_uitoa10( sn, s + PATH_PREF_LEN ) = '/';

	return ev3_read_char_array( s, buf, sz );
}

const char *ev3_port_type( INX_T type_inx )
{
	switch ( type_inx ) {
	case HT_NXT_SMUX_PORT:
		return "ht-nxt-smux-port";
	case LEGOEV3_INPUT_PORT:
		return "legoev3-input-port";
	case LEGOEV3_OUTPUT_PORT:
		return "legoev3-output-port";
	case MS_EV3_SMUX_PORT:
		return "ms-ev3-smux-port";
	case MS_NXTMMX_OUT_PORT:
		return "ms-nxtmmx-out-port";
	case WEDO_PORT:
		return "wedo-port";

	}
	return ( STR_unknown_ );
}

INX_T get_port_type_inx( uint8_t sn )
{
	char buf[ 64 ];

	if ( !get_port_driver_name( sn, buf, sizeof( buf ))) return ( PORT_TYPE__NONE_ );

	if ( strcmp( buf, "ht-nxt-smux-port" ) == 0 ) return HT_NXT_SMUX_PORT;
	if ( strcmp( buf, "legoev3-input-port" ) == 0 ) return LEGOEV3_INPUT_PORT;
	if ( strcmp( buf, "legoev3-output-port" ) == 0 ) return LEGOEV3_OUTPUT_PORT;
	if ( strcmp( buf, "ms-ev3-smux-port" ) == 0 ) return MS_EV3_SMUX_PORT;
	if ( strcmp( buf, "ms-nxtmmx-out-port" ) == 0 ) return MS_NXTMMX_OUT_PORT;
	if ( strcmp( buf, "wedo-port" ) == 0 ) return WEDO_PORT;

	return ( PORT_TYPE__UNKNOWN_ );
}

size_t get_port_desc( uint8_t sn, EV3_PORT *desc )
{
	uint8_t addr;
	char buf[ 32 ];

	desc->type_inx = get_port_type_inx( sn );
	if ( desc->type_inx == PORT_TYPE__NONE_ ) return ( 0 );

	if ( !get_port_address( sn, buf, sizeof( buf ))) return ( 0 );

	ev3_parse_port_name( buf, &desc->port, &desc->extport, &addr );
	desc->addr = addr;

	return ( sizeof( EV3_PORT ));
}

EV3_PORT *ev3_port_desc( uint8_t sn )
{
	if ( sn >= PORT_DESC__LIMIT_) sn = PORT_DESC__LIMIT_ - 1;
	return ( ev3_port + sn );
}

INX_T ev3_port_desc_type_inx( uint8_t sn )
{
	return ( ev3_port_desc( sn )->type_inx );
}

uint8_t ev3_port_desc_port( uint8_t sn )
{
	return ( ev3_port_desc( sn )->port );
}

uint8_t ev3_port_desc_extport( uint8_t sn )
{
	return ( ev3_port_desc( sn )->extport );
}

uint8_t ev3_port_desc_addr( uint8_t sn )
{
	return ( ev3_port_desc( sn )->addr );
}

char *ev3_port_port_name( uint8_t sn, char *buf )
{
	return ( ev3_port_name( ev3_port_desc( sn )->port, ev3_port_desc( sn )->extport, ev3_port_desc( sn )->addr, buf ));
}

bool ev3_search_port_type( INX_T type_inx, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < PORT_DESC__LIMIT_) {
		if ( ev3_port[ _sn ].type_inx == type_inx ) {
			*sn = _sn;
			return ( true );
		}
		++_sn;
	}
	*sn = PORT__NONE_;
	return ( false );
}

bool ev3_search_port_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from )
{
	uint8_t _sn = from;

	while ( _sn < PORT_DESC__LIMIT_) {
		if ( ev3_port[ _sn ].port == port ) {
			if ( extport ) {
				if ( ev3_port[ _sn ].extport == extport ) {
					*sn = _sn;
					return ( true );
				}
			} else {
				*sn = _sn;
				return ( true );
			}
		}
		++_sn;
	}
	*sn = PORT__NONE_;
	return ( false );
}

const char *ev3_port_mode( INX_T mode_inx )
{
	switch ( mode_inx ) {
	case HT_NXT_SMUX_PORT_ANALOG:
		return "analog";
	case HT_NXT_SMUX_PORT_I2C:
		return "i2c";

	case LEGOEV3_INPUT_PORT_AUTO:
		return "auto";
	case LEGOEV3_INPUT_PORT_NXT_ANALOG:
		return "nxt-analog";
	case LEGOEV3_INPUT_PORT_NXT_COLOR:
		return "nxt-color";
	case LEGOEV3_INPUT_PORT_NXT_I2C:
		return "nxt-i2c";
	case LEGOEV3_INPUT_PORT_OTHER_I2C:
		return "other-i2c";
	case LEGOEV3_INPUT_PORT_EV3_ANALOG:
		return "ev3-analog";
	case LEGOEV3_INPUT_PORT_EV3_UART:
		return "ev3-uart";
	case LEGOEV3_INPUT_PORT_OTHER_UART:
		return "other-uart";
	case LEGOEV3_INPUT_PORT_RAW:
		return "raw";

	case LEGOEV3_OUTPUT_PORT_AUTO:
		return "auto";
	case LEGOEV3_OUTPUT_PORT_TACHO_MOTOR:
		return "tacho-motor";
	case LEGOEV3_OUTPUT_PORT_DC_MOTOR:
		return "dc-motor";
	case LEGOEV3_OUTPUT_PORT_LED:
		return "led";
	case LEGOEV3_OUTPUT_PORT_RAW:
		return "raw";

	case MS_EV3_SMUX_PORT_UART:
		return "uart";
	case MS_EV3_SMUX_PORT_ANALOG:
		return "analog";

	case MS_NXTMMX_OUT_PORT_TACHO_MOTOR:
		return "tacho-motor";

	case WEDO_PORT_AUTO:
		return "auto";

	}
	return ( STR_unknown_ );
}

INX_T get_port_mode_inx_of_type( uint8_t sn, INX_T type_inx )
{
	char buf[ 64 ];

	if ( !get_port_mode( sn, buf, sizeof( buf ))) return ( PORT_MODE__NONE_ );

	switch ( type_inx ) {
			
	case HT_NXT_SMUX_PORT:
		if ( strcmp( buf, "analog" ) == 0 ) return HT_NXT_SMUX_PORT_ANALOG;
		if ( strcmp( buf, "i2c" ) == 0 ) return HT_NXT_SMUX_PORT_I2C;

		break;

	case LEGOEV3_INPUT_PORT:
		if ( strcmp( buf, "auto" ) == 0 ) return LEGOEV3_INPUT_PORT_AUTO;
		if ( strcmp( buf, "nxt-analog" ) == 0 ) return LEGOEV3_INPUT_PORT_NXT_ANALOG;
		if ( strcmp( buf, "nxt-color" ) == 0 ) return LEGOEV3_INPUT_PORT_NXT_COLOR;
		if ( strcmp( buf, "nxt-i2c" ) == 0 ) return LEGOEV3_INPUT_PORT_NXT_I2C;
		if ( strcmp( buf, "other-i2c" ) == 0 ) return LEGOEV3_INPUT_PORT_OTHER_I2C;
		if ( strcmp( buf, "ev3-analog" ) == 0 ) return LEGOEV3_INPUT_PORT_EV3_ANALOG;
		if ( strcmp( buf, "ev3-uart" ) == 0 ) return LEGOEV3_INPUT_PORT_EV3_UART;
		if ( strcmp( buf, "other-uart" ) == 0 ) return LEGOEV3_INPUT_PORT_OTHER_UART;
		if ( strcmp( buf, "raw" ) == 0 ) return LEGOEV3_INPUT_PORT_RAW;

		break;

	case LEGOEV3_OUTPUT_PORT:
		if ( strcmp( buf, "auto" ) == 0 ) return LEGOEV3_OUTPUT_PORT_AUTO;
		if ( strcmp( buf, "tacho-motor" ) == 0 ) return LEGOEV3_OUTPUT_PORT_TACHO_MOTOR;
		if ( strcmp( buf, "dc-motor" ) == 0 ) return LEGOEV3_OUTPUT_PORT_DC_MOTOR;
		if ( strcmp( buf, "led" ) == 0 ) return LEGOEV3_OUTPUT_PORT_LED;
		if ( strcmp( buf, "raw" ) == 0 ) return LEGOEV3_OUTPUT_PORT_RAW;

		break;

	case MS_EV3_SMUX_PORT:
		if ( strcmp( buf, "uart" ) == 0 ) return MS_EV3_SMUX_PORT_UART;
		if ( strcmp( buf, "analog" ) == 0 ) return MS_EV3_SMUX_PORT_ANALOG;

		break;

	case MS_NXTMMX_OUT_PORT:
		if ( strcmp( buf, "tacho-motor" ) == 0 ) return MS_NXTMMX_OUT_PORT_TACHO_MOTOR;

		break;

	case WEDO_PORT:
		if ( strcmp( buf, "auto" ) == 0 ) return WEDO_PORT_AUTO;

		break;

	}
	return ( PORT_MODE__UNKNOWN_ );
}

INX_T get_port_mode_inx( uint8_t sn )
{
	return get_port_mode_inx_of_type( sn, ev3_port_desc( sn )->type_inx );
}

size_t set_port_mode_inx( uint8_t sn, INX_T mode_inx )
{
	return set_port_mode( sn, ( char *) ev3_port_mode( mode_inx ));
}

size_t multi_set_port_mode_inx( uint8_t *sn, INX_T mode_inx )
{
	return multi_set_port_mode( sn, ( char *) ev3_port_mode( mode_inx ));
}

int ev3_port_init( void )
{
	char list[ 256 ];
	char *p;
	uint32_t sn;
	int cnt = 0;

	memset( ev3_port, 0, sizeof( ev3_port ));

	if ( !ev3_listdir( "/sys/class/lego-port", list, sizeof( list ))) return ( -1 );

	p = strtok( list, " " );
	while ( p ) {
		if (( ev3_string_suffix( "port", &p, &sn ) == 1 ) && ( sn < PORT_DESC__LIMIT_)) {
			get_port_desc( sn, ev3_port + sn );
			++cnt;
		}
		p = strtok( NULL, " " );
	}
	return ( cnt );
}

#define IN_PREF_LEN  2
#define OUT_PREF_LEN  3
#define I2C_PREF_LEN  3
#define MUX_PREF_LEN  3
#define SV_PREF_LEN  2
#define M_PREF_LEN  1
#define WEDO_PREF_LEN  4

void ev3_parse_port_name( char *name, uint8_t *port, uint8_t *extport, uint8_t *addr )
{
	*port = EV3_PORT__NONE_;
	*extport = EXT_PORT__NONE_;
	*addr = 0;

	if ( strncmp( name, "in", IN_PREF_LEN ) == 0 ) {
		/* "in" */
		name += IN_PREF_LEN;
		*port = *name++;
		if ( *name != ':' ) return;
		++name;
						
		if ( strncmp( name, "i2c", I2C_PREF_LEN ) == 0 ) {
			/* "i2c" */
			name += I2C_PREF_LEN;
			*addr = strtoul( name, &name, 0 );
			if ( *name != ':' ) return;
			++name;
									
			if ( strncmp( name, "mux", MUX_PREF_LEN ) == 0 ) {
				/* "mux" */
				name += MUX_PREF_LEN;
				*extport = *name++;
				if ( *name != ':' ) return;
				++name;
			
				return;
			}				
			if ( strncmp( name, "sv", SV_PREF_LEN ) == 0 ) {
				/* "sv" */
				name += SV_PREF_LEN;
				*extport = *name++ + SERVO__OFFSET_;
				if ( *name != ':' ) return;
				++name;
			
				return;
			}				
			if ( strncmp( name, "M", M_PREF_LEN ) == 0 ) {
				/* "M" */
				name += M_PREF_LEN;
				*extport = *name++ + NXTMMX__OFFSET_;
				if ( *name != ':' ) return;
				++name;
			
				return;
			}		
			return;
		}									
		if ( strncmp( name, "wedo", WEDO_PREF_LEN ) == 0 ) {
			/* "wedo" */
			name += WEDO_PREF_LEN;
			*extport = *name++ + WEDO__OFFSET_;
			if ( *name != ':' ) return;
			++name;
			
			return;
		}
		return;
	}					
	if ( strncmp( name, "out", OUT_PREF_LEN ) == 0 ) {
		/* "out" */
		name += OUT_PREF_LEN;
		*port = *name++;
		if ( *name != ':' ) return;
		++name;
			
		return;
	}										
	return;
}

char *ev3_port_name( uint8_t port, uint8_t extport, uint8_t addr, char *buf )
{
	char *p = buf;

	if (( port >= INPUT_1 ) && ( port <= INPUT_4 )) {
		memcpy( p, "in", IN_PREF_LEN );
		p += IN_PREF_LEN;
		*p++ = port;
						
		if (( addr >= 1 ) && ( addr <= 254 )) {
			memcpy( p, ":""i2c", I2C_PREF_LEN + 1 );
			p += I2C_PREF_LEN + 1;
			p = modp_uitoa10( addr, p );
									
			if (( extport >= MUX_1 ) && ( extport <= MUX_4 )) {
				memcpy( p, ":""mux", MUX_PREF_LEN + 1 );
				p += MUX_PREF_LEN + 1;
				*p++ = extport;
			
				*p = '\x00';
				return ( buf );
			}				
			if (( extport >= SERVO_1 ) && ( extport <= SERVO_8 )) {
				memcpy( p, ":""sv", SV_PREF_LEN + 1 );
				p += SV_PREF_LEN + 1;
				*p++ = extport - SERVO__OFFSET_;
			
				*p = '\x00';
				return ( buf );
			}				
			if (( extport >= NXTMMX_1 ) && ( extport <= NXTMMX_2 )) {
				memcpy( p, ":""M", M_PREF_LEN + 1 );
				p += M_PREF_LEN + 1;
				*p++ = extport - NXTMMX__OFFSET_;
			
				*p = '\x00';
				return ( buf );
			}		
			*p = '\x00';
			return ( buf );
		}									
		if (( extport >= WEDO_1 ) && ( extport <= WEDO_4 )) {
			memcpy( p, ":""wedo", WEDO_PREF_LEN + 1 );
			p += WEDO_PREF_LEN + 1;
			*p++ = extport - WEDO__OFFSET_;
			
			*p = '\x00';
			return ( buf );
		}
		*p = '\x00';
		return ( buf );
	}					
	if (( port >= OUTPUT_A ) && ( port <= OUTPUT_D )) {
		memcpy( p, "out", OUT_PREF_LEN );
		p += OUT_PREF_LEN;
		*p++ = port;
			
		*p = '\x00';
		return ( buf );
	}										
	strcpy( buf, STR_unknown_ );
	return ( buf );
}

uint8_t ev3_search_port( uint8_t port, uint8_t extport )
{
	uint8_t sn;

	ev3_search_port_plugged_in( port, extport, &sn, 0 );
	return ( sn );
}
