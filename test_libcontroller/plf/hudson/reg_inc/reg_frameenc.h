#ifndef _REG_FRAMEENC_H_
#define _REG_FRAMEENC_H_

#include <stdint.h>
#include "_reg_frameenc.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_FRAMEENC_COUNT 12

#define REG_FRAMEENC_DECODING_MASK 0x0000003F

/**
 * @brief IN_BUF_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:18          IN_BUF_SIZE   0x0
 *  16:00           IN_BUF_PTR   0x0
 * </pre>
 */
#define FRAMEENC_IN_BUF_CONFIG_ADDR   0x1000E300
#define FRAMEENC_IN_BUF_CONFIG_OFFSET 0x00000000
#define FRAMEENC_IN_BUF_CONFIG_INDEX  0x00000000
#define FRAMEENC_IN_BUF_CONFIG_RESET  0x00000000

__INLINE uint32_t frameenc_in_buf_config_get(void)
{
    return REG_PL_RD(FRAMEENC_IN_BUF_CONFIG_ADDR);
}

__INLINE void frameenc_in_buf_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_IN_BUF_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEENC_IN_BUF_SIZE_MASK   ((uint32_t)0xFFFC0000)
#define FRAMEENC_IN_BUF_SIZE_LSB    18
#define FRAMEENC_IN_BUF_SIZE_WIDTH  ((uint32_t)0x0000000E)
#define FRAMEENC_IN_BUF_PTR_MASK    ((uint32_t)0x0001FFFF)
#define FRAMEENC_IN_BUF_PTR_LSB     0
#define FRAMEENC_IN_BUF_PTR_WIDTH   ((uint32_t)0x00000011)

#define FRAMEENC_IN_BUF_SIZE_RST    0x0
#define FRAMEENC_IN_BUF_PTR_RST     0x0

__INLINE void frameenc_in_buf_config_pack(uint16_t inbufsize, uint32_t inbufptr)
{
    ASSERT_ERR((((uint32_t)inbufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    ASSERT_ERR((((uint32_t)inbufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEENC_IN_BUF_CONFIG_ADDR,  ((uint32_t)inbufsize << 18) | ((uint32_t)inbufptr << 0));
}

__INLINE void frameenc_in_buf_config_unpack(uint16_t* inbufsize, uint32_t* inbufptr)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_IN_BUF_CONFIG_ADDR);

    *inbufsize = (localVal & ((uint32_t)0xFFFC0000)) >> 18;
    *inbufptr = (localVal & ((uint32_t)0x0001FFFF)) >> 0;
}

__INLINE uint16_t frameenc_in_buf_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_IN_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0xFFFC0000)) >> 18);
}

__INLINE void frameenc_in_buf_size_setf(uint16_t inbufsize)
{
    ASSERT_ERR((((uint32_t)inbufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    REG_PL_WR(FRAMEENC_IN_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEENC_IN_BUF_CONFIG_ADDR) & ~((uint32_t)0xFFFC0000)) | ((uint32_t)inbufsize << 18));
}

__INLINE uint32_t frameenc_in_buf_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_IN_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}

__INLINE void frameenc_in_buf_ptr_setf(uint32_t inbufptr)
{
    ASSERT_ERR((((uint32_t)inbufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEENC_IN_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEENC_IN_BUF_CONFIG_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)inbufptr << 0));
}

/**
 * @brief ISR_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00   ENCODED_ISR_STATUS   0
 * </pre>
 */
#define FRAMEENC_ISR_STATUS_ADDR   0x1000E304
#define FRAMEENC_ISR_STATUS_OFFSET 0x00000004
#define FRAMEENC_ISR_STATUS_INDEX  0x00000001
#define FRAMEENC_ISR_STATUS_RESET  0x00000000

__INLINE uint32_t frameenc_isr_status_get(void)
{
    return REG_PL_RD(FRAMEENC_ISR_STATUS_ADDR);
}

// field definitions
#define FRAMEENC_ENCODED_ISR_STATUS_BIT    ((uint32_t)0x00000001)
#define FRAMEENC_ENCODED_ISR_STATUS_POS    0

#define FRAMEENC_ENCODED_ISR_STATUS_RST    0x0

__INLINE uint8_t frameenc_encoded_isr_status_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_ISR_STATUS_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief ISR_ENABLE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00   ENCODED_ISR_ENABLE   0
 * </pre>
 */
#define FRAMEENC_ISR_ENABLE_ADDR   0x1000E308
#define FRAMEENC_ISR_ENABLE_OFFSET 0x00000008
#define FRAMEENC_ISR_ENABLE_INDEX  0x00000002
#define FRAMEENC_ISR_ENABLE_RESET  0x00000000

__INLINE uint32_t frameenc_isr_enable_get(void)
{
    return REG_PL_RD(FRAMEENC_ISR_ENABLE_ADDR);
}

__INLINE void frameenc_isr_enable_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_ISR_ENABLE_ADDR, value);
}

// field definitions
#define FRAMEENC_ENCODED_ISR_ENABLE_BIT    ((uint32_t)0x00000001)
#define FRAMEENC_ENCODED_ISR_ENABLE_POS    0

#define FRAMEENC_ENCODED_ISR_ENABLE_RST    0x0

__INLINE uint8_t frameenc_encoded_isr_enable_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_ISR_ENABLE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void frameenc_encoded_isr_enable_setf(uint8_t encodedisrenable)
{
    ASSERT_ERR((((uint32_t)encodedisrenable << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(FRAMEENC_ISR_ENABLE_ADDR, (uint32_t)encodedisrenable << 0);
}

/**
 * @brief ISR_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00    ENCODED_ISR_CLEAR   0
 * </pre>
 */
#define FRAMEENC_ISR_CLEAR_ADDR   0x1000E30C
#define FRAMEENC_ISR_CLEAR_OFFSET 0x0000000C
#define FRAMEENC_ISR_CLEAR_INDEX  0x00000003
#define FRAMEENC_ISR_CLEAR_RESET  0x00000000

__INLINE uint32_t frameenc_isr_clear_get(void)
{
    return REG_PL_RD(FRAMEENC_ISR_CLEAR_ADDR);
}

__INLINE void frameenc_isr_clear_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_ISR_CLEAR_ADDR, value);
}

// field definitions
#define FRAMEENC_ENCODED_ISR_CLEAR_BIT    ((uint32_t)0x00000001)
#define FRAMEENC_ENCODED_ISR_CLEAR_POS    0

#define FRAMEENC_ENCODED_ISR_CLEAR_RST    0x0

__INLINE uint8_t frameenc_encoded_isr_clear_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_ISR_CLEAR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void frameenc_encoded_isr_clear_setf(uint8_t encodedisrclear)
{
    ASSERT_ERR((((uint32_t)encodedisrclear << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(FRAMEENC_ISR_CLEAR_ADDR, (uint32_t)encodedisrclear << 0);
}

/**
 * @brief FRAME_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  25:16         FRAME_LENGTH   0x0
 *  13:00   ENCODING_DURATION_US   0x0
 * </pre>
 */
#define FRAMEENC_FRAME_CONFIG_ADDR   0x1000E310
#define FRAMEENC_FRAME_CONFIG_OFFSET 0x00000010
#define FRAMEENC_FRAME_CONFIG_INDEX  0x00000004
#define FRAMEENC_FRAME_CONFIG_RESET  0x00000000

__INLINE uint32_t frameenc_frame_config_get(void)
{
    return REG_PL_RD(FRAMEENC_FRAME_CONFIG_ADDR);
}

__INLINE void frameenc_frame_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_FRAME_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEENC_FRAME_LENGTH_MASK           ((uint32_t)0x03FF0000)
#define FRAMEENC_FRAME_LENGTH_LSB            16
#define FRAMEENC_FRAME_LENGTH_WIDTH          ((uint32_t)0x0000000A)
#define FRAMEENC_ENCODING_DURATION_US_MASK   ((uint32_t)0x00003FFF)
#define FRAMEENC_ENCODING_DURATION_US_LSB    0
#define FRAMEENC_ENCODING_DURATION_US_WIDTH  ((uint32_t)0x0000000E)

#define FRAMEENC_FRAME_LENGTH_RST            0x0
#define FRAMEENC_ENCODING_DURATION_US_RST    0x0

__INLINE void frameenc_frame_config_pack(uint16_t framelength, uint16_t encodingdurationus)
{
    ASSERT_ERR((((uint32_t)framelength << 16) & ~((uint32_t)0x03FF0000)) == 0);
    ASSERT_ERR((((uint32_t)encodingdurationus << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(FRAMEENC_FRAME_CONFIG_ADDR,  ((uint32_t)framelength << 16) | ((uint32_t)encodingdurationus << 0));
}

__INLINE void frameenc_frame_config_unpack(uint16_t* framelength, uint16_t* encodingdurationus)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_FRAME_CONFIG_ADDR);

    *framelength = (localVal & ((uint32_t)0x03FF0000)) >> 16;
    *encodingdurationus = (localVal & ((uint32_t)0x00003FFF)) >> 0;
}

__INLINE uint16_t frameenc_frame_length_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_FRAME_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x03FF0000)) >> 16);
}

__INLINE void frameenc_frame_length_setf(uint16_t framelength)
{
    ASSERT_ERR((((uint32_t)framelength << 16) & ~((uint32_t)0x03FF0000)) == 0);
    REG_PL_WR(FRAMEENC_FRAME_CONFIG_ADDR, (REG_PL_RD(FRAMEENC_FRAME_CONFIG_ADDR) & ~((uint32_t)0x03FF0000)) | ((uint32_t)framelength << 16));
}

__INLINE uint16_t frameenc_encoding_duration_us_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_FRAME_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00003FFF)) >> 0);
}

__INLINE void frameenc_encoding_duration_us_setf(uint16_t encodingdurationus)
{
    ASSERT_ERR((((uint32_t)encodingdurationus << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(FRAMEENC_FRAME_CONFIG_ADDR, (REG_PL_RD(FRAMEENC_FRAME_CONFIG_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)encodingdurationus << 0));
}

/**
 * @brief OUT_BUF_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:18         OUT_BUF_SIZE   0x0
 *  16:00          OUT_BUF_PTR   0x0
 * </pre>
 */
#define FRAMEENC_OUT_BUF_CONFIG_ADDR   0x1000E314
#define FRAMEENC_OUT_BUF_CONFIG_OFFSET 0x00000014
#define FRAMEENC_OUT_BUF_CONFIG_INDEX  0x00000005
#define FRAMEENC_OUT_BUF_CONFIG_RESET  0x00000000

__INLINE uint32_t frameenc_out_buf_config_get(void)
{
    return REG_PL_RD(FRAMEENC_OUT_BUF_CONFIG_ADDR);
}

__INLINE void frameenc_out_buf_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_OUT_BUF_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEENC_OUT_BUF_SIZE_MASK   ((uint32_t)0xFFFC0000)
#define FRAMEENC_OUT_BUF_SIZE_LSB    18
#define FRAMEENC_OUT_BUF_SIZE_WIDTH  ((uint32_t)0x0000000E)
#define FRAMEENC_OUT_BUF_PTR_MASK    ((uint32_t)0x0001FFFF)
#define FRAMEENC_OUT_BUF_PTR_LSB     0
#define FRAMEENC_OUT_BUF_PTR_WIDTH   ((uint32_t)0x00000011)

#define FRAMEENC_OUT_BUF_SIZE_RST    0x0
#define FRAMEENC_OUT_BUF_PTR_RST     0x0

__INLINE void frameenc_out_buf_config_pack(uint16_t outbufsize, uint32_t outbufptr)
{
    ASSERT_ERR((((uint32_t)outbufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    ASSERT_ERR((((uint32_t)outbufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEENC_OUT_BUF_CONFIG_ADDR,  ((uint32_t)outbufsize << 18) | ((uint32_t)outbufptr << 0));
}

__INLINE void frameenc_out_buf_config_unpack(uint16_t* outbufsize, uint32_t* outbufptr)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_OUT_BUF_CONFIG_ADDR);

    *outbufsize = (localVal & ((uint32_t)0xFFFC0000)) >> 18;
    *outbufptr = (localVal & ((uint32_t)0x0001FFFF)) >> 0;
}

__INLINE uint16_t frameenc_out_buf_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_OUT_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0xFFFC0000)) >> 18);
}

__INLINE void frameenc_out_buf_size_setf(uint16_t outbufsize)
{
    ASSERT_ERR((((uint32_t)outbufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    REG_PL_WR(FRAMEENC_OUT_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEENC_OUT_BUF_CONFIG_ADDR) & ~((uint32_t)0xFFFC0000)) | ((uint32_t)outbufsize << 18));
}

__INLINE uint32_t frameenc_out_buf_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_OUT_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}

__INLINE void frameenc_out_buf_ptr_setf(uint32_t outbufptr)
{
    ASSERT_ERR((((uint32_t)outbufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEENC_OUT_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEENC_OUT_BUF_CONFIG_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)outbufptr << 0));
}

/**
 * @brief FRAME_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00            FRAME_CNT   0x0
 * </pre>
 */
#define FRAMEENC_FRAME_CNT_ADDR   0x1000E318
#define FRAMEENC_FRAME_CNT_OFFSET 0x00000018
#define FRAMEENC_FRAME_CNT_INDEX  0x00000006
#define FRAMEENC_FRAME_CNT_RESET  0x00000000

__INLINE uint32_t frameenc_frame_cnt_get(void)
{
    return REG_PL_RD(FRAMEENC_FRAME_CNT_ADDR);
}

__INLINE void frameenc_frame_cnt_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_FRAME_CNT_ADDR, value);
}

// field definitions
#define FRAMEENC_FRAME_CNT_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEENC_FRAME_CNT_LSB    0
#define FRAMEENC_FRAME_CNT_WIDTH  ((uint32_t)0x00000020)

#define FRAMEENC_FRAME_CNT_RST    0x0

__INLINE uint32_t frameenc_frame_cnt_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_FRAME_CNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void frameenc_frame_cnt_setf(uint32_t framecnt)
{
    ASSERT_ERR((((uint32_t)framecnt << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(FRAMEENC_FRAME_CNT_ADDR, (uint32_t)framecnt << 0);
}

/**
 * @brief RD_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  16:00               RD_PTR   0x0
 * </pre>
 */
#define FRAMEENC_RD_INFO_ADDR   0x1000E31C
#define FRAMEENC_RD_INFO_OFFSET 0x0000001C
#define FRAMEENC_RD_INFO_INDEX  0x00000007
#define FRAMEENC_RD_INFO_RESET  0x00000000

__INLINE uint32_t frameenc_rd_info_get(void)
{
    return REG_PL_RD(FRAMEENC_RD_INFO_ADDR);
}

// field definitions
#define FRAMEENC_RD_PTR_MASK   ((uint32_t)0x0001FFFF)
#define FRAMEENC_RD_PTR_LSB    0
#define FRAMEENC_RD_PTR_WIDTH  ((uint32_t)0x00000011)

#define FRAMEENC_RD_PTR_RST    0x0

__INLINE uint32_t frameenc_rd_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_RD_INFO_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0001FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAMPLE_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16           NB_SAMPLES   0x0
 *  02:00          SAMPLE_SIZE   0x0
 * </pre>
 */
#define FRAMEENC_SAMPLE_CONFIG_ADDR   0x1000E320
#define FRAMEENC_SAMPLE_CONFIG_OFFSET 0x00000020
#define FRAMEENC_SAMPLE_CONFIG_INDEX  0x00000008
#define FRAMEENC_SAMPLE_CONFIG_RESET  0x00000000

__INLINE uint32_t frameenc_sample_config_get(void)
{
    return REG_PL_RD(FRAMEENC_SAMPLE_CONFIG_ADDR);
}

__INLINE void frameenc_sample_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_SAMPLE_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEENC_NB_SAMPLES_MASK    ((uint32_t)0x01FF0000)
#define FRAMEENC_NB_SAMPLES_LSB     16
#define FRAMEENC_NB_SAMPLES_WIDTH   ((uint32_t)0x00000009)
#define FRAMEENC_SAMPLE_SIZE_MASK   ((uint32_t)0x00000007)
#define FRAMEENC_SAMPLE_SIZE_LSB    0
#define FRAMEENC_SAMPLE_SIZE_WIDTH  ((uint32_t)0x00000003)

#define FRAMEENC_NB_SAMPLES_RST     0x0
#define FRAMEENC_SAMPLE_SIZE_RST    0x0

__INLINE void frameenc_sample_config_pack(uint16_t nbsamples, uint8_t samplesize)
{
    ASSERT_ERR((((uint32_t)nbsamples << 16) & ~((uint32_t)0x01FF0000)) == 0);
    ASSERT_ERR((((uint32_t)samplesize << 0) & ~((uint32_t)0x00000007)) == 0);
    REG_PL_WR(FRAMEENC_SAMPLE_CONFIG_ADDR,  ((uint32_t)nbsamples << 16) | ((uint32_t)samplesize << 0));
}

__INLINE void frameenc_sample_config_unpack(uint16_t* nbsamples, uint8_t* samplesize)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_SAMPLE_CONFIG_ADDR);

    *nbsamples = (localVal & ((uint32_t)0x01FF0000)) >> 16;
    *samplesize = (localVal & ((uint32_t)0x00000007)) >> 0;
}

__INLINE uint16_t frameenc_nb_samples_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_SAMPLE_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x01FF0000)) >> 16);
}

__INLINE void frameenc_nb_samples_setf(uint16_t nbsamples)
{
    ASSERT_ERR((((uint32_t)nbsamples << 16) & ~((uint32_t)0x01FF0000)) == 0);
    REG_PL_WR(FRAMEENC_SAMPLE_CONFIG_ADDR, (REG_PL_RD(FRAMEENC_SAMPLE_CONFIG_ADDR) & ~((uint32_t)0x01FF0000)) | ((uint32_t)nbsamples << 16));
}

__INLINE uint8_t frameenc_sample_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_SAMPLE_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000007)) >> 0);
}

__INLINE void frameenc_sample_size_setf(uint8_t samplesize)
{
    ASSERT_ERR((((uint32_t)samplesize << 0) & ~((uint32_t)0x00000007)) == 0);
    REG_PL_WR(FRAMEENC_SAMPLE_CONFIG_ADDR, (REG_PL_RD(FRAMEENC_SAMPLE_CONFIG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)samplesize << 0));
}

/**
 * @brief WR_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  16:00               WR_PTR   0x0
 * </pre>
 */
#define FRAMEENC_WR_INFO_ADDR   0x1000E324
#define FRAMEENC_WR_INFO_OFFSET 0x00000024
#define FRAMEENC_WR_INFO_INDEX  0x00000009
#define FRAMEENC_WR_INFO_RESET  0x00000000

__INLINE uint32_t frameenc_wr_info_get(void)
{
    return REG_PL_RD(FRAMEENC_WR_INFO_ADDR);
}

// field definitions
#define FRAMEENC_WR_PTR_MASK   ((uint32_t)0x0001FFFF)
#define FRAMEENC_WR_PTR_LSB    0
#define FRAMEENC_WR_PTR_WIDTH  ((uint32_t)0x00000011)

#define FRAMEENC_WR_PTR_RST    0x0

__INLINE uint32_t frameenc_wr_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_WR_INFO_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0001FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SDU_INTERVAL_US register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00                VALUE   0x0
 * </pre>
 */
#define FRAMEENC_SDU_INTERVAL_US_ADDR   0x1000E328
#define FRAMEENC_SDU_INTERVAL_US_OFFSET 0x00000028
#define FRAMEENC_SDU_INTERVAL_US_INDEX  0x0000000A
#define FRAMEENC_SDU_INTERVAL_US_RESET  0x00000000

__INLINE uint32_t frameenc_sdu_interval_us_get(void)
{
    return REG_PL_RD(FRAMEENC_SDU_INTERVAL_US_ADDR);
}

__INLINE void frameenc_sdu_interval_us_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_SDU_INTERVAL_US_ADDR, value);
}

// field definitions
#define FRAMEENC_VALUE_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEENC_VALUE_LSB    0
#define FRAMEENC_VALUE_WIDTH  ((uint32_t)0x00000020)

#define FRAMEENC_VALUE_RST    0x0

__INLINE uint32_t frameenc_value_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_SDU_INTERVAL_US_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void frameenc_value_setf(uint32_t value)
{
    ASSERT_ERR((((uint32_t)value << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(FRAMEENC_SDU_INTERVAL_US_ADDR, (uint32_t)value << 0);
}

/**
 * @brief SAMPLE_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00                   NB   0x0
 * </pre>
 */
#define FRAMEENC_SAMPLE_CNT_ADDR   0x1000E32C
#define FRAMEENC_SAMPLE_CNT_OFFSET 0x0000002C
#define FRAMEENC_SAMPLE_CNT_INDEX  0x0000000B
#define FRAMEENC_SAMPLE_CNT_RESET  0x00000000

__INLINE uint32_t frameenc_sample_cnt_get(void)
{
    return REG_PL_RD(FRAMEENC_SAMPLE_CNT_ADDR);
}

__INLINE void frameenc_sample_cnt_set(uint32_t value)
{
    REG_PL_WR(FRAMEENC_SAMPLE_CNT_ADDR, value);
}

// field definitions
#define FRAMEENC_NB_MASK   ((uint32_t)0x0000FFFF)
#define FRAMEENC_NB_LSB    0
#define FRAMEENC_NB_WIDTH  ((uint32_t)0x00000010)

#define FRAMEENC_NB_RST    0x0

__INLINE uint16_t frameenc_nb_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEENC_SAMPLE_CNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0000FFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void frameenc_nb_setf(uint16_t nb)
{
    ASSERT_ERR((((uint32_t)nb << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(FRAMEENC_SAMPLE_CNT_ADDR, (uint32_t)nb << 0);
}


#endif // _REG_FRAMEENC_H_

