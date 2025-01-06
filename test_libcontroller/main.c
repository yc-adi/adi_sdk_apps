
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

extern void rw_main(void);

void main() {
    int ret = 0;
    
    rw_main();

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
