#ifndef _REG_FRAMEPLAYER_H_
#define _REG_FRAMEPLAYER_H_

#include <stdint.h>
#include "_reg_frameplayer.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_FRAMEPLAYER_COUNT 4

#define REG_FRAMEPLAYER_DECODING_MASK 0x0000000F

/**
 * @brief BUF_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:18             BUF_SIZE   0x0
 *  16:00              BUF_PTR   0x0
 * </pre>
 */
#define FRAMEPLAYER_BUF_CONFIG_ADDR   0x1000E400
#define FRAMEPLAYER_BUF_CONFIG_OFFSET 0x00000000
#define FRAMEPLAYER_BUF_CONFIG_INDEX  0x00000000
#define FRAMEPLAYER_BUF_CONFIG_RESET  0x00000000

__INLINE uint32_t frameplayer_buf_config_get(void)
{
    return REG_PL_RD(FRAMEPLAYER_BUF_CONFIG_ADDR);
}

__INLINE void frameplayer_buf_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEPLAYER_BUF_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEPLAYER_BUF_SIZE_MASK   ((uint32_t)0xFFFC0000)
#define FRAMEPLAYER_BUF_SIZE_LSB    18
#define FRAMEPLAYER_BUF_SIZE_WIDTH  ((uint32_t)0x0000000E)
#define FRAMEPLAYER_BUF_PTR_MASK    ((uint32_t)0x0001FFFF)
#define FRAMEPLAYER_BUF_PTR_LSB     0
#define FRAMEPLAYER_BUF_PTR_WIDTH   ((uint32_t)0x00000011)

#define FRAMEPLAYER_BUF_SIZE_RST    0x0
#define FRAMEPLAYER_BUF_PTR_RST     0x0

__INLINE void frameplayer_buf_config_pack(uint16_t bufsize, uint32_t bufptr)
{
    ASSERT_ERR((((uint32_t)bufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    ASSERT_ERR((((uint32_t)bufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEPLAYER_BUF_CONFIG_ADDR,  ((uint32_t)bufsize << 18) | ((uint32_t)bufptr << 0));
}

__INLINE void frameplayer_buf_config_unpack(uint16_t* bufsize, uint32_t* bufptr)
{
    uint32_t localVal = REG_PL_RD(FRAMEPLAYER_BUF_CONFIG_ADDR);

    *bufsize = (localVal & ((uint32_t)0xFFFC0000)) >> 18;
    *bufptr = (localVal & ((uint32_t)0x0001FFFF)) >> 0;
}

__INLINE uint16_t frameplayer_buf_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEPLAYER_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0xFFFC0000)) >> 18);
}

__INLINE void frameplayer_buf_size_setf(uint16_t bufsize)
{
    ASSERT_ERR((((uint32_t)bufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    REG_PL_WR(FRAMEPLAYER_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEPLAYER_BUF_CONFIG_ADDR) & ~((uint32_t)0xFFFC0000)) | ((uint32_t)bufsize << 18));
}

__INLINE uint32_t frameplayer_buf_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEPLAYER_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}

__INLINE void frameplayer_buf_ptr_setf(uint32_t bufptr)
{
    ASSERT_ERR((((uint32_t)bufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEPLAYER_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEPLAYER_BUF_CONFIG_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)bufptr << 0));
}

/**
 * @brief RD_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  16:00               RD_PTR   0x0
 * </pre>
 */
#define FRAMEPLAYER_RD_INFO_ADDR   0x1000E404
#define FRAMEPLAYER_RD_INFO_OFFSET 0x00000004
#define FRAMEPLAYER_RD_INFO_INDEX  0x00000001
#define FRAMEPLAYER_RD_INFO_RESET  0x00000000

__INLINE uint32_t frameplayer_rd_info_get(void)
{
    return REG_PL_RD(FRAMEPLAYER_RD_INFO_ADDR);
}

__INLINE void frameplayer_rd_info_set(uint32_t value)
{
    REG_PL_WR(FRAMEPLAYER_RD_INFO_ADDR, value);
}

// field definitions
#define FRAMEPLAYER_RD_PTR_MASK   ((uint32_t)0x0001FFFF)
#define FRAMEPLAYER_RD_PTR_LSB    0
#define FRAMEPLAYER_RD_PTR_WIDTH  ((uint32_t)0x00000011)

#define FRAMEPLAYER_RD_PTR_RST    0x0

__INLINE uint32_t frameplayer_rd_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEPLAYER_RD_INFO_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0001FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void frameplayer_rd_ptr_setf(uint32_t rdptr)
{
    ASSERT_ERR((((uint32_t)rdptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEPLAYER_RD_INFO_ADDR, (uint32_t)rdptr << 0);
}

/**
 * @brief TIMESTAMP register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00            TIMESTAMP   0x0
 * </pre>
 */
#define FRAMEPLAYER_TIMESTAMP_ADDR   0x1000E408
#define FRAMEPLAYER_TIMESTAMP_OFFSET 0x00000008
#define FRAMEPLAYER_TIMESTAMP_INDEX  0x00000002
#define FRAMEPLAYER_TIMESTAMP_RESET  0x00000000

__INLINE uint32_t frameplayer_timestamp_get(void)
{
    return REG_PL_RD(FRAMEPLAYER_TIMESTAMP_ADDR);
}

__INLINE void frameplayer_timestamp_set(uint32_t value)
{
    REG_PL_WR(FRAMEPLAYER_TIMESTAMP_ADDR, value);
}

// field definitions
#define FRAMEPLAYER_TIMESTAMP_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEPLAYER_TIMESTAMP_LSB    0
#define FRAMEPLAYER_TIMESTAMP_WIDTH  ((uint32_t)0x00000020)

#define FRAMEPLAYER_TIMESTAMP_RST    0x0

__INLINE uint32_t frameplayer_timestamp_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEPLAYER_TIMESTAMP_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void frameplayer_timestamp_setf(uint32_t timestamp)
{
    ASSERT_ERR((((uint32_t)timestamp << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(FRAMEPLAYER_TIMESTAMP_ADDR, (uint32_t)timestamp << 0);
}

/**
 * @brief SAMPLE_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  18:16          SAMPLE_SIZE   0x0
 *  02:00          SAMPLE_FREQ   0x0
 * </pre>
 */
#define FRAMEPLAYER_SAMPLE_CONFIG_ADDR   0x1000E40C
#define FRAMEPLAYER_SAMPLE_CONFIG_OFFSET 0x0000000C
#define FRAMEPLAYER_SAMPLE_CONFIG_INDEX  0x00000003
#define FRAMEPLAYER_SAMPLE_CONFIG_RESET  0x00000000

__INLINE uint32_t frameplayer_sample_config_get(void)
{
    return REG_PL_RD(FRAMEPLAYER_SAMPLE_CONFIG_ADDR);
}

__INLINE void frameplayer_sample_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEPLAYER_SAMPLE_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEPLAYER_SAMPLE_SIZE_MASK   ((uint32_t)0x00070000)
#define FRAMEPLAYER_SAMPLE_SIZE_LSB    16
#define FRAMEPLAYER_SAMPLE_SIZE_WIDTH  ((uint32_t)0x00000003)
#define FRAMEPLAYER_SAMPLE_FREQ_MASK   ((uint32_t)0x00000007)
#define FRAMEPLAYER_SAMPLE_FREQ_LSB    0
#define FRAMEPLAYER_SAMPLE_FREQ_WIDTH  ((uint32_t)0x00000003)

#define FRAMEPLAYER_SAMPLE_SIZE_RST    0x0
#define FRAMEPLAYER_SAMPLE_FREQ_RST    0x0

__INLINE void frameplayer_sample_config_pack(uint8_t samplesize, uint8_t samplefreq)
{
    ASSERT_ERR((((uint32_t)samplesize << 16) & ~((uint32_t)0x00070000)) == 0);
    ASSERT_ERR((((uint32_t)samplefreq << 0) & ~((uint32_t)0x00000007)) == 0);
    REG_PL_WR(FRAMEPLAYER_SAMPLE_CONFIG_ADDR,  ((uint32_t)samplesize << 16) | ((uint32_t)samplefreq << 0));
}

__INLINE void frameplayer_sample_config_unpack(uint8_t* samplesize, uint8_t* samplefreq)
{
    uint32_t localVal = REG_PL_RD(FRAMEPLAYER_SAMPLE_CONFIG_ADDR);

    *samplesize = (localVal & ((uint32_t)0x00070000)) >> 16;
    *samplefreq = (localVal & ((uint32_t)0x00000007)) >> 0;
}

__INLINE uint8_t frameplayer_sample_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEPLAYER_SAMPLE_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00070000)) >> 16);
}

__INLINE void frameplayer_sample_size_setf(uint8_t samplesize)
{
    ASSERT_ERR((((uint32_t)samplesize << 16) & ~((uint32_t)0x00070000)) == 0);
    REG_PL_WR(FRAMEPLAYER_SAMPLE_CONFIG_ADDR, (REG_PL_RD(FRAMEPLAYER_SAMPLE_CONFIG_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)samplesize << 16));
}

__INLINE uint8_t frameplayer_sample_freq_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEPLAYER_SAMPLE_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000007)) >> 0);
}

__INLINE void frameplayer_sample_freq_setf(uint8_t samplefreq)
{
    ASSERT_ERR((((uint32_t)samplefreq << 0) & ~((uint32_t)0x00000007)) == 0);
    REG_PL_WR(FRAMEPLAYER_SAMPLE_CONFIG_ADDR, (REG_PL_RD(FRAMEPLAYER_SAMPLE_CONFIG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)samplefreq << 0));
}


#endif // _REG_FRAMEPLAYER_H_

