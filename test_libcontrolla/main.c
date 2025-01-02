
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

int add(int a, int b);

void main() {
    const PlfVersion_t *version = PlfGetVersion();

    printf("Version: %d.%d.%d %u %s\n", version->major, version->minor, version->patch,
           version->commit, version->buildDate);

    int c = 10;
    int d = 20;
    int res = add(c, d);
    printf("res = %d\n", res);

    uint32_t ver = 0;

    uint32_t addr = (uint32_t)&c;
    uint32_t addr2 = REG_ADDR_2;

    *(uint32_t *)addr = 0x12345678;
    ver = *(uint32_t *)addr;

    // Write values to registers
    write_8(addr, 0x12);
    write_16(addr, 0x1234);
    write_32(addr, 0x12345678);

    // Read back values from registers
    uint8_t val8 = read_8(addr);
    uint16_t val16 = read_16(addr);
    uint32_t val32 = read_32(addr);

    // Print the read values
    printf("Read 8-bit value: 0x%02X\n", val8);
    printf("Read 16-bit value: 0x%04X\n", val16);
    printf("Read 32-bit value: 0x%08X\n", val32);

    // Test with another address
    write_32(addr2, 0x87654321);
    printf("Read from addr2: 0x%08X\n", read_32(addr2));

    while(1) {}
    
    // Should never reach here
}

// Function implementations

int add(int a, int b) 
{
    a += 1;
    b += 2;
    return (a + b);
}

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
