#ifndef _REG_DMA_H_
#define _REG_DMA_H_

#include <stdint.h>
#include "_reg_dma.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_DMA_COUNT 12

#define REG_DMA_DECODING_MASK 0x0000003F

/**
 * @brief CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01               ENABLE   0
 *     00                RESET   0
 * </pre>
 */
#define DMA_CFG_ADDR   0x1000B000
#define DMA_CFG_OFFSET 0x00000000
#define DMA_CFG_INDEX  0x00000000
#define DMA_CFG_RESET  0x00000000

__INLINE uint32_t dma_cfg_get(void)
{
    return REG_PL_RD(DMA_CFG_ADDR);
}

__INLINE void dma_cfg_set(uint32_t value)
{
    REG_PL_WR(DMA_CFG_ADDR, value);
}

// field definitions
#define DMA_ENABLE_BIT    ((uint32_t)0x00000002)
#define DMA_ENABLE_POS    1
#define DMA_RESET_BIT     ((uint32_t)0x00000001)
#define DMA_RESET_POS     0

#define DMA_ENABLE_RST    0x0
#define DMA_RESET_RST     0x0

__INLINE void dma_cfg_pack(uint8_t enable, uint8_t reset)
{
    ASSERT_ERR((((uint32_t)enable << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)reset << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(DMA_CFG_ADDR,  ((uint32_t)enable << 1) | ((uint32_t)reset << 0));
}

__INLINE void dma_cfg_unpack(uint8_t* enable, uint8_t* reset)
{
    uint32_t localVal = REG_PL_RD(DMA_CFG_ADDR);

    *enable = (localVal & ((uint32_t)0x00000002)) >> 1;
    *reset = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t dma_cfg_enable_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_CFG_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void dma_cfg_enable_setf(uint8_t enable)
{
    ASSERT_ERR((((uint32_t)enable << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(DMA_CFG_ADDR, (REG_PL_RD(DMA_CFG_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)enable << 1));
}

__INLINE void dma_cfg_reset_setf(uint8_t reset)
{
    ASSERT_ERR((((uint32_t)reset << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(DMA_CFG_ADDR, (REG_PL_RD(DMA_CFG_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)reset << 0));
}

/**
 * @brief ISR_STAT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01       CHANNEL_1_STAT   0
 *     00       CHANNEL_0_STAT   0
 * </pre>
 */
#define DMA_ISR_STAT_ADDR   0x1000B004
#define DMA_ISR_STAT_OFFSET 0x00000004
#define DMA_ISR_STAT_INDEX  0x00000001
#define DMA_ISR_STAT_RESET  0x00000000

__INLINE uint32_t dma_isr_stat_get(void)
{
    return REG_PL_RD(DMA_ISR_STAT_ADDR);
}

// field definitions
#define DMA_CHANNEL_1_STAT_BIT    ((uint32_t)0x00000002)
#define DMA_CHANNEL_1_STAT_POS    1
#define DMA_CHANNEL_0_STAT_BIT    ((uint32_t)0x00000001)
#define DMA_CHANNEL_0_STAT_POS    0

#define DMA_CHANNEL_1_STAT_RST    0x0
#define DMA_CHANNEL_0_STAT_RST    0x0

__INLINE void dma_isr_stat_unpack(uint8_t* channel1stat, uint8_t* channel0stat)
{
    uint32_t localVal = REG_PL_RD(DMA_ISR_STAT_ADDR);

    *channel1stat = (localVal & ((uint32_t)0x00000002)) >> 1;
    *channel0stat = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t dma_isr_stat_channel_1_stat_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_ISR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE uint8_t dma_isr_stat_channel_0_stat_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_ISR_STAT_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

/**
 * @brief ISR_EN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01         CHANNEL_1_EN   0
 *     00         CHANNEL_0_EN   0
 * </pre>
 */
#define DMA_ISR_EN_ADDR   0x1000B008
#define DMA_ISR_EN_OFFSET 0x00000008
#define DMA_ISR_EN_INDEX  0x00000002
#define DMA_ISR_EN_RESET  0x00000000

__INLINE uint32_t dma_isr_en_get(void)
{
    return REG_PL_RD(DMA_ISR_EN_ADDR);
}

__INLINE void dma_isr_en_set(uint32_t value)
{
    REG_PL_WR(DMA_ISR_EN_ADDR, value);
}

// field definitions
#define DMA_CHANNEL_1_EN_BIT    ((uint32_t)0x00000002)
#define DMA_CHANNEL_1_EN_POS    1
#define DMA_CHANNEL_0_EN_BIT    ((uint32_t)0x00000001)
#define DMA_CHANNEL_0_EN_POS    0

#define DMA_CHANNEL_1_EN_RST    0x0
#define DMA_CHANNEL_0_EN_RST    0x0

__INLINE void dma_isr_en_pack(uint8_t channel1en, uint8_t channel0en)
{
    ASSERT_ERR((((uint32_t)channel1en << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)channel0en << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(DMA_ISR_EN_ADDR,  ((uint32_t)channel1en << 1) | ((uint32_t)channel0en << 0));
}

__INLINE void dma_isr_en_unpack(uint8_t* channel1en, uint8_t* channel0en)
{
    uint32_t localVal = REG_PL_RD(DMA_ISR_EN_ADDR);

    *channel1en = (localVal & ((uint32_t)0x00000002)) >> 1;
    *channel0en = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint8_t dma_isr_en_channel_1_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_ISR_EN_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void dma_isr_en_channel_1_en_setf(uint8_t channel1en)
{
    ASSERT_ERR((((uint32_t)channel1en << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(DMA_ISR_EN_ADDR, (REG_PL_RD(DMA_ISR_EN_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)channel1en << 1));
}

__INLINE uint8_t dma_isr_en_channel_0_en_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_ISR_EN_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void dma_isr_en_channel_0_en_setf(uint8_t channel0en)
{
    ASSERT_ERR((((uint32_t)channel0en << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(DMA_ISR_EN_ADDR, (REG_PL_RD(DMA_ISR_EN_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)channel0en << 0));
}

/**
 * @brief ISR_CLR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01        CHANNEL_1_CLR   0
 *     00        CHANNEL_0_CLR   0
 * </pre>
 */
#define DMA_ISR_CLR_ADDR   0x1000B00C
#define DMA_ISR_CLR_OFFSET 0x0000000C
#define DMA_ISR_CLR_INDEX  0x00000003
#define DMA_ISR_CLR_RESET  0x00000000

__INLINE void dma_isr_clr_set(uint32_t value)
{
    REG_PL_WR(DMA_ISR_CLR_ADDR, value);
}

// field definitions
#define DMA_CHANNEL_1_CLR_BIT    ((uint32_t)0x00000002)
#define DMA_CHANNEL_1_CLR_POS    1
#define DMA_CHANNEL_0_CLR_BIT    ((uint32_t)0x00000001)
#define DMA_CHANNEL_0_CLR_POS    0

#define DMA_CHANNEL_1_CLR_RST    0x0
#define DMA_CHANNEL_0_CLR_RST    0x0

__INLINE void dma_isr_clr_pack(uint8_t channel1clr, uint8_t channel0clr)
{
    ASSERT_ERR((((uint32_t)channel1clr << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)channel0clr << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(DMA_ISR_CLR_ADDR,  ((uint32_t)channel1clr << 1) | ((uint32_t)channel0clr << 0));
}

__INLINE void dma_isr_clr_channel_1_clr_setf(uint8_t channel1clr)
{
    ASSERT_ERR((((uint32_t)channel1clr << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(DMA_ISR_CLR_ADDR, (REG_PL_RD(DMA_ISR_CLR_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)channel1clr << 1));
}

__INLINE void dma_isr_clr_channel_0_clr_setf(uint8_t channel0clr)
{
    ASSERT_ERR((((uint32_t)channel0clr << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(DMA_ISR_CLR_ADDR, (REG_PL_RD(DMA_ISR_CLR_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)channel0clr << 0));
}

/**
 * @brief SAR_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                SAR_0   0x0
 * </pre>
 */
#define DMA_SAR_0_ADDR   0x1000B010
#define DMA_SAR_0_OFFSET 0x00000010
#define DMA_SAR_0_INDEX  0x00000004
#define DMA_SAR_0_RESET  0x00000000

__INLINE uint32_t dma_sar_0_get(void)
{
    return REG_PL_RD(DMA_SAR_0_ADDR);
}

__INLINE void dma_sar_0_set(uint32_t value)
{
    REG_PL_WR(DMA_SAR_0_ADDR, value);
}

// field definitions
#define DMA_SAR_0_MASK   ((uint32_t)0xFFFFFFFF)
#define DMA_SAR_0_LSB    0
#define DMA_SAR_0_WIDTH  ((uint32_t)0x00000020)

#define DMA_SAR_0_RST    0x0

__INLINE uint32_t dma_sar_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_SAR_0_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief DAR_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                DAR_0   0x0
 * </pre>
 */
#define DMA_DAR_0_ADDR   0x1000B014
#define DMA_DAR_0_OFFSET 0x00000014
#define DMA_DAR_0_INDEX  0x00000005
#define DMA_DAR_0_RESET  0x00000000

__INLINE void dma_dar_0_set(uint32_t value)
{
    REG_PL_WR(DMA_DAR_0_ADDR, value);
}

// field definitions
#define DMA_DAR_0_MASK   ((uint32_t)0xFFFFFFFF)
#define DMA_DAR_0_LSB    0
#define DMA_DAR_0_WIDTH  ((uint32_t)0x00000020)

#define DMA_DAR_0_RST    0x0

__INLINE void dma_dar_0_setf(uint32_t dar0)
{
    ASSERT_ERR((((uint32_t)dar0 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(DMA_DAR_0_ADDR, (uint32_t)dar0 << 0);
}

/**
 * @brief CCFG_0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31              START_0   0
 *  12:00               SIZE_0   0x0
 * </pre>
 */
#define DMA_CCFG_0_ADDR   0x1000B018
#define DMA_CCFG_0_OFFSET 0x00000018
#define DMA_CCFG_0_INDEX  0x00000006
#define DMA_CCFG_0_RESET  0x00000000

__INLINE uint32_t dma_ccfg_0_get(void)
{
    return REG_PL_RD(DMA_CCFG_0_ADDR);
}

__INLINE void dma_ccfg_0_set(uint32_t value)
{
    REG_PL_WR(DMA_CCFG_0_ADDR, value);
}

// field definitions
#define DMA_START_0_BIT    ((uint32_t)0x80000000)
#define DMA_START_0_POS    31
#define DMA_SIZE_0_MASK    ((uint32_t)0x00001FFF)
#define DMA_SIZE_0_LSB     0
#define DMA_SIZE_0_WIDTH   ((uint32_t)0x0000000D)

#define DMA_START_0_RST    0x0
#define DMA_SIZE_0_RST     0x0

__INLINE void dma_ccfg_0_pack(uint8_t start0, uint16_t size0)
{
    ASSERT_ERR((((uint32_t)start0 << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)size0 << 0) & ~((uint32_t)0x00001FFF)) == 0);
    REG_PL_WR(DMA_CCFG_0_ADDR,  ((uint32_t)start0 << 31) | ((uint32_t)size0 << 0));
}

__INLINE void dma_ccfg_0_unpack(uint8_t* start0, uint16_t* size0)
{
    uint32_t localVal = REG_PL_RD(DMA_CCFG_0_ADDR);

    *start0 = (localVal & ((uint32_t)0x80000000)) >> 31;
    *size0 = (localVal & ((uint32_t)0x00001FFF)) >> 0;
}

__INLINE void dma_ccfg_0_start_0_setf(uint8_t start0)
{
    ASSERT_ERR((((uint32_t)start0 << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(DMA_CCFG_0_ADDR, (REG_PL_RD(DMA_CCFG_0_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)start0 << 31));
}

__INLINE uint16_t dma_ccfg_0_size_0_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_CCFG_0_ADDR);
    return ((localVal & ((uint32_t)0x00001FFF)) >> 0);
}

__INLINE void dma_ccfg_0_size_0_setf(uint16_t size0)
{
    ASSERT_ERR((((uint32_t)size0 << 0) & ~((uint32_t)0x00001FFF)) == 0);
    REG_PL_WR(DMA_CCFG_0_ADDR, (REG_PL_RD(DMA_CCFG_0_ADDR) & ~((uint32_t)0x00001FFF)) | ((uint32_t)size0 << 0));
}

/**
 * @brief SAR_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                SAR_1   0x0
 * </pre>
 */
#define DMA_SAR_1_ADDR   0x1000B020
#define DMA_SAR_1_OFFSET 0x00000020
#define DMA_SAR_1_INDEX  0x00000008
#define DMA_SAR_1_RESET  0x00000000

__INLINE uint32_t dma_sar_1_get(void)
{
    return REG_PL_RD(DMA_SAR_1_ADDR);
}

__INLINE void dma_sar_1_set(uint32_t value)
{
    REG_PL_WR(DMA_SAR_1_ADDR, value);
}

// field definitions
#define DMA_SAR_1_MASK   ((uint32_t)0xFFFFFFFF)
#define DMA_SAR_1_LSB    0
#define DMA_SAR_1_WIDTH  ((uint32_t)0x00000020)

#define DMA_SAR_1_RST    0x0

__INLINE uint32_t dma_sar_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_SAR_1_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief DAR_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                DAR_1   0x0
 * </pre>
 */
#define DMA_DAR_1_ADDR   0x1000B024
#define DMA_DAR_1_OFFSET 0x00000024
#define DMA_DAR_1_INDEX  0x00000009
#define DMA_DAR_1_RESET  0x00000000

__INLINE void dma_dar_1_set(uint32_t value)
{
    REG_PL_WR(DMA_DAR_1_ADDR, value);
}

// field definitions
#define DMA_DAR_1_MASK   ((uint32_t)0xFFFFFFFF)
#define DMA_DAR_1_LSB    0
#define DMA_DAR_1_WIDTH  ((uint32_t)0x00000020)

#define DMA_DAR_1_RST    0x0

__INLINE void dma_dar_1_setf(uint32_t dar1)
{
    ASSERT_ERR((((uint32_t)dar1 << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(DMA_DAR_1_ADDR, (uint32_t)dar1 << 0);
}

/**
 * @brief CCFG_1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     31              START_1   0
 *  12:00               SIZE_1   0x0
 * </pre>
 */
#define DMA_CCFG_1_ADDR   0x1000B028
#define DMA_CCFG_1_OFFSET 0x00000028
#define DMA_CCFG_1_INDEX  0x0000000A
#define DMA_CCFG_1_RESET  0x00000000

__INLINE uint32_t dma_ccfg_1_get(void)
{
    return REG_PL_RD(DMA_CCFG_1_ADDR);
}

__INLINE void dma_ccfg_1_set(uint32_t value)
{
    REG_PL_WR(DMA_CCFG_1_ADDR, value);
}

// field definitions
#define DMA_START_1_BIT    ((uint32_t)0x80000000)
#define DMA_START_1_POS    31
#define DMA_SIZE_1_MASK    ((uint32_t)0x00001FFF)
#define DMA_SIZE_1_LSB     0
#define DMA_SIZE_1_WIDTH   ((uint32_t)0x0000000D)

#define DMA_START_1_RST    0x0
#define DMA_SIZE_1_RST     0x0

__INLINE void dma_ccfg_1_pack(uint8_t start1, uint16_t size1)
{
    ASSERT_ERR((((uint32_t)start1 << 31) & ~((uint32_t)0x80000000)) == 0);
    ASSERT_ERR((((uint32_t)size1 << 0) & ~((uint32_t)0x00001FFF)) == 0);
    REG_PL_WR(DMA_CCFG_1_ADDR,  ((uint32_t)start1 << 31) | ((uint32_t)size1 << 0));
}

__INLINE void dma_ccfg_1_unpack(uint8_t* start1, uint16_t* size1)
{
    uint32_t localVal = REG_PL_RD(DMA_CCFG_1_ADDR);

    *start1 = (localVal & ((uint32_t)0x80000000)) >> 31;
    *size1 = (localVal & ((uint32_t)0x00001FFF)) >> 0;
}

__INLINE void dma_ccfg_1_start_1_setf(uint8_t start1)
{
    ASSERT_ERR((((uint32_t)start1 << 31) & ~((uint32_t)0x80000000)) == 0);
    REG_PL_WR(DMA_CCFG_1_ADDR, (REG_PL_RD(DMA_CCFG_1_ADDR) & ~((uint32_t)0x80000000)) | ((uint32_t)start1 << 31));
}

__INLINE uint16_t dma_ccfg_1_size_1_getf(void)
{
    uint32_t localVal = REG_PL_RD(DMA_CCFG_1_ADDR);
    return ((localVal & ((uint32_t)0x00001FFF)) >> 0);
}

__INLINE void dma_ccfg_1_size_1_setf(uint16_t size1)
{
    ASSERT_ERR((((uint32_t)size1 << 0) & ~((uint32_t)0x00001FFF)) == 0);
    REG_PL_WR(DMA_CCFG_1_ADDR, (REG_PL_RD(DMA_CCFG_1_ADDR) & ~((uint32_t)0x00001FFF)) | ((uint32_t)size1 << 0));
}


#endif // _REG_DMA_H_

