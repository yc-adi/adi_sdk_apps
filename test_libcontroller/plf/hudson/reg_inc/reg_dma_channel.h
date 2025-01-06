#ifndef _REG_DMA_CHANNEL_H_
#define _REG_DMA_CHANNEL_H_

#include <stdint.h>
#include "_reg_dma_channel.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_DMA_CHANNEL_COUNT 8

#define REG_DMA_CHANNEL_DECODING_MASK 0x0000001F

/**
 * @brief SAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                  SAR   0x0
 * </pre>
 */
#define DMA_SAR_ADDR   0x1000B010
#define DMA_SAR_OFFSET 0x00000010
#define DMA_SAR_INDEX  0x00000004
#define DMA_SAR_RESET  0x00000000

__INLINE uint32_t dma_sar_get(int elt_idx)
{
    return REG_PL_RD(DMA_SAR_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE);
}

__INLINE void dma_sar_set(int elt_idx, uint32_t value)
{
    REG_PL_WR(DMA_SAR_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE, value);
}

// field definitions
#define DMA_SAR_MASK   ((uint32_t)0xFFFFFFFF)
#define DMA_SAR_LSB    0
#define DMA_SAR_WIDTH  ((uint32_t)0x00000020)

#define DMA_SAR_RST    0x0

__INLINE uint32_t dma_sar_getf(int elt_idx)
{
    uint32_t localVal = REG_PL_RD(DMA_SAR_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief DAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                  DAR   0x0
 * </pre>
 */
#define DMA_DAR_ADDR   0x1000B014
#define DMA_DAR_OFFSET 0x00000014
#define DMA_DAR_INDEX  0x00000005
#define DMA_DAR_RESET  0x00000000

__INLINE void dma_dar_set(int elt_idx, uint32_t value)
{
    REG_PL_WR(DMA_DAR_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE, value);
}

// field definitions
#define DMA_DAR_MASK   ((uint32_t)0xFFFFFFFF)
#define DMA_DAR_LSB    0
#define DMA_DAR_WIDTH  ((uint32_t)0x00000020)

#define DMA_DAR_RST    0x0

__INLINE void dma_dar_setf(int elt_idx, uint32_t dar)
{
    ASSERT_ERR((((uint32_t)dar << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(DMA_DAR_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE, (uint32_t)dar << 0);
}

/**
 * @brief CCFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31                START   0
 *  12:00                 SIZE   0x0
 * </pre>
 */
#define DMA_CCFG_ADDR   0x1000B018
#define DMA_CCFG_OFFSET 0x00000018
#define DMA_CCFG_INDEX  0x00000006
#define DMA_CCFG_RESET  0x00000000

__INLINE uint32_t dma_ccfg_get(int elt_idx)
{
    return REG_PL_RD(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE);
}

__INLINE void dma_ccfg_set(int elt_idx, uint32_t value)
{
    REG_PL_WR(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE, value);
}

// field definitions
#define DMA_START_BIT    ((uint32_t)0x80000000)
#define DMA_START_POS    31
#define DMA_SIZE_MASK    ((uint32_t)0x00001FFF)
#define DMA_SIZE_LSB     0
#define DMA_SIZE_WIDTH   ((uint32_t)0x0000000D)

#define DMA_START_RST    0x0
#define DMA_SIZE_RST     0x0

__INLINE void dma_ccfg_pack(int elt_idx, uint8_t start, uint16_t size)
{
    ASSERT_ERR((((uint32_t)start << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)size << 0) & ~((uint32_t)0x00001FFF)) == 0);
    REG_PL_WR(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE,  ((uint32_t)start << 31) | ((uint32_t)size << 0));
}

__INLINE void dma_ccfg_unpack(int elt_idx, uint8_t* start, uint16_t* size)
{
    uint32_t localVal = REG_PL_RD(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE);

    *start = (localVal & ((uint32_t)0x80000000)) >> 31;
    *size = (localVal & ((uint32_t)0x00001FFF)) >> 0;
}

__INLINE void dma_ccfg_start_setf(int elt_idx, uint8_t start)
{
    ASSERT_ERR((((uint32_t)start << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE, (REG_PL_RD(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE) & ~((uint32_t)0x80000000)) | ((uint32_t)start << 31));
}

__INLINE uint16_t dma_ccfg_size_getf(int elt_idx)
{
    uint32_t localVal = REG_PL_RD(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE);
    return ((localVal & ((uint32_t)0x00001FFF)) >> 0);
}

__INLINE void dma_ccfg_size_setf(int elt_idx, uint16_t size)
{
    ASSERT_ERR((((uint32_t)size << 0) & ~((uint32_t)0x00001FFF)) == 0);
    REG_PL_WR(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE, (REG_PL_RD(DMA_CCFG_ADDR + elt_idx * REG_DMA_CHANNEL_SIZE) & ~((uint32_t)0x00001FFF)) | ((uint32_t)size << 0));
}


#endif // _REG_DMA_CHANNEL_H_

