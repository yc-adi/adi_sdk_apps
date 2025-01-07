#ifndef _REG_FRAMEDEC_H_
#define _REG_FRAMEDEC_H_

#include <stdint.h>
#include "_reg_framedec.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_FRAMEDEC_COUNT 17

#define REG_FRAMEDEC_DECODING_MASK 0x0000007F

/**
 * @brief IN_BUF_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:18          IN_BUF_SIZE   0x0
 *  16:00           IN_BUF_PTR   0x0
 * </pre>
 */
#define FRAMEDEC_IN_BUF_CONFIG_ADDR   0x1000E200
#define FRAMEDEC_IN_BUF_CONFIG_OFFSET 0x00000000
#define FRAMEDEC_IN_BUF_CONFIG_INDEX  0x00000000
#define FRAMEDEC_IN_BUF_CONFIG_RESET  0x00000000

__INLINE uint32_t framedec_in_buf_config_get(void)
{
    return REG_PL_RD(FRAMEDEC_IN_BUF_CONFIG_ADDR);
}

__INLINE void framedec_in_buf_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEDEC_IN_BUF_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEDEC_IN_BUF_SIZE_MASK   ((uint32_t)0xFFFC0000)
#define FRAMEDEC_IN_BUF_SIZE_LSB    18
#define FRAMEDEC_IN_BUF_SIZE_WIDTH  ((uint32_t)0x0000000E)
#define FRAMEDEC_IN_BUF_PTR_MASK    ((uint32_t)0x0001FFFF)
#define FRAMEDEC_IN_BUF_PTR_LSB     0
#define FRAMEDEC_IN_BUF_PTR_WIDTH   ((uint32_t)0x00000011)

#define FRAMEDEC_IN_BUF_SIZE_RST    0x0
#define FRAMEDEC_IN_BUF_PTR_RST     0x0

__INLINE void framedec_in_buf_config_pack(uint16_t inbufsize, uint32_t inbufptr)
{
    ASSERT_ERR((((uint32_t)inbufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    ASSERT_ERR((((uint32_t)inbufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEDEC_IN_BUF_CONFIG_ADDR,  ((uint32_t)inbufsize << 18) | ((uint32_t)inbufptr << 0));
}

__INLINE void framedec_in_buf_config_unpack(uint16_t* inbufsize, uint32_t* inbufptr)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_IN_BUF_CONFIG_ADDR);

    *inbufsize = (localVal & ((uint32_t)0xFFFC0000)) >> 18;
    *inbufptr = (localVal & ((uint32_t)0x0001FFFF)) >> 0;
}

__INLINE uint16_t framedec_in_buf_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_IN_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0xFFFC0000)) >> 18);
}

__INLINE void framedec_in_buf_size_setf(uint16_t inbufsize)
{
    ASSERT_ERR((((uint32_t)inbufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    REG_PL_WR(FRAMEDEC_IN_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_IN_BUF_CONFIG_ADDR) & ~((uint32_t)0xFFFC0000)) | ((uint32_t)inbufsize << 18));
}

__INLINE uint32_t framedec_in_buf_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_IN_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}

__INLINE void framedec_in_buf_ptr_setf(uint32_t inbufptr)
{
    ASSERT_ERR((((uint32_t)inbufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEDEC_IN_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_IN_BUF_CONFIG_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)inbufptr << 0));
}

/**
 * @brief FRAME_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  25:16         FRAME_LENGTH   0x0
 *  13:00   DECODING_DURATION_US   0x0
 * </pre>
 */
#define FRAMEDEC_FRAME_CONFIG_ADDR   0x1000E204
#define FRAMEDEC_FRAME_CONFIG_OFFSET 0x00000004
#define FRAMEDEC_FRAME_CONFIG_INDEX  0x00000001
#define FRAMEDEC_FRAME_CONFIG_RESET  0x00000000

__INLINE uint32_t framedec_frame_config_get(void)
{
    return REG_PL_RD(FRAMEDEC_FRAME_CONFIG_ADDR);
}

__INLINE void framedec_frame_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEDEC_FRAME_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEDEC_FRAME_LENGTH_MASK           ((uint32_t)0x03FF0000)
#define FRAMEDEC_FRAME_LENGTH_LSB            16
#define FRAMEDEC_FRAME_LENGTH_WIDTH          ((uint32_t)0x0000000A)
#define FRAMEDEC_DECODING_DURATION_US_MASK   ((uint32_t)0x00003FFF)
#define FRAMEDEC_DECODING_DURATION_US_LSB    0
#define FRAMEDEC_DECODING_DURATION_US_WIDTH  ((uint32_t)0x0000000E)

#define FRAMEDEC_FRAME_LENGTH_RST            0x0
#define FRAMEDEC_DECODING_DURATION_US_RST    0x0

__INLINE void framedec_frame_config_pack(uint16_t framelength, uint16_t decodingdurationus)
{
    ASSERT_ERR((((uint32_t)framelength << 16) & ~((uint32_t)0x03FF0000)) == 0);
    ASSERT_ERR((((uint32_t)decodingdurationus << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(FRAMEDEC_FRAME_CONFIG_ADDR,  ((uint32_t)framelength << 16) | ((uint32_t)decodingdurationus << 0));
}

__INLINE void framedec_frame_config_unpack(uint16_t* framelength, uint16_t* decodingdurationus)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_FRAME_CONFIG_ADDR);

    *framelength = (localVal & ((uint32_t)0x03FF0000)) >> 16;
    *decodingdurationus = (localVal & ((uint32_t)0x00003FFF)) >> 0;
}

__INLINE uint16_t framedec_frame_length_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_FRAME_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x03FF0000)) >> 16);
}

__INLINE void framedec_frame_length_setf(uint16_t framelength)
{
    ASSERT_ERR((((uint32_t)framelength << 16) & ~((uint32_t)0x03FF0000)) == 0);
    REG_PL_WR(FRAMEDEC_FRAME_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_FRAME_CONFIG_ADDR) & ~((uint32_t)0x03FF0000)) | ((uint32_t)framelength << 16));
}

__INLINE uint16_t framedec_decoding_duration_us_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_FRAME_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00003FFF)) >> 0);
}

__INLINE void framedec_decoding_duration_us_setf(uint16_t decodingdurationus)
{
    ASSERT_ERR((((uint32_t)decodingdurationus << 0) & ~((uint32_t)0x00003FFF)) == 0);
    REG_PL_WR(FRAMEDEC_FRAME_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_FRAME_CONFIG_ADDR) & ~((uint32_t)0x00003FFF)) | ((uint32_t)decodingdurationus << 0));
}

/**
 * @brief NB_DECODED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00           NB_DECODED   0x0
 * </pre>
 */
#define FRAMEDEC_NB_DECODED_ADDR   0x1000E208
#define FRAMEDEC_NB_DECODED_OFFSET 0x00000008
#define FRAMEDEC_NB_DECODED_INDEX  0x00000002
#define FRAMEDEC_NB_DECODED_RESET  0x00000000

__INLINE uint32_t framedec_nb_decoded_get(void)
{
    return REG_PL_RD(FRAMEDEC_NB_DECODED_ADDR);
}

// field definitions
#define FRAMEDEC_NB_DECODED_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEDEC_NB_DECODED_LSB    0
#define FRAMEDEC_NB_DECODED_WIDTH  ((uint32_t)0x00000020)

#define FRAMEDEC_NB_DECODED_RST    0x0

__INLINE uint32_t framedec_nb_decoded_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_NB_DECODED_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief NB_MISSED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00            NB_MISSED   0x0
 * </pre>
 */
#define FRAMEDEC_NB_MISSED_ADDR   0x1000E20C
#define FRAMEDEC_NB_MISSED_OFFSET 0x0000000C
#define FRAMEDEC_NB_MISSED_INDEX  0x00000003
#define FRAMEDEC_NB_MISSED_RESET  0x00000000

__INLINE uint32_t framedec_nb_missed_get(void)
{
    return REG_PL_RD(FRAMEDEC_NB_MISSED_ADDR);
}

// field definitions
#define FRAMEDEC_NB_MISSED_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEDEC_NB_MISSED_LSB    0
#define FRAMEDEC_NB_MISSED_WIDTH  ((uint32_t)0x00000020)

#define FRAMEDEC_NB_MISSED_RST    0x0

__INLINE uint32_t framedec_nb_missed_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_NB_MISSED_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief EXP_FRAME_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00        EXP_FRAME_CNT   0x0
 * </pre>
 */
#define FRAMEDEC_EXP_FRAME_CNT_ADDR   0x1000E210
#define FRAMEDEC_EXP_FRAME_CNT_OFFSET 0x00000010
#define FRAMEDEC_EXP_FRAME_CNT_INDEX  0x00000004
#define FRAMEDEC_EXP_FRAME_CNT_RESET  0x00000000

__INLINE uint32_t framedec_exp_frame_cnt_get(void)
{
    return REG_PL_RD(FRAMEDEC_EXP_FRAME_CNT_ADDR);
}

// field definitions
#define FRAMEDEC_EXP_FRAME_CNT_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEDEC_EXP_FRAME_CNT_LSB    0
#define FRAMEDEC_EXP_FRAME_CNT_WIDTH  ((uint32_t)0x00000020)

#define FRAMEDEC_EXP_FRAME_CNT_RST    0x0

__INLINE uint32_t framedec_exp_frame_cnt_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_EXP_FRAME_CNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief ISR_STATUS register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00   DECODED_ISR_STATUS   0
 * </pre>
 */
#define FRAMEDEC_ISR_STATUS_ADDR   0x1000E214
#define FRAMEDEC_ISR_STATUS_OFFSET 0x00000014
#define FRAMEDEC_ISR_STATUS_INDEX  0x00000005
#define FRAMEDEC_ISR_STATUS_RESET  0x00000000

__INLINE uint32_t framedec_isr_status_get(void)
{
    return REG_PL_RD(FRAMEDEC_ISR_STATUS_ADDR);
}

// field definitions
#define FRAMEDEC_DECODED_ISR_STATUS_BIT    ((uint32_t)0x00000001)
#define FRAMEDEC_DECODED_ISR_STATUS_POS    0

#define FRAMEDEC_DECODED_ISR_STATUS_RST    0x0

__INLINE uint8_t framedec_decoded_isr_status_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_ISR_STATUS_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

/**
 * @brief ISR_ENABLE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00   DECODED_ISR_ENABLE   0
 * </pre>
 */
#define FRAMEDEC_ISR_ENABLE_ADDR   0x1000E218
#define FRAMEDEC_ISR_ENABLE_OFFSET 0x00000018
#define FRAMEDEC_ISR_ENABLE_INDEX  0x00000006
#define FRAMEDEC_ISR_ENABLE_RESET  0x00000000

__INLINE uint32_t framedec_isr_enable_get(void)
{
    return REG_PL_RD(FRAMEDEC_ISR_ENABLE_ADDR);
}

__INLINE void framedec_isr_enable_set(uint32_t value)
{
    REG_PL_WR(FRAMEDEC_ISR_ENABLE_ADDR, value);
}

// field definitions
#define FRAMEDEC_DECODED_ISR_ENABLE_BIT    ((uint32_t)0x00000001)
#define FRAMEDEC_DECODED_ISR_ENABLE_POS    0

#define FRAMEDEC_DECODED_ISR_ENABLE_RST    0x0

__INLINE uint8_t framedec_decoded_isr_enable_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_ISR_ENABLE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void framedec_decoded_isr_enable_setf(uint8_t decodedisrenable)
{
    ASSERT_ERR((((uint32_t)decodedisrenable << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(FRAMEDEC_ISR_ENABLE_ADDR, (uint32_t)decodedisrenable << 0);
}

/**
 * @brief ISR_CLEAR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     00    DECODED_ISR_CLEAR   0
 * </pre>
 */
#define FRAMEDEC_ISR_CLEAR_ADDR   0x1000E21C
#define FRAMEDEC_ISR_CLEAR_OFFSET 0x0000001C
#define FRAMEDEC_ISR_CLEAR_INDEX  0x00000007
#define FRAMEDEC_ISR_CLEAR_RESET  0x00000000

__INLINE uint32_t framedec_isr_clear_get(void)
{
    return REG_PL_RD(FRAMEDEC_ISR_CLEAR_ADDR);
}

__INLINE void framedec_isr_clear_set(uint32_t value)
{
    REG_PL_WR(FRAMEDEC_ISR_CLEAR_ADDR, value);
}

// field definitions
#define FRAMEDEC_DECODED_ISR_CLEAR_BIT    ((uint32_t)0x00000001)
#define FRAMEDEC_DECODED_ISR_CLEAR_POS    0

#define FRAMEDEC_DECODED_ISR_CLEAR_RST    0x0

__INLINE uint8_t framedec_decoded_isr_clear_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_ISR_CLEAR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000001)) == 0);
    return (localVal >> 0);
}

__INLINE void framedec_decoded_isr_clear_setf(uint8_t decodedisrclear)
{
    ASSERT_ERR((((uint32_t)decodedisrclear << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(FRAMEDEC_ISR_CLEAR_ADDR, (uint32_t)decodedisrclear << 0);
}

/**
 * @brief SAMPLE_CNT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00           SAMPLE_CNT   0x0
 * </pre>
 */
#define FRAMEDEC_SAMPLE_CNT_ADDR   0x1000E220
#define FRAMEDEC_SAMPLE_CNT_OFFSET 0x00000020
#define FRAMEDEC_SAMPLE_CNT_INDEX  0x00000008
#define FRAMEDEC_SAMPLE_CNT_RESET  0x00000000

__INLINE uint32_t framedec_sample_cnt_get(void)
{
    return REG_PL_RD(FRAMEDEC_SAMPLE_CNT_ADDR);
}

// field definitions
#define FRAMEDEC_SAMPLE_CNT_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEDEC_SAMPLE_CNT_LSB    0
#define FRAMEDEC_SAMPLE_CNT_WIDTH  ((uint32_t)0x00000020)

#define FRAMEDEC_SAMPLE_CNT_RST    0x0

__INLINE uint32_t framedec_sample_cnt_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_SAMPLE_CNT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief OUT_DIR1_BUF_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:18    OUT_DIR1_BUF_SIZE   0x0
 *  16:00     OUT_DIR1_BUF_PTR   0x0
 * </pre>
 */
#define FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR   0x1000E224
#define FRAMEDEC_OUT_DIR1_BUF_CONFIG_OFFSET 0x00000024
#define FRAMEDEC_OUT_DIR1_BUF_CONFIG_INDEX  0x00000009
#define FRAMEDEC_OUT_DIR1_BUF_CONFIG_RESET  0x00000000

__INLINE uint32_t framedec_out_dir1_buf_config_get(void)
{
    return REG_PL_RD(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR);
}

__INLINE void framedec_out_dir1_buf_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEDEC_OUT_DIR1_BUF_SIZE_MASK   ((uint32_t)0xFFFC0000)
#define FRAMEDEC_OUT_DIR1_BUF_SIZE_LSB    18
#define FRAMEDEC_OUT_DIR1_BUF_SIZE_WIDTH  ((uint32_t)0x0000000E)
#define FRAMEDEC_OUT_DIR1_BUF_PTR_MASK    ((uint32_t)0x0001FFFF)
#define FRAMEDEC_OUT_DIR1_BUF_PTR_LSB     0
#define FRAMEDEC_OUT_DIR1_BUF_PTR_WIDTH   ((uint32_t)0x00000011)

#define FRAMEDEC_OUT_DIR1_BUF_SIZE_RST    0x0
#define FRAMEDEC_OUT_DIR1_BUF_PTR_RST     0x0

__INLINE void framedec_out_dir1_buf_config_pack(uint16_t outdir1bufsize, uint32_t outdir1bufptr)
{
    ASSERT_ERR((((uint32_t)outdir1bufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    ASSERT_ERR((((uint32_t)outdir1bufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR,  ((uint32_t)outdir1bufsize << 18) | ((uint32_t)outdir1bufptr << 0));
}

__INLINE void framedec_out_dir1_buf_config_unpack(uint16_t* outdir1bufsize, uint32_t* outdir1bufptr)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR);

    *outdir1bufsize = (localVal & ((uint32_t)0xFFFC0000)) >> 18;
    *outdir1bufptr = (localVal & ((uint32_t)0x0001FFFF)) >> 0;
}

__INLINE uint16_t framedec_out_dir1_buf_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0xFFFC0000)) >> 18);
}

__INLINE void framedec_out_dir1_buf_size_setf(uint16_t outdir1bufsize)
{
    ASSERT_ERR((((uint32_t)outdir1bufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    REG_PL_WR(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR) & ~((uint32_t)0xFFFC0000)) | ((uint32_t)outdir1bufsize << 18));
}

__INLINE uint32_t framedec_out_dir1_buf_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}

__INLINE void framedec_out_dir1_buf_ptr_setf(uint32_t outdir1bufptr)
{
    ASSERT_ERR((((uint32_t)outdir1bufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_OUT_DIR1_BUF_CONFIG_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)outdir1bufptr << 0));
}

/**
 * @brief OUT_DIR2_BUF_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:18    OUT_DIR2_BUF_SIZE   0x0
 *  16:00     OUT_DIR2_BUF_PTR   0x0
 * </pre>
 */
#define FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR   0x1000E228
#define FRAMEDEC_OUT_DIR2_BUF_CONFIG_OFFSET 0x00000028
#define FRAMEDEC_OUT_DIR2_BUF_CONFIG_INDEX  0x0000000A
#define FRAMEDEC_OUT_DIR2_BUF_CONFIG_RESET  0x00000000

__INLINE uint32_t framedec_out_dir2_buf_config_get(void)
{
    return REG_PL_RD(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR);
}

__INLINE void framedec_out_dir2_buf_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEDEC_OUT_DIR2_BUF_SIZE_MASK   ((uint32_t)0xFFFC0000)
#define FRAMEDEC_OUT_DIR2_BUF_SIZE_LSB    18
#define FRAMEDEC_OUT_DIR2_BUF_SIZE_WIDTH  ((uint32_t)0x0000000E)
#define FRAMEDEC_OUT_DIR2_BUF_PTR_MASK    ((uint32_t)0x0001FFFF)
#define FRAMEDEC_OUT_DIR2_BUF_PTR_LSB     0
#define FRAMEDEC_OUT_DIR2_BUF_PTR_WIDTH   ((uint32_t)0x00000011)

#define FRAMEDEC_OUT_DIR2_BUF_SIZE_RST    0x0
#define FRAMEDEC_OUT_DIR2_BUF_PTR_RST     0x0

__INLINE void framedec_out_dir2_buf_config_pack(uint16_t outdir2bufsize, uint32_t outdir2bufptr)
{
    ASSERT_ERR((((uint32_t)outdir2bufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    ASSERT_ERR((((uint32_t)outdir2bufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR,  ((uint32_t)outdir2bufsize << 18) | ((uint32_t)outdir2bufptr << 0));
}

__INLINE void framedec_out_dir2_buf_config_unpack(uint16_t* outdir2bufsize, uint32_t* outdir2bufptr)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR);

    *outdir2bufsize = (localVal & ((uint32_t)0xFFFC0000)) >> 18;
    *outdir2bufptr = (localVal & ((uint32_t)0x0001FFFF)) >> 0;
}

__INLINE uint16_t framedec_out_dir2_buf_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0xFFFC0000)) >> 18);
}

__INLINE void framedec_out_dir2_buf_size_setf(uint16_t outdir2bufsize)
{
    ASSERT_ERR((((uint32_t)outdir2bufsize << 18) & ~((uint32_t)0xFFFC0000)) == 0);
    REG_PL_WR(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR) & ~((uint32_t)0xFFFC0000)) | ((uint32_t)outdir2bufsize << 18));
}

__INLINE uint32_t framedec_out_dir2_buf_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x0001FFFF)) >> 0);
}

__INLINE void framedec_out_dir2_buf_ptr_setf(uint32_t outdir2bufptr)
{
    ASSERT_ERR((((uint32_t)outdir2bufptr << 0) & ~((uint32_t)0x0001FFFF)) == 0);
    REG_PL_WR(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_OUT_DIR2_BUF_CONFIG_ADDR) & ~((uint32_t)0x0001FFFF)) | ((uint32_t)outdir2bufptr << 0));
}

/**
 * @brief RD_INFO register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  16:00               RD_PTR   0x0
 * </pre>
 */
#define FRAMEDEC_RD_INFO_ADDR   0x1000E22C
#define FRAMEDEC_RD_INFO_OFFSET 0x0000002C
#define FRAMEDEC_RD_INFO_INDEX  0x0000000B
#define FRAMEDEC_RD_INFO_RESET  0x00000000

__INLINE uint32_t framedec_rd_info_get(void)
{
    return REG_PL_RD(FRAMEDEC_RD_INFO_ADDR);
}

// field definitions
#define FRAMEDEC_RD_PTR_MASK   ((uint32_t)0x0001FFFF)
#define FRAMEDEC_RD_PTR_LSB    0
#define FRAMEDEC_RD_PTR_WIDTH  ((uint32_t)0x00000011)

#define FRAMEDEC_RD_PTR_RST    0x0

__INLINE uint32_t framedec_rd_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_RD_INFO_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0001FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief WR_INFO_DIR1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  16:00          DIR1_WR_PTR   0x0
 * </pre>
 */
#define FRAMEDEC_WR_INFO_DIR1_ADDR   0x1000E230
#define FRAMEDEC_WR_INFO_DIR1_OFFSET 0x00000030
#define FRAMEDEC_WR_INFO_DIR1_INDEX  0x0000000C
#define FRAMEDEC_WR_INFO_DIR1_RESET  0x00000000

__INLINE uint32_t framedec_wr_info_dir1_get(void)
{
    return REG_PL_RD(FRAMEDEC_WR_INFO_DIR1_ADDR);
}

// field definitions
#define FRAMEDEC_DIR1_WR_PTR_MASK   ((uint32_t)0x0001FFFF)
#define FRAMEDEC_DIR1_WR_PTR_LSB    0
#define FRAMEDEC_DIR1_WR_PTR_WIDTH  ((uint32_t)0x00000011)

#define FRAMEDEC_DIR1_WR_PTR_RST    0x0

__INLINE uint32_t framedec_dir1_wr_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_WR_INFO_DIR1_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0001FFFF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief NB_SAMPLE_GENERATED register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  09:00   NB_SAMPLE_GENERATED   0x0
 * </pre>
 */
#define FRAMEDEC_NB_SAMPLE_GENERATED_ADDR   0x1000E234
#define FRAMEDEC_NB_SAMPLE_GENERATED_OFFSET 0x00000034
#define FRAMEDEC_NB_SAMPLE_GENERATED_INDEX  0x0000000D
#define FRAMEDEC_NB_SAMPLE_GENERATED_RESET  0x00000000

__INLINE uint32_t framedec_nb_sample_generated_get(void)
{
    return REG_PL_RD(FRAMEDEC_NB_SAMPLE_GENERATED_ADDR);
}

// field definitions
#define FRAMEDEC_NB_SAMPLE_GENERATED_MASK   ((uint32_t)0x000003FF)
#define FRAMEDEC_NB_SAMPLE_GENERATED_LSB    0
#define FRAMEDEC_NB_SAMPLE_GENERATED_WIDTH  ((uint32_t)0x0000000A)

#define FRAMEDEC_NB_SAMPLE_GENERATED_RST    0x0

__INLINE uint16_t framedec_nb_sample_generated_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_NB_SAMPLE_GENERATED_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x000003FF)) == 0);
    return (localVal >> 0);
}

/**
 * @brief SAMPLE_CONFIG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  18:16          SAMPLE_SIZE   0x0
 *  06:04       IN_SAMPLE_FREQ   0x0
 *  02:00      OUT_SAMPLE_FREQ   0x0
 * </pre>
 */
#define FRAMEDEC_SAMPLE_CONFIG_ADDR   0x1000E238
#define FRAMEDEC_SAMPLE_CONFIG_OFFSET 0x00000038
#define FRAMEDEC_SAMPLE_CONFIG_INDEX  0x0000000E
#define FRAMEDEC_SAMPLE_CONFIG_RESET  0x00000000

__INLINE uint32_t framedec_sample_config_get(void)
{
    return REG_PL_RD(FRAMEDEC_SAMPLE_CONFIG_ADDR);
}

__INLINE void framedec_sample_config_set(uint32_t value)
{
    REG_PL_WR(FRAMEDEC_SAMPLE_CONFIG_ADDR, value);
}

// field definitions
#define FRAMEDEC_SAMPLE_SIZE_MASK       ((uint32_t)0x00070000)
#define FRAMEDEC_SAMPLE_SIZE_LSB        16
#define FRAMEDEC_SAMPLE_SIZE_WIDTH      ((uint32_t)0x00000003)
#define FRAMEDEC_IN_SAMPLE_FREQ_MASK    ((uint32_t)0x00000070)
#define FRAMEDEC_IN_SAMPLE_FREQ_LSB     4
#define FRAMEDEC_IN_SAMPLE_FREQ_WIDTH   ((uint32_t)0x00000003)
#define FRAMEDEC_OUT_SAMPLE_FREQ_MASK   ((uint32_t)0x00000007)
#define FRAMEDEC_OUT_SAMPLE_FREQ_LSB    0
#define FRAMEDEC_OUT_SAMPLE_FREQ_WIDTH  ((uint32_t)0x00000003)

#define FRAMEDEC_SAMPLE_SIZE_RST        0x0
#define FRAMEDEC_IN_SAMPLE_FREQ_RST     0x0
#define FRAMEDEC_OUT_SAMPLE_FREQ_RST    0x0

__INLINE void framedec_sample_config_pack(uint8_t samplesize, uint8_t insamplefreq, uint8_t outsamplefreq)
{
    ASSERT_ERR((((uint32_t)samplesize << 16) & ~((uint32_t)0x00070000)) == 0);
    ASSERT_ERR((((uint32_t)insamplefreq << 4) & ~((uint32_t)0x00000070)) == 0);
    ASSERT_ERR((((uint32_t)outsamplefreq << 0) & ~((uint32_t)0x00000007)) == 0);
    REG_PL_WR(FRAMEDEC_SAMPLE_CONFIG_ADDR,  ((uint32_t)samplesize << 16) | ((uint32_t)insamplefreq << 4) | ((uint32_t)outsamplefreq << 0));
}

__INLINE void framedec_sample_config_unpack(uint8_t* samplesize, uint8_t* insamplefreq, uint8_t* outsamplefreq)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_SAMPLE_CONFIG_ADDR);

    *samplesize = (localVal & ((uint32_t)0x00070000)) >> 16;
    *insamplefreq = (localVal & ((uint32_t)0x00000070)) >> 4;
    *outsamplefreq = (localVal & ((uint32_t)0x00000007)) >> 0;
}

__INLINE uint8_t framedec_sample_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_SAMPLE_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00070000)) >> 16);
}

__INLINE void framedec_sample_size_setf(uint8_t samplesize)
{
    ASSERT_ERR((((uint32_t)samplesize << 16) & ~((uint32_t)0x00070000)) == 0);
    REG_PL_WR(FRAMEDEC_SAMPLE_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_SAMPLE_CONFIG_ADDR) & ~((uint32_t)0x00070000)) | ((uint32_t)samplesize << 16));
}

__INLINE uint8_t framedec_in_sample_freq_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_SAMPLE_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000070)) >> 4);
}

__INLINE void framedec_in_sample_freq_setf(uint8_t insamplefreq)
{
    ASSERT_ERR((((uint32_t)insamplefreq << 4) & ~((uint32_t)0x00000070)) == 0);
    REG_PL_WR(FRAMEDEC_SAMPLE_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_SAMPLE_CONFIG_ADDR) & ~((uint32_t)0x00000070)) | ((uint32_t)insamplefreq << 4));
}

__INLINE uint8_t framedec_out_sample_freq_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_SAMPLE_CONFIG_ADDR);
    return ((localVal & ((uint32_t)0x00000007)) >> 0);
}

__INLINE void framedec_out_sample_freq_setf(uint8_t outsamplefreq)
{
    ASSERT_ERR((((uint32_t)outsamplefreq << 0) & ~((uint32_t)0x00000007)) == 0);
    REG_PL_WR(FRAMEDEC_SAMPLE_CONFIG_ADDR, (REG_PL_RD(FRAMEDEC_SAMPLE_CONFIG_ADDR) & ~((uint32_t)0x00000007)) | ((uint32_t)outsamplefreq << 0));
}

/**
 * @brief NB_MISSED_RX_BUF_FULL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00   NB_MISSED_RX_BUF_FULL   0x0
 * </pre>
 */
#define FRAMEDEC_NB_MISSED_RX_BUF_FULL_ADDR   0x1000E23C
#define FRAMEDEC_NB_MISSED_RX_BUF_FULL_OFFSET 0x0000003C
#define FRAMEDEC_NB_MISSED_RX_BUF_FULL_INDEX  0x0000000F
#define FRAMEDEC_NB_MISSED_RX_BUF_FULL_RESET  0x00000000

__INLINE uint32_t framedec_nb_missed_rx_buf_full_get(void)
{
    return REG_PL_RD(FRAMEDEC_NB_MISSED_RX_BUF_FULL_ADDR);
}

__INLINE void framedec_nb_missed_rx_buf_full_set(uint32_t value)
{
    REG_PL_WR(FRAMEDEC_NB_MISSED_RX_BUF_FULL_ADDR, value);
}

// field definitions
#define FRAMEDEC_NB_MISSED_RX_BUF_FULL_MASK   ((uint32_t)0xFFFFFFFF)
#define FRAMEDEC_NB_MISSED_RX_BUF_FULL_LSB    0
#define FRAMEDEC_NB_MISSED_RX_BUF_FULL_WIDTH  ((uint32_t)0x00000020)

#define FRAMEDEC_NB_MISSED_RX_BUF_FULL_RST    0x0

__INLINE uint32_t framedec_nb_missed_rx_buf_full_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_NB_MISSED_RX_BUF_FULL_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void framedec_nb_missed_rx_buf_full_setf(uint32_t nbmissedrxbuffull)
{
    ASSERT_ERR((((uint32_t)nbmissedrxbuffull << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(FRAMEDEC_NB_MISSED_RX_BUF_FULL_ADDR, (uint32_t)nbmissedrxbuffull << 0);
}

/**
 * @brief WR_INFO_DIR2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  16:00          DIR2_WR_PTR   0x0
 * </pre>
 */
#define FRAMEDEC_WR_INFO_DIR2_ADDR   0x1000E240
#define FRAMEDEC_WR_INFO_DIR2_OFFSET 0x00000040
#define FRAMEDEC_WR_INFO_DIR2_INDEX  0x00000010
#define FRAMEDEC_WR_INFO_DIR2_RESET  0x00000000

__INLINE uint32_t framedec_wr_info_dir2_get(void)
{
    return REG_PL_RD(FRAMEDEC_WR_INFO_DIR2_ADDR);
}

// field definitions
#define FRAMEDEC_DIR2_WR_PTR_MASK   ((uint32_t)0x0001FFFF)
#define FRAMEDEC_DIR2_WR_PTR_LSB    0
#define FRAMEDEC_DIR2_WR_PTR_WIDTH  ((uint32_t)0x00000011)

#define FRAMEDEC_DIR2_WR_PTR_RST    0x0

__INLINE uint32_t framedec_dir2_wr_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(FRAMEDEC_WR_INFO_DIR2_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x0001FFFF)) == 0);
    return (localVal >> 0);
}


#endif // _REG_FRAMEDEC_H_

