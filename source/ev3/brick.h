
/*  brick.h was generated by yup.py (yupp) 1.0c2
    out of brick.yu-h 
 *//**
 *  \file  brick.h (brick.yu-h)
 *  \brief  Simplified interface of "ev3dev-c" library.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef BRICK_H
#define BRICK_H

#ifdef  BRICK_IMPLEMENT
#define BRICK_VAR( decl ) \
	decl
#define BRICK_VAR_INIT( decl, ... ) \
	decl = __VA_ARGS__

#define BRICK_INL

#else  /* BRICK_IMPLEMENT */
#define BRICK_VAR( decl ) \
	extern decl
#define BRICK_VAR_INIT( decl, ... ) \
	extern decl

#if __GNUC__ && !__GNUC_STDC_INLINE__
#define BRICK_INL \
	extern inline
#else
#define BRICK_INL \
	inline
#endif

#endif /* BRICK_IMPLEMENT */

#include <stdint.h>
#include <stdbool.h>
#include "ev3.h"
#include "ev3_port.h"
#include "ev3_sensor.h"
#include "ev3_tacho.h"
#include "ev3_dc.h"

/**
 *  \defgroup brick "brick" library
 *  \brief Simplified interface of "ev3dev-c" library.
 *
 *  "brick" library allows simultaneous setting of identical attributes of multiple
 *  devices using a ports mask, e.g. `tacho_run_forever(OUTA | OUTB)`,
 *  but extended ports are not supported.
 *  \{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \brief Type of a pool of input or output sockets.
 */
typedef uint8_t POOL_T;

/**
 *  \brief Identifiers of sockets.
 */
enum {
	SOCKET__NONE_ = 0,

	IN1 = 0x1L,
	IN2 = 0x2L,
	IN3 = 0x4L,
	IN4 = 0x8L,
	OUTA = 0x10L,
	OUTB = 0x20L,
	OUTC = 0x40L,
	OUTD = 0x80L,

};

/**
 *  \brief Get socket of the EV3 port.
 *  \param port EV3 port.
 *  \return Socket.
 */
extern POOL_T port_to_socket( uint8_t port );

/**
 *  \brief Get EV3 port of the socket.
 *  \param sock Socket.
 *  \return EV3 port.
 */
extern uint8_t socket_to_port( POOL_T sock );

/**
 *  \brief Initialize the EV3 brick.
 *  \return false - the brick is NOT found or an error has occurred;
 *  true - the brick is OK.
 */
extern bool brick_init( void );

/**
 *  \brief Uninitialize the EV3 brick.
 */
extern void brick_uninit( void );

/**
 *  \brief Read state of the EV3 brick's keys.
 *  \return State.
 */
extern uint8_t brick_keys( void );

/**
 *  \brief Get value of "address" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_address( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "bin_data" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern byte *sensor_get_bin_data( POOL_T sock, byte *buf, size_t sz );

/**
 *  \brief Set value of "bin_data" attribute of sensors.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
 *  \param sz Size of attribute value.
 *  \return Flag - success operation.
 */
extern bool sensor_set_bin_data( POOL_T pool, byte *value, size_t sz );

/**
 *  \brief Get value of "bin_data_format" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_bin_data_format( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Set value of "command" attribute of sensors.
 *  \param pool Pool of sockets.
 *  \param command_inx Index of the sensor command.
 *  \return Flag - success operation.
 */
extern bool sensor_set_command( POOL_T pool, INX_T command_inx );

/**
 *  \brief Get value of "commands" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_commands( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "direct" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_direct( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Set value of "direct" attribute of sensors.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool sensor_set_direct( POOL_T pool, char *value );

/**
 *  \brief Get value of "decimals" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern dword sensor_get_decimals( POOL_T sock, dword defval );

/**
 *  \brief Get value of "driver_name" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_driver_name( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "fw_version" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_fw_version( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value (index) of "mode" attribute of the sensor.
 *  \param sock Socket.
 *  \return Requested value.
 */
extern INX_T sensor_get_mode( POOL_T sock );

/**
 *  \brief Set value of "mode" attribute of sensors.
 *  \param pool Pool of sockets.
 *  \param mode_inx Index of the sensor mode.
 *  \return Flag - success operation.
 */
extern bool sensor_set_mode( POOL_T pool, INX_T mode_inx );

/**
 *  \brief Get value of "modes" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_modes( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "num_values" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern dword sensor_get_num_values( POOL_T sock, dword defval );

/**
 *  \brief Get value of "poll_ms" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern dword sensor_get_poll_ms( POOL_T sock, dword defval );

/**
 *  \brief Set value of "poll_ms" attribute of sensors.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool sensor_set_poll_ms( POOL_T pool, dword value );

/**
 *  \brief Get value of "units" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_units( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "value0" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern float sensor_get_value0( POOL_T sock, float defval );

/**
 *  \brief Get value of "value1" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern float sensor_get_value1( POOL_T sock, float defval );

/**
 *  \brief Get value of "value2" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern float sensor_get_value2( POOL_T sock, float defval );

/**
 *  \brief Get value of "value3" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern float sensor_get_value3( POOL_T sock, float defval );

/**
 *  \brief Get value of "value4" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern float sensor_get_value4( POOL_T sock, float defval );

/**
 *  \brief Get value of "value5" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern float sensor_get_value5( POOL_T sock, float defval );

/**
 *  \brief Get value of "value6" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern float sensor_get_value6( POOL_T sock, float defval );

/**
 *  \brief Get value of "value7" attribute of the sensor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern float sensor_get_value7( POOL_T sock, float defval );

/**
 *  \brief Get value of "text_value" attribute of the sensor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *sensor_get_text_value( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "value" attribute of the sensor.
 *  \param inx Attribute index.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern int sensor_get_value( uint8_t inx, POOL_T sock, int defval );

/**
 *  \brief Set "US_DIST_CM" mode for lego_ev3_us sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool us_set_mode_us_dist_cm( POOL_T pool );

/**
 *  \brief Set "US_DIST_IN" mode for lego_ev3_us sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool us_set_mode_us_dist_in( POOL_T pool );

/**
 *  \brief Set "US_LISTEN" mode for lego_ev3_us sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool us_set_mode_us_listen( POOL_T pool );

/**
 *  \brief Set "US_SI_CM" mode for lego_ev3_us sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool us_set_mode_us_si_cm( POOL_T pool );

/**
 *  \brief Set "US_SI_IN" mode for lego_ev3_us sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool us_set_mode_us_si_in( POOL_T pool );

/**
 *  \brief Set "US_DC_CM" mode for lego_ev3_us sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool us_set_mode_us_dc_cm( POOL_T pool );

/**
 *  \brief Set "US_DC_IN" mode for lego_ev3_us sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool us_set_mode_us_dc_in( POOL_T pool );
					
/**
 *  \brief Set "GYRO_ANG" mode for lego_ev3_gyro sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool gyro_set_mode_gyro_ang( POOL_T pool );

/**
 *  \brief Set "GYRO_RATE" mode for lego_ev3_gyro sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool gyro_set_mode_gyro_rate( POOL_T pool );

/**
 *  \brief Set "GYRO_FAS" mode for lego_ev3_gyro sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool gyro_set_mode_gyro_fas( POOL_T pool );

/**
 *  \brief Set "GYRO_G_AND_A" mode for lego_ev3_gyro sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool gyro_set_mode_gyro_g_and_a( POOL_T pool );

/**
 *  \brief Set "GYRO_CAL" mode for lego_ev3_gyro sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool gyro_set_mode_gyro_cal( POOL_T pool );
					
/**
 *  \brief Set "COL_REFLECT" mode for lego_ev3_color sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool color_set_mode_col_reflect( POOL_T pool );

/**
 *  \brief Set "COL_AMBIENT" mode for lego_ev3_color sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool color_set_mode_col_ambient( POOL_T pool );

/**
 *  \brief Set "COL_COLOR" mode for lego_ev3_color sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool color_set_mode_col_color( POOL_T pool );

/**
 *  \brief Set "REF_RAW" mode for lego_ev3_color sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool color_set_mode_ref_raw( POOL_T pool );

/**
 *  \brief Set "RGB_RAW" mode for lego_ev3_color sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool color_set_mode_rgb_raw( POOL_T pool );

/**
 *  \brief Set "COL_CAL" mode for lego_ev3_color sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool color_set_mode_col_cal( POOL_T pool );
					
/**
 *  \brief Set "TOUCH" mode for lego_ev3_touch sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool touch_set_mode_touch( POOL_T pool );
					
/**
 *  \brief Set "IR_PROX" mode for lego_ev3_ir sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool ir_set_mode_ir_prox( POOL_T pool );

/**
 *  \brief Set "IR_SEEK" mode for lego_ev3_ir sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool ir_set_mode_ir_seek( POOL_T pool );

/**
 *  \brief Set "IR_REMOTE" mode for lego_ev3_ir sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool ir_set_mode_ir_remote( POOL_T pool );

/**
 *  \brief Set "IR_REM_A" mode for lego_ev3_ir sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool ir_set_mode_ir_rem_a( POOL_T pool );

/**
 *  \brief Set "IR_S_ALT" mode for lego_ev3_ir sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool ir_set_mode_ir_s_alt( POOL_T pool );

/**
 *  \brief Set "IR_CAL" mode for lego_ev3_ir sensors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool ir_set_mode_ir_cal( POOL_T pool );
																																									
/**
 *  \brief Search of the specified sensor type.
 *  \param type_inx Sensor type.
 *  \return Pool of sockets to which specified sensors are plugged.
 */
extern POOL_T sensor_search( INX_T type_inx );

/**
 *  \brief Check that sensors of the specified type are plugged into specified sockets.
 *  \param pool Pool of sockets.
 *  \param type_inx Sensor type, if this parameter is `sensor)_TYPE__NONE_` the type does not matter.
 *  \return Flag - sensors are found.
 */
extern bool sensor_is_plugged( POOL_T pool, INX_T type_inx );

/**
 *  \brief Get value of "address" attribute of the tacho.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *tacho_get_address( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Set value of "command" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param command_inx Index of the tacho command.
 *  \return Flag - success operation.
 */
extern bool tacho_set_command( POOL_T pool, INX_T command_inx );

/**
 *  \brief Get value of "commands" attribute of the tacho.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *tacho_get_commands( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "count_per_rot" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_count_per_rot( POOL_T sock, int defval );

/**
 *  \brief Get value of "count_per_m" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_count_per_m( POOL_T sock, int defval );

/**
 *  \brief Get value of "full_travel_count" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_full_travel_count( POOL_T sock, int defval );

/**
 *  \brief Get value of "driver_name" attribute of the tacho.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *tacho_get_driver_name( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "duty_cycle" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_duty_cycle( POOL_T sock, int defval );

/**
 *  \brief Get value of "duty_cycle_sp" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_duty_cycle_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "duty_cycle_sp" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_duty_cycle_sp( POOL_T pool, int value );

/**
 *  \brief Get value of "hold_pid/Kd" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_hold_pid_Kd( POOL_T sock, int defval );

/**
 *  \brief Set value of "hold_pid/Kd" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_hold_pid_Kd( POOL_T pool, int value );

/**
 *  \brief Get value of "hold_pid/Ki" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_hold_pid_Ki( POOL_T sock, int defval );

/**
 *  \brief Set value of "hold_pid/Ki" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_hold_pid_Ki( POOL_T pool, int value );

/**
 *  \brief Get value of "hold_pid/Kp" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_hold_pid_Kp( POOL_T sock, int defval );

/**
 *  \brief Set value of "hold_pid/Kp" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_hold_pid_Kp( POOL_T pool, int value );

/**
 *  \brief Get value of "max_speed" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_max_speed( POOL_T sock, int defval );

/**
 *  \brief Get value (index) of "polarity" attribute of the tacho.
 *  \param sock Socket.
 *  \return Requested value.
 */
extern INX_T tacho_get_polarity( POOL_T sock );

/**
 *  \brief Set value of "polarity" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param polarity_inx Index of the tacho polarity.
 *  \return Flag - success operation.
 */
extern bool tacho_set_polarity( POOL_T pool, INX_T polarity_inx );

/**
 *  \brief Get value of "position" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_position( POOL_T sock, int defval );

/**
 *  \brief Set value of "position" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_position( POOL_T pool, int value );

/**
 *  \brief Get value of "position_sp" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_position_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "position_sp" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_position_sp( POOL_T pool, int value );

/**
 *  \brief Get value of "ramp_down_sp" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_ramp_down_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "ramp_down_sp" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_ramp_down_sp( POOL_T pool, int value );

/**
 *  \brief Get value of "ramp_up_sp" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_ramp_up_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "ramp_up_sp" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_ramp_up_sp( POOL_T pool, int value );

/**
 *  \brief Get value of "speed" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_speed( POOL_T sock, int defval );

/**
 *  \brief Get value of "speed_pid/Kd" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_speed_pid_Kd( POOL_T sock, int defval );

/**
 *  \brief Set value of "speed_pid/Kd" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_speed_pid_Kd( POOL_T pool, int value );

/**
 *  \brief Get value of "speed_pid/Ki" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_speed_pid_Ki( POOL_T sock, int defval );

/**
 *  \brief Set value of "speed_pid/Ki" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_speed_pid_Ki( POOL_T pool, int value );

/**
 *  \brief Get value of "speed_pid/Kp" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_speed_pid_Kp( POOL_T sock, int defval );

/**
 *  \brief Set value of "speed_pid/Kp" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_speed_pid_Kp( POOL_T pool, int value );

/**
 *  \brief Get value of "speed_sp" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_speed_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "speed_sp" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_speed_sp( POOL_T pool, int value );

/**
 *  \brief Get value (flags) of "state" attribute of the tacho.
 *  \param sock Socket.
 *  \return Requested value.
 */
extern FLAGS_T tacho_get_state( POOL_T sock );

/**
 *  \brief Get value (index) of "stop_action" attribute of the tacho.
 *  \param sock Socket.
 *  \return Requested value.
 */
extern INX_T tacho_get_stop_action( POOL_T sock );

/**
 *  \brief Set value of "stop_action" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param stop_action_inx Index of the tacho stop_action.
 *  \return Flag - success operation.
 */
extern bool tacho_set_stop_action( POOL_T pool, INX_T stop_action_inx );

/**
 *  \brief Get value of "stop_actions" attribute of the tacho.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *tacho_get_stop_actions( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "time_sp" attribute of the tacho.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int tacho_get_time_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "time_sp" attribute of tachos.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool tacho_set_time_sp( POOL_T pool, int value );

/**
 *  \brief Set "run_forever" command for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_run_forever( POOL_T pool );

/**
 *  \brief Set "run_to_abs_pos" command for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_run_to_abs_pos( POOL_T pool );

/**
 *  \brief Set "run_to_rel_pos" command for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_run_to_rel_pos( POOL_T pool );

/**
 *  \brief Set "run_timed" command for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_run_timed( POOL_T pool );

/**
 *  \brief Set "run_direct" command for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_run_direct( POOL_T pool );

/**
 *  \brief Set "stop" command for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_stop( POOL_T pool );

/**
 *  \brief Set "reset" command for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_reset( POOL_T pool );
	
/**
 *  \brief Set "normal" polarity for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_set_polarity_normal( POOL_T pool );

/**
 *  \brief Set "inversed" polarity for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_set_polarity_inversed( POOL_T pool );
	
/**
 *  \brief Set "coast" stop_action for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_set_stop_action_coast( POOL_T pool );

/**
 *  \brief Set "brake" stop_action for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_set_stop_action_brake( POOL_T pool );

/**
 *  \brief Set "hold" stop_action for tachos.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool tacho_set_stop_action_hold( POOL_T pool );

/**
 *  \brief Search of the specified tacho type.
 *  \param type_inx Tacho type.
 *  \return Pool of sockets to which specified tachos are plugged.
 */
extern POOL_T tacho_search( INX_T type_inx );

/**
 *  \brief Check that tachos of the specified type are plugged into specified sockets.
 *  \param pool Pool of sockets.
 *  \param type_inx Tacho type, if this parameter is `tacho)_TYPE__NONE_` the type does not matter.
 *  \return Flag - tachos are found.
 */
extern bool tacho_is_plugged( POOL_T pool, INX_T type_inx );

/**
 *  \brief Check that tachos are running.
 *  \param pool Pool of sockets.
 *  \return Flag - at least one tacho is running.
 */
extern bool tacho_is_running( POOL_T pool );

/**
 *  \brief Get value of "address" attribute of the DC motor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *dc_get_address( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Set value of "command" attribute of DC motors.
 *  \param pool Pool of sockets.
 *  \param command_inx Index of the DC motor command.
 *  \return Flag - success operation.
 */
extern bool dc_set_command( POOL_T pool, INX_T command_inx );

/**
 *  \brief Get value of "commands" attribute of the DC motor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *dc_get_commands( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "driver_name" attribute of the DC motor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *dc_get_driver_name( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "duty_cycle" attribute of the DC motor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int dc_get_duty_cycle( POOL_T sock, int defval );

/**
 *  \brief Get value of "duty_cycle_sp" attribute of the DC motor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int dc_get_duty_cycle_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "duty_cycle_sp" attribute of DC motors.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool dc_set_duty_cycle_sp( POOL_T pool, int value );

/**
 *  \brief Get value (index) of "polarity" attribute of the DC motor.
 *  \param sock Socket.
 *  \return Requested value.
 */
extern INX_T dc_get_polarity( POOL_T sock );

/**
 *  \brief Set value of "polarity" attribute of DC motors.
 *  \param pool Pool of sockets.
 *  \param polarity_inx Index of the DC motor polarity.
 *  \return Flag - success operation.
 */
extern bool dc_set_polarity( POOL_T pool, INX_T polarity_inx );

/**
 *  \brief Get value (flags) of "state" attribute of the DC motor.
 *  \param sock Socket.
 *  \return Requested value.
 */
extern FLAGS_T dc_get_state( POOL_T sock );

/**
 *  \brief Set value of "stop_action" attribute of DC motors.
 *  \param pool Pool of sockets.
 *  \param stop_action_inx Index of the DC motor stop_action.
 *  \return Flag - success operation.
 */
extern bool dc_set_stop_action( POOL_T pool, INX_T stop_action_inx );

/**
 *  \brief Get value of "stop_actions" attribute of the DC motor.
 *  \param sock Socket.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Requested value.
 */
extern char *dc_get_stop_actions( POOL_T sock, char *buf, size_t sz );

/**
 *  \brief Get value of "ramp_down_sp" attribute of the DC motor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int dc_get_ramp_down_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "ramp_down_sp" attribute of DC motors.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool dc_set_ramp_down_sp( POOL_T pool, int value );

/**
 *  \brief Get value of "ramp_up_sp" attribute of the DC motor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int dc_get_ramp_up_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "ramp_up_sp" attribute of DC motors.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool dc_set_ramp_up_sp( POOL_T pool, int value );

/**
 *  \brief Get value of "time_sp" attribute of the DC motor.
 *  \param sock Socket.
 *  \param defval Default value.
 *  \return Requested value.
 */
extern int dc_get_time_sp( POOL_T sock, int defval );

/**
 *  \brief Set value of "time_sp" attribute of DC motors.
 *  \param pool Pool of sockets.
 *  \param value Attribute value.
			 
 *  \return Flag - success operation.
 */
extern bool dc_set_time_sp( POOL_T pool, int value );

/**
 *  \brief Set "run_forever" command for DC motors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool dc_run_forever( POOL_T pool );

/**
 *  \brief Set "run_timed" command for DC motors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool dc_run_timed( POOL_T pool );

/**
 *  \brief Set "run_direct" command for DC motors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool dc_run_direct( POOL_T pool );

/**
 *  \brief Set "stop" command for DC motors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool dc_stop( POOL_T pool );
	
/**
 *  \brief Set "normal" polarity for DC motors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool dc_set_polarity_normal( POOL_T pool );

/**
 *  \brief Set "inversed" polarity for DC motors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool dc_set_polarity_inversed( POOL_T pool );
	
/**
 *  \brief Set "coast" stop_action for DC motors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool dc_set_stop_action_coast( POOL_T pool );

/**
 *  \brief Set "brake" stop_action for DC motors.
 *  \param pool Pool of sockets.
 *  \return Flag - success operation.
 */
extern bool dc_set_stop_action_brake( POOL_T pool );

/**
 *  \brief Search of the specified DC motor type.
 *  \param type_inx DC motor type.
 *  \return Pool of sockets to which specified DC motors are plugged.
 */
extern POOL_T dc_search( INX_T type_inx );

/**
 *  \brief Check that DC motors of the specified type are plugged into specified sockets.
 *  \param pool Pool of sockets.
 *  \param type_inx DC motor type, if this parameter is `dc)_TYPE__NONE_` the type does not matter.
 *  \return Flag - DC motors are found.
 */
extern bool dc_is_plugged( POOL_T pool, INX_T type_inx );

/**
 *  \brief Check that DC motors are running.
 *  \param pool Pool of sockets.
 *  \return Flag - at least one DC motor is running.
 */
extern bool dc_is_running( POOL_T pool );

/**
 *  \brief Delay in milliseconds.
 *  \param ms Value.
 */
extern void sleep_ms( uint32_t ms );

#ifdef __cplusplus
}
#endif

/** \} */

#undef BRICK_VAR
#undef BRICK_VAR_INIT
#undef BRICK_INL
#endif

