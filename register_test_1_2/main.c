
/*
 * Copyright (c) 2024 Analog Devices, Inc. All Rights Reserved.
 * This software is proprietary to Analog Devices, Inc. and its licensors.
 * Released under the terms of the "LICENSE.md" file in the root directory.
 */

#include <stdint.h>

void main() {
    *(uint32_t *)0x000BFFE8 = 0x55555555;
    uint32_t temp = *(uint32_t *)0x000BFFE8;

    while(1) {}
    
    // Should never reach here
}

