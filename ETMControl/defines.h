#ifndef DEFINES_H
#define DEFINES_H

/* UART Packet masks */
#define UART_TYPE                               0b11000000
#define UART_COMMAND                            0b00111111

/* UART Debugging Flag */
#define UART_DEBUG_FLAG                         0xFF

/* UART packet types */
#define UART_TYPE_CONTROL                       0x00    // 0b00000000
#define UART_TYPE_DATA                          0x40    // 0b01000000
#define UART_TYPE_COMMAND                       0x80    // 0b10000000
#define UART_TYPE_ACK                           0xC0    // 0b11000000

/* UART Packet Commands */
//Control Commands
#define UART_COMMAND_NOP                        0x00
#define UART_COMMAND_HALT                       0x3F
#define UART_COMMAND_BURP                       0x3E

//Table Commands
#define UART_COMMAND_CLAMP_EXPERIMENT           0x11
#define UART_COMMAND_RELEASE_EXPERIMENT         0x12
#define UART_COMMAND_MV_TABLE_HAB               0x13
#define UART_COMMAND_MV_TABLE_CEN               0x14
#define UART_COMMAND_MV_TABLE_SPC               0x15

//Door Commands
#define UART_COMMAND_OPEN_HAB                   0x16
#define UART_COMMAND_OPEN_SPC                   0x17
#define UART_COMMAND_CLOSE_HAB                  0x18
#define UART_COMMAND_CLOSE_SPC                  0x19

//Data commands
#define UART_COMMAND_DATA_TABLE_CAP_SENSE       0x20
#define UART_COMMAND_DATA_PLATE_CAP_SENSE       0x21
#define UART_COMMAND_DATA_TABLE_FORCE_SENSE     0x22
#define UART_COMMAND_DATA_HAB_DOOR_HE_SENSE     0x23
#define UART_COMMAND_DATA_SPC_DOOR_HE_SENSE     0x24
#define UART_COMMAND_DATA_HAB_HINGE_HE_SENSE    0x25
#define UART_COMMAND_DATA_SPC_HINGE_HE_SENSE    0x26
#define UART_COMMAND_DATA_TEMPERATURE           0x27

/* Packet byte sizes */
#define UART_COMMAND_PACKET_TYPECMD_SIZE        1
#define UART_COMMAND_PACKET_LENGTH_SIZE         1

/* Pin defines */
//Serial
#define COMMAND_SERIAL_PORT                     0

#endif // DEFINES_H
