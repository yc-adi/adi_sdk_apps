#ifndef _REG_FRAMEGEN_H_
#define _REG_FRAMEGEN_H_

#include <stdint.h>
#include "_reg_framegen.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_FRAMEGEN_COUNT 9

#define REG_FRAMEGEN_DECODING_MASK 0x0000003F

/**
 * @brief FRAME_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  25:16         FRAME_LENGTH   0x0
 *  13:00    FRAME_INTERVAL_US   0x0
 * </pre>
 */
#define FRAMEGEN_FRAME_CONFIG_ADDR   0x1000E100
#define FRAMEGEN_FRAME_CONFIG_OFFSET 0x00000000
#define FRAMEGEN_FRAME_CONFIG_INDEX  0x00000000
#define FRAMEGEN_FRAME_CONFIG_RESET  0x00000000

__INLINE uint32_t framegen_frame_config_get(void)
{
    return REG_PL_RD(FRAMEGEN_FRAME_CONFIG_ADDR);
}

__INLINE void framegen_frame_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEGEN_FRAME_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEGEN_FRAME_LENGTH_MASK        ((uint32_t)0x03FF0000)
#define FRAMEGEN_FRAME_LENGTH_LSB         16
#define FRAMEGEN_FRAME_LENGTH_WIDTH       ((uint32_t)0x0000000A)
#define FRAMEGEN_FRAME_INTERVAL_US_MASK   ((uint32_t)0x00003FFF)
#define FRAMEGEN_FRAME_INTERVAL_US_LSB    0
#define FRAMEGEN_FRAME_INTERVAL_US_WIDTH  ((uint32_t)0x0000000E)

#define FRAMEGEN_FRAME_LENGTH_RST         0x0
#define FRAMEGEN_FRAME_INTERVAL_US_RST    0x0

__INLINE void framegen_frame_config_pack(uint16_t framelength, uint16_t frameintervalus)
{
    ASSERT_ERR((((uint32_t)framelength << 16) & ~((uint32_t)0x03FF0000)) == 0);
    ASSERT_ERR((((uint32_t)frameintervalus << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(FRAMEGEN_FRAME_CONFIG_ADDR,  ((uint32_t)framelength << 16) | ((uint32_t)frameintervalus << 0));
}

__INLINE void framegen_frame_config_unpack(uint16_t* framelength, uint16_t* frameintervalus)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_FRAME_CONFIG_ADDR);

    *framelength = (localVal & ((uint32_t)0x03FF0000)) >> 16;
    *frameintervalus = (localVal & ((uint32_t)0x00003FFF)) >> 0;
}

__INLINE uint16_t framegen_frame_length_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_FRAME_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x03FF0000)) >> 16);
}

__INLINE void framegen_frame_length_setf(uint16_t framelength)
{
    ASSERT_ERR((((uint32_t)framelength << 16) & ~((uint32_t)0x03FF0000)) == 0);
    REG_PL_WR(FRAMEGEN_FRAME_CONFIG_ADDR, (REG_PL_RD(FRAMEGEN_FRAME_CONFIG_ADDR) & ~((uint32_t)0x03FF0000)) | ((uint32_t)framelength << 16));
}

__INLINE uint16_t framegen_frame_interval_us_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_FRAME_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00003FFF)) >> 0);
}

__INLINE void framegen_frame_interval_us_setf(uint16_t frameintervalus)
{
    ASSERT_ERR((((uint32_t)frameintervalus << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(FRAMEGEN_FRAME_CONFIG_ADDR, (REG_PL_RD(FRAMEGEN_FRAME_CONFIG_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)frameintervalus << 0));
}

/**
 * @brief FRAME_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00            FRAME_CNT   0x0
 * </pre>
 */
#define FRAMEGEN_FRAME_CNT_ADDR   0x1000E104
#define FRAMEGEN_FRAME_CNT_OFFSET 0x00000004
#define FRAMEGEN_FRAME_CNT_INDEX  0x00000001
#define FRAMEGEN_FRAME_CNT_RESET  0x00000000

__INLINE uint32_t framegen_frame_cnt_get(void)
{
    return REG_PL_RD(FRAMEGEN_FRAME_CNT_ADDR);
}

__INLINE void framegen_frame_cnt_set(uint32_t value)
{
    REG_PL_WR(FRAMEGEN_FRAME_CNT_ADDR, value);
}

// field definitions
#define FRAMEGEN_FRAME_CNT_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEGEN_FRAME_CNT_LSB    0
#define FRAMEGEN_FRAME_CNT_WIDTH  ((uint32_t)0x00000020)

#define FRAMEGEN_FRAME_CNT_RST    0x0

__INLINE uint32_t framegen_frame_cnt_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_FRAME_CNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void framegen_frame_cnt_setf(uint32_t framecnt)
{
    ASSERT_ERR((((uint32_t)framecnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(FRAMEGEN_FRAME_CNT_ADDR, (uint32_t)framecnt << 0);
}

/**
 * @brief ISR_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00     FRAME_ISR_STATUS   0
 * </pre>
 */
#define FRAMEGEN_ISR_STATUS_ADDR   0x1000E108
#define FRAMEGEN_ISR_STATUS_OFFSET 0x00000008
#define FRAMEGEN_ISR_STATUS_INDEX  0x00000002
#define FRAMEGEN_ISR_STATUS_RESET  0x00000000

__INLINE uint32_t framegen_isr_status_get(void)
{
    return REG_PL_RD(FRAMEGEN_ISR_STATUS_ADDR);
}

// field definitions
#define FRAMEGEN_FRAME_ISR_STATUS_BIT    ((uint32_t)0x00000001)
#define FRAMEGEN_FRAME_ISR_STATUS_POS    0

#define FRAMEGEN_FRAME_ISR_STATUS_RST    0x0

__INLINE uint8_t framegen_frame_isr_status_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_ISR_STATUS_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief ISR_ENABLE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00     FRAME_ISR_ENABLE   0
 * </pre>
 */
#define FRAMEGEN_ISR_ENABLE_ADDR   0x1000E10C
#define FRAMEGEN_ISR_ENABLE_OFFSET 0x0000000C
#define FRAMEGEN_ISR_ENABLE_INDEX  0x00000003
#define FRAMEGEN_ISR_ENABLE_RESET  0x00000000

__INLINE uint32_t framegen_isr_enable_get(void)
{
    return REG_PL_RD(FRAMEGEN_ISR_ENABLE_ADDR);
}

__INLINE void framegen_isr_enable_set(uint32_t value)
{
    REG_PL_WR(FRAMEGEN_ISR_ENABLE_ADDR, value);
}

// field definitions
#define FRAMEGEN_FRAME_ISR_ENABLE_BIT    ((uint32_t)0x00000001)
#define FRAMEGEN_FRAME_ISR_ENABLE_POS    0

#define FRAMEGEN_FRAME_ISR_ENABLE_RST    0x0

__INLINE uint8_t framegen_frame_isr_enable_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_ISR_ENABLE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void framegen_frame_isr_enable_setf(uint8_t frameisrenable)
{
    ASSERT_ERR((((uint32_t)frameisrenable << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(FRAMEGEN_ISR_ENABLE_ADDR, (uint32_t)frameisrenable << 0);
}

/**
 * @brief ISR_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00      FRAME_ISR_CLEAR   0
 * </pre>
 */
#define FRAMEGEN_ISR_CLEAR_ADDR   0x1000E110
#define FRAMEGEN_ISR_CLEAR_OFFSET 0x00000010
#define FRAMEGEN_ISR_CLEAR_INDEX  0x00000004
#define FRAMEGEN_ISR_CLEAR_RESET  0x00000000

__INLINE uint32_t framegen_isr_clear_get(void)
{
    return REG_PL_RD(FRAMEGEN_ISR_CLEAR_ADDR);
}

__INLINE void framegen_isr_clear_set(uint32_t value)
{
    REG_PL_WR(FRAMEGEN_ISR_CLEAR_ADDR, value);
}

// field definitions
#define FRAMEGEN_FRAME_ISR_CLEAR_BIT    ((uint32_t)0x00000001)
#define FRAMEGEN_FRAME_ISR_CLEAR_POS    0

#define FRAMEGEN_FRAME_ISR_CLEAR_RST    0x0

__INLINE uint8_t framegen_frame_isr_clear_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_ISR_CLEAR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void framegen_frame_isr_clear_setf(uint8_t frameisrclear)
{
    ASSERT_ERR((((uint32_t)frameisrclear << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(FRAMEGEN_ISR_CLEAR_ADDR, (uint32_t)frameisrclear << 0);
}

/**
 * @brief BUF_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:18             BUF_SIZE   0x0
 *  16:00              BUF_PTR   0x0
 * </pre>
 */
#define FRAMEGEN_BUF_CONFIG_ADDR   0x1000E114
#define FRAMEGEN_BUF_CONFIG_OFFSET 0x00000014
#define FRAMEGEN_BUF_CONFIG_INDEX  0x00000005
#define FRAMEGEN_BUF_CONFIG_RESET  0x00000000

__INLINE uint32_t framegen_buf_config_get(void)
{
    return REG_PL_RD(FRAMEGEN_BUF_CONFIG_ADDR);
}

__INLINE void framegen_buf_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEGEN_BUF_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEGEN_BUF_SIZE_MASK   ((uint32_t)0xFFFC0000)
#define FRAMEGEN_BUF_SIZE_LSB    18
#define FRAMEGEN_BUF_SIZE_WIDTH  ((uint32_t)0x0000000E)
#define FRAMEGEN_BUF_PTR_MASK    ((uint32_t)0x0001FFFF)
#define FRAMEGEN_BUF_PTR_LSB     0
#define FRAMEGEN_BUF_PTR_WIDTH   ((uint32_t)0x00000011)

#define FRAMEGEN_BUF_SIZE_RST    0x0
#define FRAMEGEN_BUF_PTR_RST     0x0

__INLINE void framegen_buf_config_pack(uint16_t bufsize, uint32_t bufptr)
{
    ASSERT_ERR((((uint32_t)bufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    ASSERT_ERR((((uint32_t)bufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEGEN_BUF_CONFIG_ADDR,  ((uint32_t)bufsize << 18) | ((uint32_t)bufptr << 0));
}

__INLINE void framegen_buf_config_unpack(uint16_t* bufsize, uint32_t* bufptr)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_BUF_CONFIG_ADDR);

    *bufsize = (localVal & ((uint32_t)0xFFFC0000)) >> 18;
    *bufptr = (localVal & ((uint32_t)0x0001FFFF)) >> 0;
}

__INLINE uint16_t framegen_buf_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0xFFFC0000)) >> 18);
}

__INLINE void framegen_buf_size_setf(uint16_t bufsize)
{
    ASSERT_ERR((((uint32_t)bufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    REG_PL_WR(FRAMEGEN_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEGEN_BUF_CONFIG_ADDR) & ~((uint32_t)0xFFFC0000)) | ((uint32_t)bufsize << 18));
}

__INLINE uint32_t framegen_buf_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}

__INLINE void framegen_buf_ptr_setf(uint32_t bufptr)
{
    ASSERT_ERR((((uint32_t)bufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEGEN_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEGEN_BUF_CONFIG_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)bufptr << 0));
}

/**
 * @brief WR_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  16:00               WR_PTR   0x0
 * </pre>
 */
#define FRAMEGEN_WR_INFO_ADDR   0x1000E118
#define FRAMEGEN_WR_INFO_OFFSET 0x00000018
#define FRAMEGEN_WR_INFO_INDEX  0x00000006
#define FRAMEGEN_WR_INFO_RESET  0x00000000

__INLINE uint32_t framegen_wr_info_get(void)
{
    return REG_PL_RD(FRAMEGEN_WR_INFO_ADDR);
}

// field definitions
#define FRAMEGEN_WR_PTR_MASK   ((uint32_t)0x0001FFFF)
#define FRAMEGEN_WR_PTR_LSB    0
#define FRAMEGEN_WR_PTR_WIDTH  ((uint32_t)0x00000011)

#define FRAMEGEN_WR_PTR_RST    0x0

__INLINE uint32_t framegen_wr_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_WR_INFO_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0001FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAMPLE_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  08:00           NB_SAMPLES   0x0
 * </pre>
 */
#define FRAMEGEN_SAMPLE_CONFIG_ADDR   0x1000E11C
#define FRAMEGEN_SAMPLE_CONFIG_OFFSET 0x0000001C
#define FRAMEGEN_SAMPLE_CONFIG_INDEX  0x00000007
#define FRAMEGEN_SAMPLE_CONFIG_RESET  0x00000000

__INLINE uint32_t framegen_sample_config_get(void)
{
    return REG_PL_RD(FRAMEGEN_SAMPLE_CONFIG_ADDR);
}

__INLINE void framegen_sample_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEGEN_SAMPLE_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEGEN_NB_SAMPLES_MASK   ((uint32_t)0x000001FF)
#define FRAMEGEN_NB_SAMPLES_LSB    0
#define FRAMEGEN_NB_SAMPLES_WIDTH  ((uint32_t)0x00000009)

#define FRAMEGEN_NB_SAMPLES_RST    0x0

__INLINE uint16_t framegen_nb_samples_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_SAMPLE_CONFIG_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000001FF)) == 0);
    return (localVal >> 0);
}

__INLINE void framegen_nb_samples_setf(uint16_t nbsamples)
{
    ASSERT_ERR((((uint32_t)nbsamples << 0) & ~((uint32_t)0x000001FF)) == 0);
    REG_PL_WR(FRAMEGEN_SAMPLE_CONFIG_ADDR, (uint32_t)nbsamples << 0);
}

/**
 * @brief SAMPLE_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00           SAMPLE_CNT   0x1
 * </pre>
 */
#define FRAMEGEN_SAMPLE_CNT_ADDR   0x1000E120
#define FRAMEGEN_SAMPLE_CNT_OFFSET 0x00000020
#define FRAMEGEN_SAMPLE_CNT_INDEX  0x00000008
#define FRAMEGEN_SAMPLE_CNT_RESET  0x00000001

__INLINE uint32_t framegen_sample_cnt_get(void)
{
    return REG_PL_RD(FRAMEGEN_SAMPLE_CNT_ADDR);
}

// field definitions
#define FRAMEGEN_SAMPLE_CNT_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEGEN_SAMPLE_CNT_LSB    0
#define FRAMEGEN_SAMPLE_CNT_WIDTH  ((uint32_t)0x00000020)

#define FRAMEGEN_SAMPLE_CNT_RST    0x1

__INLINE uint32_t framegen_sample_cnt_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEGEN_SAMPLE_CNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}


#endif // _REG_FRAMEGEN_H_

