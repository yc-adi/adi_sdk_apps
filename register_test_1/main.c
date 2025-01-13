
/*
 * Copyright (c) 2024 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary to Analog Devices, Inc. and its licensors.
 * Released under the terms of the "LICENSE.md" file in the root directory.
 */

#include <stdint.h>

void main() {
    *(uint8_t *)0x000BFFE8 = 0x55;
    uint8_t temp = 0;
    temp = *(uint8_t *)0x000BFFE8;

    while(1) {}
    
    // Should never reach here
}

