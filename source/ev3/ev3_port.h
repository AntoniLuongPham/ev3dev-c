
/*  ev3_port.h was generated by yup.py (yupp) 1.0c2
    out of ev3_port.yu-h 
 *//**
 *  \file  ev3_port.h (ev3_port.yu-h)
 *  \brief  EV3 Ports.
 *  \author  Vitaly Kravtsov (in4lio@gmail.com)
 *  \copyright  See the LICENSE file.
 */

#ifndef EV3_PORT_H
#define EV3_PORT_H

#ifdef  EV3_PORT_IMPLEMENT
#define EV3_PORT_VAR( decl ) \
	decl
#define EV3_PORT_VAR_INIT( decl, ... ) \
	decl = __VA_ARGS__

#define EV3_PORT_INL

#else  /* EV3_PORT_IMPLEMENT */
#define EV3_PORT_VAR( decl ) \
	extern decl
#define EV3_PORT_VAR_INIT( decl, ... ) \
	extern decl

#if __GNUC__ && !__GNUC_STDC_INLINE__
#define EV3_PORT_INL \
	extern inline
#else
#define EV3_PORT_INL \
	inline
#endif

#endif /* EV3_PORT_IMPLEMENT */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 *  \defgroup ev3_port EV3 ports and extended ports
 *  \brief Access to EV3 ports and extended ports.
 *  \see http://www.ev3dev.org/docs/ports/
 *  \see http://www.ev3dev.org/docs/drivers/lego-port-class/
 *  \{
 */

#ifdef __cplusplus
extern "C" {
#endif

#define PORT_DIR  "/sys/class/lego-port"  /**< Directory of EV3 ports. */

/**
 *  \brief Structure of a EV3 port descriptor.
 */
typedef struct {
	INX_T type_inx;  /**< EV3 port type. */
	uint8_t port;  /**< EV3 port EV3 port. */
	uint8_t extport;  /**< EV3 port extended port. */
	uint8_t addr;  /**< EV3 port I2C address. */

} EV3_PORT;

#define PORT_DESC__LIMIT_  DESC_LIMIT  /**< Limit of EV3 port descriptors. */

#define PORT__NONE_  PORT_DESC__LIMIT_  /**< EV3 port is not found. */

/**
 *  \brief Vector of EV3 port descriptors (filled by \ref ev3_port_init).
 */
EV3_PORT_VAR( EV3_PORT ev3_port[ PORT_DESC__LIMIT_ ] );;

/**
 *  \brief Identifiers of EV3 port types.
 */
enum {
	PORT_TYPE__NONE_ = 0,  /* XXX: memset( 0 ) is used */

	HT_NXT_SMUX_PORT,
	LEGOEV3_INPUT_PORT,
	LEGOEV3_OUTPUT_PORT,
	MS_EV3_SMUX_PORT,
	MS_NXTMMX_OUT_PORT,
	WEDO_PORT,

	PORT_TYPE__COUNT_,  /**< Count of EV3 port types. */
	PORT_TYPE__UNKNOWN_ = PORT_TYPE__COUNT_
};

/**
 *  \brief Identifiers of EV3 port "mode" attribute.
 */
enum {
	PORT_MODE__NONE_ = 0,

	HT_NXT_SMUX_PORT_ANALOG, HT_NXT_SMUX_ANALOG = HT_NXT_SMUX_PORT_ANALOG,
	HT_NXT_SMUX_PORT_I2C, HT_NXT_SMUX_I2C = HT_NXT_SMUX_PORT_I2C,			
	LEGOEV3_INPUT_PORT_AUTO, INPUT_AUTO = LEGOEV3_INPUT_PORT_AUTO,
	LEGOEV3_INPUT_PORT_NXT_ANALOG, INPUT_NXT_ANALOG = LEGOEV3_INPUT_PORT_NXT_ANALOG,
	LEGOEV3_INPUT_PORT_NXT_COLOR, INPUT_NXT_COLOR = LEGOEV3_INPUT_PORT_NXT_COLOR,
	LEGOEV3_INPUT_PORT_NXT_I2C, INPUT_NXT_I2C = LEGOEV3_INPUT_PORT_NXT_I2C,
	LEGOEV3_INPUT_PORT_OTHER_I2C, INPUT_OTHER_I2C = LEGOEV3_INPUT_PORT_OTHER_I2C,
	LEGOEV3_INPUT_PORT_EV3_ANALOG, INPUT_EV3_ANALOG = LEGOEV3_INPUT_PORT_EV3_ANALOG,
	LEGOEV3_INPUT_PORT_EV3_UART, INPUT_EV3_UART = LEGOEV3_INPUT_PORT_EV3_UART,
	LEGOEV3_INPUT_PORT_OTHER_UART, INPUT_OTHER_UART = LEGOEV3_INPUT_PORT_OTHER_UART,
	LEGOEV3_INPUT_PORT_RAW, INPUT_RAW = LEGOEV3_INPUT_PORT_RAW,			
	LEGOEV3_OUTPUT_PORT_AUTO, OUTPUT_AUTO = LEGOEV3_OUTPUT_PORT_AUTO,
	LEGOEV3_OUTPUT_PORT_TACHO_MOTOR, OUTPUT_TACHO_MOTOR = LEGOEV3_OUTPUT_PORT_TACHO_MOTOR,
	LEGOEV3_OUTPUT_PORT_DC_MOTOR, OUTPUT_DC_MOTOR = LEGOEV3_OUTPUT_PORT_DC_MOTOR,
	LEGOEV3_OUTPUT_PORT_LED, OUTPUT_LED = LEGOEV3_OUTPUT_PORT_LED,
	LEGOEV3_OUTPUT_PORT_RAW, OUTPUT_RAW = LEGOEV3_OUTPUT_PORT_RAW,			
	MS_EV3_SMUX_PORT_UART, MS_EV3_SMUX_UART = MS_EV3_SMUX_PORT_UART,
	MS_EV3_SMUX_PORT_ANALOG, MS_EV3_SMUX_ANALOG = MS_EV3_SMUX_PORT_ANALOG,			
	MS_NXTMMX_OUT_PORT_TACHO_MOTOR, MS_NXTMMX_TACHO_MOTOR = MS_NXTMMX_OUT_PORT_TACHO_MOTOR,			
	WEDO_PORT_AUTO, WEDO_AUTO = WEDO_PORT_AUTO,
	PORT_MODE__COUNT_,  /**< Count of EV3 port "mode" attribute. */
	PORT_MODE__UNKNOWN_ = PORT_MODE__COUNT_
};

/**
 *  \brief Read "address" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
extern size_t get_port_address( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Read "driver_name" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
extern size_t get_port_driver_name( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Read "mode" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
extern size_t get_port_mode( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Write "mode" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
extern size_t set_port_mode( uint8_t sn, char *value );

/**
 *  \brief Write "mode" attribute of several EV3 ports.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
extern size_t multi_set_port_mode( uint8_t *sn, char *value );

/**
 *  \brief Read "modes" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
extern size_t get_port_modes( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Write "set_device" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
extern size_t set_port_set_device( uint8_t sn, char *value );

/**
 *  \brief Write "set_device" attribute of several EV3 ports.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param value Attribute value.
		 
 *  \return Count of written bytes.
 */
extern size_t multi_set_port_set_device( uint8_t *sn, char *value );

/**
 *  \brief Read "status" attribute of the EV3 port.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \param sz Buffer size.
 *  \return Count of read bytes.
 */
extern size_t get_port_status( uint8_t sn, char *buf, size_t sz );

/**
 *  \brief Get name of the specified EV3 port type.
 *  \param type_inx Index of the EV3 port type.
 *  \return Requested value.
 */
extern const char *ev3_port_type( INX_T type_inx );

/**
 *  \brief Read "driver_name" attribute and get index of the EV3 port type.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
extern INX_T get_port_type_inx( uint8_t sn );

/**
 *  \brief Read EV3 port attributes that are required for filling the descriptor.
 *  \param sn Sequence number.
 *  \param desc Buffer for the descriptor.
 *  \return Count of read bytes.
 */
extern size_t get_port_desc( uint8_t sn, EV3_PORT *desc );

/**
 *  \brief Get descriptor of the EV3 port.
 *  \param sn Sequence number.
 *  \return Pointer to the EV3 port descriptor.
 */
extern EV3_PORT *ev3_port_desc( uint8_t sn );

/**
 *  \brief Get type from the EV3 port descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
extern INX_T ev3_port_desc_type_inx( uint8_t sn );

/**
 *  \brief Get EV3 port from the EV3 port descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
extern uint8_t ev3_port_desc_port( uint8_t sn );

/**
 *  \brief Get extended port from the EV3 port descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
extern uint8_t ev3_port_desc_extport( uint8_t sn );

/**
 *  \brief Get I2C address from the EV3 port descriptor.
 *  \param sn Sequence number.
 *  \return Requested value.
 */
extern uint8_t ev3_port_desc_addr( uint8_t sn );

/**
 *  \brief Assemble EV3 port name from the EV3 port descriptor.
 *  \param sn Sequence number.
 *  \param[out] buf Buffer for result.
 *  \return Requested value.
 */
extern char *ev3_port_port_name( uint8_t sn, char *buf );

/**
 *  \brief Search of a sequence number of the specified EV3 port type.
 *  \param type_inx EV3 port type.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the EV3 port is found.
 */
extern bool ev3_search_port_type( INX_T type_inx, uint8_t *sn, uint8_t from );

/**
 *  \brief Search of a sequence number the EV3 port by plug-in attributes.
 *  \param port EV3 port.
 *  \param extport Extended port.
 *  \param[out] sn Buffer for the sequence number.
 *  \param from Search initial value.
 *  \return Flag - the EV3 port is found.
 */
extern bool ev3_search_port_plugged_in( uint8_t port, uint8_t extport, uint8_t *sn, uint8_t from );

/**
 *  \brief Get name of the specified EV3 port mode.
 *  \param mode_inx Index of the EV3 port mode.
 *  \return Requested value.
 */
extern const char *ev3_port_mode( INX_T mode_inx );

/**
 *  \brief Read "mode" attribute of the specified EV3 port type and get the index.
 *  \param sn Sequence number.
 *  \param type_inx Index of the EV3 port type.
 *  \return Requested value.
 */
extern INX_T get_port_mode_inx_of_type( uint8_t sn, INX_T type_inx );

/**
 *  \brief Read "mode" attribute of the EV3 port and get the index.
 *  \param sn Sequence number.
 *  \return Requested value.
 *
 *  This function gets type of the EV3 port from the descriptor.
 */
extern INX_T get_port_mode_inx( uint8_t sn );

/**
 *  \brief Write "mode" attribute of the EV3 port by the index.
 *  \param sn Sequence number.
 *  \param mode_inx Index of the EV3 port mode.
 *  \return Count of written bytes.
 */
extern size_t set_port_mode_inx( uint8_t sn, INX_T mode_inx );

/**
 *  \brief Write "mode" attribute of several EV3 ports by the index.
 *  \param sn Vector of sequence numbers ending with DESC_LIMIT.
 *  \param mode_inx Index of the EV3 port mode.
 *  \return Count of written bytes.
 */
extern size_t multi_set_port_mode_inx( uint8_t *sn, INX_T mode_inx );

/**
 *  \brief Detect connected EV3 ports.
 *  \return Number of found EV3 ports or -1 in case of an error.
 */
extern int ev3_port_init( void );

/**
 *  \brief Identifiers of EV3 ports and extended ports.
 */
#define EV3_PORT__NONE_  0  /* XXX: 0 is used */
#define EXT_PORT__NONE_  EV3_PORT__NONE_

#define INPUT_1  49  // '1'
#define INPUT_2  50  // '2'
#define INPUT_3  51  // '3'
#define INPUT_4  52  // '4'
			
#define OUTPUT_A  65  // 'A'
#define OUTPUT_B  66  // 'B'
#define OUTPUT_C  67  // 'C'
#define OUTPUT_D  68  // 'D'
				
#define MUX_1  49  // '1'
#define MUX_2  50  // '2'
#define MUX_3  51  // '3'
#define MUX_4  52  // '4'
#define SERVO__OFFSET_  16
#define SERVO_1  65  // 'A'
#define SERVO_2  66  // 'B'
#define SERVO_3  67  // 'C'
#define SERVO_4  68  // 'D'
#define SERVO_5  69  // 'E'
#define SERVO_6  70  // 'F'
#define SERVO_7  71  // 'G'
#define SERVO_8  72  // 'H'
#define NXTMMX__OFFSET_  28
#define NXTMMX_1  77  // 'M'
#define NXTMMX_2  78  // 'N'
#define WEDO__OFFSET_  48
#define WEDO_1  97  // 'a'
#define WEDO_2  98  // 'b'
#define WEDO_3  99  // 'c'
#define WEDO_4  100  // 'd'

/**
 *  \brief Search of a port sequence number by the EV3 port and the extended port.
 *  \param port EV3 port index.
 *  \param extport Extended port index.
 *  \return Port sequence number.
 */
extern uint8_t ev3_search_port( uint8_t port, uint8_t extport );

/**
 *  \brief Parse name of the EV3 port.
 *  \param name Port name.
 *  \param port Buffer for the EV3 port index.
 *  \param extport Buffer for the extended port index.
 *  \param addr Buffer for the address.
 */
extern void ev3_parse_port_name( char *name, uint8_t *port, uint8_t *extport, uint8_t *addr );

/**
 *  \brief Assemble name of the EV3 port.
 *  \param port EV3 port index.
 *  \param extport Extended port index.
 *  \param addr Address.
 *  \param[out] buf Buffer for result.
 *  \return Requested value.
 */
extern char *ev3_port_name( uint8_t port, uint8_t extport, uint8_t addr, char *buf );

#ifdef __cplusplus
}
#endif

/** \} */

#undef EV3_PORT_VAR
#undef EV3_PORT_VAR_INIT
#undef EV3_PORT_INL
#endif

