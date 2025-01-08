
/*
 * Copyright (c) 2024 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary to Analog Devices, Inc. and its licensors.
 * Released under the terms of the "LICENSE.md" file in the root directory.
 */

#include <stdint.h>
#include <stdio.h>

#include "version.h"

// Define base addresses for memory-mapped registers
#define REG_ADDR_1 0x10000000
#define REG_ADDR_2 0x10000004

// Function prototypes
uint8_t read_8(uint32_t address);
uint16_t read_16(uint32_t address);
uint32_t read_32(uint32_t address);

void write_8(uint32_t address, uint8_t value);
void write_16(uint32_t address, uint16_t value);
void write_32(uint32_t address, uint32_t value);

extern int hci_le_tx_test_v1_cmd_handler_direct(uint8_t tx_channel, uint8_t test_data_len, uint8_t pkt_payl);

void main() {
    printf("\n\n\n****************************************\n");
    printf("TX_TEST on FPGA board\n");
    printf("https://jira.analog.com/browse/GRANITESW-200\n");
    printf("https://confluence.analog.com/display/GRANITE/Design+Verification\n\n");

    int ret = 0;

    /*
     * @param[in] tx_channel        0x00 to 0x27, RF channel to transmit on.
     * @param[in] test_data_len     0x00 to 0xFF, Length of each packet in bytes.
     * @param[in] pkt_payl          Packet_Payload, size = 1 octet
     *   0x00    PRBS9 payload.
     *   0x01    Repeated 11110000 payload.
     *   0x02    Repeated 10101010 payload.
     *   0x03    PRBS15 payload.
     *   0x04    Repeated 11111111 payload.
     *   0x05    Repeated 00000000 payload.
     *   0x06    Repeated 00001111 payload.
     *   0x07    Repeated 01010101 payload.
     *   All other values [Reserved for future use].
    */
    uint8_t tx_channel = 1;
    uint8_t test_data_len = 2;
    uint8_t pkt_payl = 7;
    printf("tx_channel = %d, test_data_len = %d, pkt_payl = %d\n", tx_channel, test_data_len, pkt_payl);

    ret = hci_le_tx_test_v1_cmd_handler_direct(tx_channel, test_data_len, pkt_payl);
    printf("ret = %d\n", ret);

    while(1) {}
    
    // Should never reach here
}

// Function implementations
uint8_t read_8(uint32_t address) 
{
    return *(volatile uint8_t *)address;
}

uint16_t read_16(uint32_t address) 
{
    return *(volatile uint16_t *)address;
}

uint32_t read_32(uint32_t address) 
{
    return *(volatile uint32_t *)address;
}

void write_8(uint32_t address, uint8_t value) 
{
    *(volatile uint8_t *)address = value;
}

void write_16(uint32_t address, uint16_t value) 
{
    *(volatile uint16_t *)address = value;
}

void write_32(uint32_t address, uint32_t value) 
{
    *(volatile uint32_t *)address = value;
}
