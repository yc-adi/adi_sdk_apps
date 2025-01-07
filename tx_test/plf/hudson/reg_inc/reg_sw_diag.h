#ifndef _REG_SW_DIAG_H_
#define _REG_SW_DIAG_H_

#include <stdint.h>
#include "_reg_sw_diag.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_SW_DIAG_COUNT 1

#define REG_SW_DIAG_DECODING_MASK 0x00000000

/**
 * @brief DIAG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:24                 BANK   0x0
 *  23:16               OFFSET   0x0
 *  15:08                 MASK   0x0
 *  07:00                VALUE   0x0
 * </pre>
 */
#define SW_DIAG_DIAG_ADDR   0x1000D200
#define SW_DIAG_DIAG_OFFSET 0x00000000
#define SW_DIAG_DIAG_INDEX  0x00000000
#define SW_DIAG_DIAG_RESET  0x00000000

__INLINE uint32_t sw_diag_diag_get(void)
{
    return REG_PL_RD(SW_DIAG_DIAG_ADDR);
}

__INLINE void sw_diag_diag_set(uint32_t value)
{
    REG_PL_WR(SW_DIAG_DIAG_ADDR, value);
}

// field definitions
#define SW_DIAG_BANK_MASK     ((uint32_t)0xFF000000)
#define SW_DIAG_BANK_LSB      24
#define SW_DIAG_BANK_WIDTH    ((uint32_t)0x00000008)
#define SW_DIAG_OFFSET_MASK   ((uint32_t)0x00FF0000)
#define SW_DIAG_OFFSET_LSB    16
#define SW_DIAG_OFFSET_WIDTH  ((uint32_t)0x00000008)
#define SW_DIAG_MASK_MASK     ((uint32_t)0x0000FF00)
#define SW_DIAG_MASK_LSB      8
#define SW_DIAG_MASK_WIDTH    ((uint32_t)0x00000008)
#define SW_DIAG_VALUE_MASK    ((uint32_t)0x000000FF)
#define SW_DIAG_VALUE_LSB     0
#define SW_DIAG_VALUE_WIDTH   ((uint32_t)0x00000008)

#define SW_DIAG_BANK_RST      0x0
#define SW_DIAG_OFFSET_RST    0x0
#define SW_DIAG_MASK_RST      0x0
#define SW_DIAG_VALUE_RST     0x0

__INLINE void sw_diag_diag_pack(uint8_t bank, uint8_t offset, uint8_t mask, uint8_t value)
{
    ASSERT_ERR((((uint32_t)bank << 24) & ~((uint32_t)0xFF000000)) == 0);
    ASSERT_ERR((((uint32_t)offset << 16) & ~((uint32_t)0x00FF0000)) == 0);
    ASSERT_ERR((((uint32_t)mask << 8) & ~((uint32_t)0x0000FF00)) == 0);
    ASSERT_ERR((((uint32_t)value << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(SW_DIAG_DIAG_ADDR,  ((uint32_t)bank << 24) | ((uint32_t)offset << 16) | ((uint32_t)mask << 8) | ((uint32_t)value << 0));
}

__INLINE void sw_diag_diag_unpack(uint8_t* bank, uint8_t* offset, uint8_t* mask, uint8_t* value)
{
    uint32_t localVal = REG_PL_RD(SW_DIAG_DIAG_ADDR);

    *bank = (localVal & ((uint32_t)0xFF000000)) >> 24;
    *offset = (localVal & ((uint32_t)0x00FF0000)) >> 16;
    *mask = (localVal & ((uint32_t)0x0000FF00)) >> 8;
    *value = (localVal & ((uint32_t)0x000000FF)) >> 0;
}

__INLINE void sw_diag_bank_setf(uint8_t bank)
{
    ASSERT_ERR((((uint32_t)bank << 24) & ~((uint32_t)0xFF000000)) == 0);
    REG_PL_WR(SW_DIAG_DIAG_ADDR, (REG_PL_RD(SW_DIAG_DIAG_ADDR) & ~((uint32_t)0xFF000000)) | ((uint32_t)bank << 24));
}

__INLINE void sw_diag_offset_setf(uint8_t offset)
{
    ASSERT_ERR((((uint32_t)offset << 16) & ~((uint32_t)0x00FF0000)) == 0);
    REG_PL_WR(SW_DIAG_DIAG_ADDR, (REG_PL_RD(SW_DIAG_DIAG_ADDR) & ~((uint32_t)0x00FF0000)) | ((uint32_t)offset << 16));
}

__INLINE void sw_diag_mask_setf(uint8_t mask)
{
    ASSERT_ERR((((uint32_t)mask << 8) & ~((uint32_t)0x0000FF00)) == 0);
    REG_PL_WR(SW_DIAG_DIAG_ADDR, (REG_PL_RD(SW_DIAG_DIAG_ADDR) & ~((uint32_t)0x0000FF00)) | ((uint32_t)mask << 8));
}

__INLINE void sw_diag_value_setf(uint8_t value)
{
    ASSERT_ERR((((uint32_t)value << 0) & ~((uint32_t)0x000000FF)) == 0);
    REG_PL_WR(SW_DIAG_DIAG_ADDR, (REG_PL_RD(SW_DIAG_DIAG_ADDR) & ~((uint32_t)0x000000FF)) | ((uint32_t)value << 0));
}


#endif // _REG_SW_DIAG_H_

