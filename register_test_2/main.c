
/*
 * Copyright (c) 2024 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary to Analog Devices, Inc. and its licensors.
 * Released under the terms of the "LICENSE.md" file in the root directory.
 */

#include <stdint.h>

// Function prototypes
uint32_t read_32(uint32_t address);

void write_32(uint32_t address, uint32_t value);

extern int hci_le_tx_test_v1_cmd_handler_direct(uint8_t tx_channel, uint8_t test_data_len, uint8_t pkt_payl);

void main() {
    uint32_t ret = 0;
 
    uint32_t addr = 0x000BFFE4;
    uint32_t val = 0;
 
    write_32(addr, val);
 
    while(val < 0xFFFFFFFF){
      write_32(addr, val);
      val++;
    }
 
    while(1) {}
    // Should never reach here
}

void write_32(uint32_t address, uint32_t value) 
{
    *(volatile uint32_t *)address = value;
}
