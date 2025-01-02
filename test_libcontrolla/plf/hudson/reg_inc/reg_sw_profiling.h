#ifndef _REG_SW_PROFILING_H_
#define _REG_SW_PROFILING_H_

#include <stdint.h>
#include "_reg_sw_profiling.h"
#include "compiler.h"
#include "arch.h"
#include "reg_access.h"

#define REG_SW_PROFILING_COUNT 12

#define REG_SW_PROFILING_DECODING_MASK 0x0000003F

/**
 * @brief CFG register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  01:00            DATA_SIZE   0x0
 * </pre>
 */
#define SW_PROF_CFG_ADDR   0x1000D100
#define SW_PROF_CFG_OFFSET 0x00000000
#define SW_PROF_CFG_INDEX  0x00000000
#define SW_PROF_CFG_RESET  0x00000000

__INLINE uint32_t sw_prof_cfg_get(void)
{
    return REG_PL_RD(SW_PROF_CFG_ADDR);
}

__INLINE void sw_prof_cfg_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_CFG_ADDR, value);
}

// field definitions
#define SW_PROF_DATA_SIZE_MASK   ((uint32_t)0x00000003)
#define SW_PROF_DATA_SIZE_LSB    0
#define SW_PROF_DATA_SIZE_WIDTH  ((uint32_t)0x00000002)

#define SW_PROF_DATA_SIZE_RST    0x0

__INLINE uint8_t sw_prof_data_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_CFG_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0x00000003)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_data_size_setf(uint8_t datasize)
{
    ASSERT_ERR((((uint32_t)datasize << 0) & ~((uint32_t)0x00000003)) == 0);
    REG_PL_WR(SW_PROF_CFG_ADDR, (uint32_t)datasize << 0);
}

/**
 * @brief FUNC_IN_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00          FUNC_IN_PTR   0x0
 * </pre>
 */
#define SW_PROF_FUNC_IN_PTR_ADDR   0x1000D104
#define SW_PROF_FUNC_IN_PTR_OFFSET 0x00000004
#define SW_PROF_FUNC_IN_PTR_INDEX  0x00000001
#define SW_PROF_FUNC_IN_PTR_RESET  0x00000000

__INLINE uint32_t sw_prof_func_in_ptr_get(void)
{
    return REG_PL_RD(SW_PROF_FUNC_IN_PTR_ADDR);
}

__INLINE void sw_prof_func_in_ptr_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_FUNC_IN_PTR_ADDR, value);
}

// field definitions
#define SW_PROF_FUNC_IN_PTR_MASK   ((uint32_t)0xFFFFFFFF)
#define SW_PROF_FUNC_IN_PTR_LSB    0
#define SW_PROF_FUNC_IN_PTR_WIDTH  ((uint32_t)0x00000020)

#define SW_PROF_FUNC_IN_PTR_RST    0x0

__INLINE uint32_t sw_prof_func_in_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_FUNC_IN_PTR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_func_in_ptr_setf(uint32_t funcinptr)
{
    ASSERT_ERR((((uint32_t)funcinptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(SW_PROF_FUNC_IN_PTR_ADDR, (uint32_t)funcinptr << 0);
}

/**
 * @brief FUNC_OUT_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00         FUNC_OUT_PTR   0x0
 * </pre>
 */
#define SW_PROF_FUNC_OUT_PTR_ADDR   0x1000D108
#define SW_PROF_FUNC_OUT_PTR_OFFSET 0x00000008
#define SW_PROF_FUNC_OUT_PTR_INDEX  0x00000002
#define SW_PROF_FUNC_OUT_PTR_RESET  0x00000000

__INLINE uint32_t sw_prof_func_out_ptr_get(void)
{
    return REG_PL_RD(SW_PROF_FUNC_OUT_PTR_ADDR);
}

__INLINE void sw_prof_func_out_ptr_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_FUNC_OUT_PTR_ADDR, value);
}

// field definitions
#define SW_PROF_FUNC_OUT_PTR_MASK   ((uint32_t)0xFFFFFFFF)
#define SW_PROF_FUNC_OUT_PTR_LSB    0
#define SW_PROF_FUNC_OUT_PTR_WIDTH  ((uint32_t)0x00000020)

#define SW_PROF_FUNC_OUT_PTR_RST    0x0

__INLINE uint32_t sw_prof_func_out_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_FUNC_OUT_PTR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_func_out_ptr_setf(uint32_t funcoutptr)
{
    ASSERT_ERR((((uint32_t)funcoutptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(SW_PROF_FUNC_OUT_PTR_ADDR, (uint32_t)funcoutptr << 0);
}

/**
 * @brief FUNC_NAME_PTR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00        FUNC_NAME_PTR   0x0
 * </pre>
 */
#define SW_PROF_FUNC_NAME_PTR_ADDR   0x1000D10C
#define SW_PROF_FUNC_NAME_PTR_OFFSET 0x0000000C
#define SW_PROF_FUNC_NAME_PTR_INDEX  0x00000003
#define SW_PROF_FUNC_NAME_PTR_RESET  0x00000000

__INLINE uint32_t sw_prof_func_name_ptr_get(void)
{
    return REG_PL_RD(SW_PROF_FUNC_NAME_PTR_ADDR);
}

__INLINE void sw_prof_func_name_ptr_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_FUNC_NAME_PTR_ADDR, value);
}

// field definitions
#define SW_PROF_FUNC_NAME_PTR_MASK   ((uint32_t)0xFFFFFFFF)
#define SW_PROF_FUNC_NAME_PTR_LSB    0
#define SW_PROF_FUNC_NAME_PTR_WIDTH  ((uint32_t)0x00000020)

#define SW_PROF_FUNC_NAME_PTR_RST    0x0

__INLINE uint32_t sw_prof_func_name_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_FUNC_NAME_PTR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_func_name_ptr_setf(uint32_t funcnameptr)
{
    ASSERT_ERR((((uint32_t)funcnameptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(SW_PROF_FUNC_NAME_PTR_ADDR, (uint32_t)funcnameptr << 0);
}

/**
 * @brief DATA_PTR_IN register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00          DATA_IN_PTR   0x0
 * </pre>
 */
#define SW_PROF_DATA_PTR_IN_ADDR   0x1000D110
#define SW_PROF_DATA_PTR_IN_OFFSET 0x00000010
#define SW_PROF_DATA_PTR_IN_INDEX  0x00000004
#define SW_PROF_DATA_PTR_IN_RESET  0x00000000

__INLINE uint32_t sw_prof_data_ptr_in_get(void)
{
    return REG_PL_RD(SW_PROF_DATA_PTR_IN_ADDR);
}

__INLINE void sw_prof_data_ptr_in_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_DATA_PTR_IN_ADDR, value);
}

// field definitions
#define SW_PROF_DATA_IN_PTR_MASK   ((uint32_t)0xFFFFFFFF)
#define SW_PROF_DATA_IN_PTR_LSB    0
#define SW_PROF_DATA_IN_PTR_WIDTH  ((uint32_t)0x00000020)

#define SW_PROF_DATA_IN_PTR_RST    0x0

__INLINE uint32_t sw_prof_data_in_ptr_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_DATA_PTR_IN_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_data_in_ptr_setf(uint32_t datainptr)
{
    ASSERT_ERR((((uint32_t)datainptr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(SW_PROF_DATA_PTR_IN_ADDR, (uint32_t)datainptr << 0);
}

/**
 * @brief DATA_PTR_OUT register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00         DATA_PTR_OUT   0x0
 * </pre>
 */
#define SW_PROF_DATA_PTR_OUT_ADDR   0x1000D114
#define SW_PROF_DATA_PTR_OUT_OFFSET 0x00000014
#define SW_PROF_DATA_PTR_OUT_INDEX  0x00000005
#define SW_PROF_DATA_PTR_OUT_RESET  0x00000000

__INLINE uint32_t sw_prof_data_ptr_out_get(void)
{
    return REG_PL_RD(SW_PROF_DATA_PTR_OUT_ADDR);
}

__INLINE void sw_prof_data_ptr_out_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_DATA_PTR_OUT_ADDR, value);
}

// field definitions
#define SW_PROF_DATA_PTR_OUT_MASK   ((uint32_t)0xFFFFFFFF)
#define SW_PROF_DATA_PTR_OUT_LSB    0
#define SW_PROF_DATA_PTR_OUT_WIDTH  ((uint32_t)0x00000020)

#define SW_PROF_DATA_PTR_OUT_RST    0x0

__INLINE uint32_t sw_prof_data_ptr_out_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_DATA_PTR_OUT_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_data_ptr_out_setf(uint32_t dataptrout)
{
    ASSERT_ERR((((uint32_t)dataptrout << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(SW_PROF_DATA_PTR_OUT_ADDR, (uint32_t)dataptrout << 0);
}

/**
 * @brief DATA_PTR_NAME register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00        DATA_PTR_NAME   0x0
 * </pre>
 */
#define SW_PROF_DATA_PTR_NAME_ADDR   0x1000D118
#define SW_PROF_DATA_PTR_NAME_OFFSET 0x00000018
#define SW_PROF_DATA_PTR_NAME_INDEX  0x00000006
#define SW_PROF_DATA_PTR_NAME_RESET  0x00000000

__INLINE uint32_t sw_prof_data_ptr_name_get(void)
{
    return REG_PL_RD(SW_PROF_DATA_PTR_NAME_ADDR);
}

__INLINE void sw_prof_data_ptr_name_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_DATA_PTR_NAME_ADDR, value);
}

// field definitions
#define SW_PROF_DATA_PTR_NAME_MASK   ((uint32_t)0xFFFFFFFF)
#define SW_PROF_DATA_PTR_NAME_LSB    0
#define SW_PROF_DATA_PTR_NAME_WIDTH  ((uint32_t)0x00000020)

#define SW_PROF_DATA_PTR_NAME_RST    0x0

__INLINE uint32_t sw_prof_data_ptr_name_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_DATA_PTR_NAME_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_data_ptr_name_setf(uint32_t dataptrname)
{
    ASSERT_ERR((((uint32_t)dataptrname << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(SW_PROF_DATA_PTR_NAME_ADDR, (uint32_t)dataptrname << 0);
}

/**
 * @brief DATA_PTR_TRACE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00       DATA_PTR_TRACE   0x0
 * </pre>
 */
#define SW_PROF_DATA_PTR_TRACE_ADDR   0x1000D11C
#define SW_PROF_DATA_PTR_TRACE_OFFSET 0x0000001C
#define SW_PROF_DATA_PTR_TRACE_INDEX  0x00000007
#define SW_PROF_DATA_PTR_TRACE_RESET  0x00000000

__INLINE uint32_t sw_prof_data_ptr_trace_get(void)
{
    return REG_PL_RD(SW_PROF_DATA_PTR_TRACE_ADDR);
}

__INLINE void sw_prof_data_ptr_trace_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_DATA_PTR_TRACE_ADDR, value);
}

// field definitions
#define SW_PROF_DATA_PTR_TRACE_MASK   ((uint32_t)0xFFFFFFFF)
#define SW_PROF_DATA_PTR_TRACE_LSB    0
#define SW_PROF_DATA_PTR_TRACE_WIDTH  ((uint32_t)0x00000020)

#define SW_PROF_DATA_PTR_TRACE_RST    0x0

__INLINE uint32_t sw_prof_data_ptr_trace_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_DATA_PTR_TRACE_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_data_ptr_trace_setf(uint32_t dataptrtrace)
{
    ASSERT_ERR((((uint32_t)dataptrtrace << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(SW_PROF_DATA_PTR_TRACE_ADDR, (uint32_t)dataptrtrace << 0);
}

/**
 * @brief MEM_PROTECT_CTRL register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:16     MEM_PROTECT_SIZE   0x0
 *     14   MEM_INIT_CLR_ACCESS   0
 *     13      MEM_READ_ACCESS   0
 *     12     MEM_WRITE_ACCESS   0
 *     08     MEM_GRANT_ACCESS   0
 *     03     MEM_INIT_CLR_SET   0
 *     02         MEM_READ_SET   0
 *     01        MEM_WRITE_SET   0
 *     00        MEM_GRANT_SET   0
 * </pre>
 */
#define SW_PROF_MEM_PROTECT_CTRL_ADDR   0x1000D120
#define SW_PROF_MEM_PROTECT_CTRL_OFFSET 0x00000020
#define SW_PROF_MEM_PROTECT_CTRL_INDEX  0x00000008
#define SW_PROF_MEM_PROTECT_CTRL_RESET  0x00000000

__INLINE uint32_t sw_prof_mem_protect_ctrl_get(void)
{
    return REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
}

__INLINE void sw_prof_mem_protect_ctrl_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, value);
}

// field definitions
#define SW_PROF_MEM_PROTECT_SIZE_MASK      ((uint32_t)0xFFFF0000)
#define SW_PROF_MEM_PROTECT_SIZE_LSB       16
#define SW_PROF_MEM_PROTECT_SIZE_WIDTH     ((uint32_t)0x00000010)
#define SW_PROF_MEM_INIT_CLR_ACCESS_BIT    ((uint32_t)0x00004000)
#define SW_PROF_MEM_INIT_CLR_ACCESS_POS    14
#define SW_PROF_MEM_READ_ACCESS_BIT        ((uint32_t)0x00002000)
#define SW_PROF_MEM_READ_ACCESS_POS        13
#define SW_PROF_MEM_WRITE_ACCESS_BIT       ((uint32_t)0x00001000)
#define SW_PROF_MEM_WRITE_ACCESS_POS       12
#define SW_PROF_MEM_GRANT_ACCESS_BIT       ((uint32_t)0x00000100)
#define SW_PROF_MEM_GRANT_ACCESS_POS       8
#define SW_PROF_MEM_INIT_CLR_SET_BIT       ((uint32_t)0x00000008)
#define SW_PROF_MEM_INIT_CLR_SET_POS       3
#define SW_PROF_MEM_READ_SET_BIT           ((uint32_t)0x00000004)
#define SW_PROF_MEM_READ_SET_POS           2
#define SW_PROF_MEM_WRITE_SET_BIT          ((uint32_t)0x00000002)
#define SW_PROF_MEM_WRITE_SET_POS          1
#define SW_PROF_MEM_GRANT_SET_BIT          ((uint32_t)0x00000001)
#define SW_PROF_MEM_GRANT_SET_POS          0

#define SW_PROF_MEM_PROTECT_SIZE_RST       0x0
#define SW_PROF_MEM_INIT_CLR_ACCESS_RST    0x0
#define SW_PROF_MEM_READ_ACCESS_RST        0x0
#define SW_PROF_MEM_WRITE_ACCESS_RST       0x0
#define SW_PROF_MEM_GRANT_ACCESS_RST       0x0
#define SW_PROF_MEM_INIT_CLR_SET_RST       0x0
#define SW_PROF_MEM_READ_SET_RST           0x0
#define SW_PROF_MEM_WRITE_SET_RST          0x0
#define SW_PROF_MEM_GRANT_SET_RST          0x0

__INLINE void sw_prof_mem_protect_ctrl_pack(uint16_t memprotectsize, uint8_t meminitclraccess, uint8_t memreadaccess, uint8_t memwriteaccess, uint8_t memgrantaccess, uint8_t meminitclrset, uint8_t memreadset, uint8_t memwriteset, uint8_t memgrantset)
{
    ASSERT_ERR((((uint32_t)memprotectsize << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    ASSERT_ERR((((uint32_t)meminitclraccess << 14) & ~((uint32_t)0x00004000)) == 0);
    ASSERT_ERR((((uint32_t)memreadaccess << 13) & ~((uint32_t)0x00002000)) == 0);
    ASSERT_ERR((((uint32_t)memwriteaccess << 12) & ~((uint32_t)0x00001000)) == 0);
    ASSERT_ERR((((uint32_t)memgrantaccess << 8) & ~((uint32_t)0x00000100)) == 0);
    ASSERT_ERR((((uint32_t)meminitclrset << 3) & ~((uint32_t)0x00000008)) == 0);
    ASSERT_ERR((((uint32_t)memreadset << 2) & ~((uint32_t)0x00000004)) == 0);
    ASSERT_ERR((((uint32_t)memwriteset << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)memgrantset << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR,  ((uint32_t)memprotectsize << 16) | ((uint32_t)meminitclraccess << 14) | ((uint32_t)memreadaccess << 13) | ((uint32_t)memwriteaccess << 12) | ((uint32_t)memgrantaccess << 8) | ((uint32_t)meminitclrset << 3) | ((uint32_t)memreadset << 2) | ((uint32_t)memwriteset << 1) | ((uint32_t)memgrantset << 0));
}

__INLINE void sw_prof_mem_protect_ctrl_unpack(uint16_t* memprotectsize, uint8_t* meminitclraccess, uint8_t* memreadaccess, uint8_t* memwriteaccess, uint8_t* memgrantaccess, uint8_t* meminitclrset, uint8_t* memreadset, uint8_t* memwriteset, uint8_t* memgrantset)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);

    *memprotectsize = (localVal & ((uint32_t)0xFFFF0000)) >> 16;
    *meminitclraccess = (localVal & ((uint32_t)0x00004000)) >> 14;
    *memreadaccess = (localVal & ((uint32_t)0x00002000)) >> 13;
    *memwriteaccess = (localVal & ((uint32_t)0x00001000)) >> 12;
    *memgrantaccess = (localVal & ((uint32_t)0x00000100)) >> 8;
    *meminitclrset = (localVal & ((uint32_t)0x00000008)) >> 3;
    *memreadset = (localVal & ((uint32_t)0x00000004)) >> 2;
    *memwriteset = (localVal & ((uint32_t)0x00000002)) >> 1;
    *memgrantset = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE uint16_t sw_prof_mem_protect_size_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0xFFFF0000)) >> 16);
}

__INLINE void sw_prof_mem_protect_size_setf(uint16_t memprotectsize)
{
    ASSERT_ERR((((uint32_t)memprotectsize << 16) & ~((uint32_t)0xFFFF0000)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0xFFFF0000)) | ((uint32_t)memprotectsize << 16));
}

__INLINE uint8_t sw_prof_mem_init_clr_access_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00004000)) >> 14);
}

__INLINE void sw_prof_mem_init_clr_access_setf(uint8_t meminitclraccess)
{
    ASSERT_ERR((((uint32_t)meminitclraccess << 14) & ~((uint32_t)0x00004000)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0x00004000)) | ((uint32_t)meminitclraccess << 14));
}

__INLINE uint8_t sw_prof_mem_read_access_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00002000)) >> 13);
}

__INLINE void sw_prof_mem_read_access_setf(uint8_t memreadaccess)
{
    ASSERT_ERR((((uint32_t)memreadaccess << 13) & ~((uint32_t)0x00002000)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0x00002000)) | ((uint32_t)memreadaccess << 13));
}

__INLINE uint8_t sw_prof_mem_write_access_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00001000)) >> 12);
}

__INLINE void sw_prof_mem_write_access_setf(uint8_t memwriteaccess)
{
    ASSERT_ERR((((uint32_t)memwriteaccess << 12) & ~((uint32_t)0x00001000)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0x00001000)) | ((uint32_t)memwriteaccess << 12));
}

__INLINE uint8_t sw_prof_mem_grant_access_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000100)) >> 8);
}

__INLINE void sw_prof_mem_grant_access_setf(uint8_t memgrantaccess)
{
    ASSERT_ERR((((uint32_t)memgrantaccess << 8) & ~((uint32_t)0x00000100)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0x00000100)) | ((uint32_t)memgrantaccess << 8));
}

__INLINE uint8_t sw_prof_mem_init_clr_set_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000008)) >> 3);
}

__INLINE void sw_prof_mem_init_clr_set_setf(uint8_t meminitclrset)
{
    ASSERT_ERR((((uint32_t)meminitclrset << 3) & ~((uint32_t)0x00000008)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0x00000008)) | ((uint32_t)meminitclrset << 3));
}

__INLINE uint8_t sw_prof_mem_read_set_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000004)) >> 2);
}

__INLINE void sw_prof_mem_read_set_setf(uint8_t memreadset)
{
    ASSERT_ERR((((uint32_t)memreadset << 2) & ~((uint32_t)0x00000004)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0x00000004)) | ((uint32_t)memreadset << 2));
}

__INLINE uint8_t sw_prof_mem_write_set_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000002)) >> 1);
}

__INLINE void sw_prof_mem_write_set_setf(uint8_t memwriteset)
{
    ASSERT_ERR((((uint32_t)memwriteset << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)memwriteset << 1));
}

__INLINE uint8_t sw_prof_mem_grant_set_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR);
    return ((localVal & ((uint32_t)0x00000001)) >> 0);
}

__INLINE void sw_prof_mem_grant_set_setf(uint8_t memgrantset)
{
    ASSERT_ERR((((uint32_t)memgrantset << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_CTRL_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_CTRL_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)memgrantset << 0));
}

/**
 * @brief MEM_PROTECT_ADDR register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  31:00     MEM_PROTECT_ADDR   0x0
 * </pre>
 */
#define SW_PROF_MEM_PROTECT_ADDR_ADDR   0x1000D124
#define SW_PROF_MEM_PROTECT_ADDR_OFFSET 0x00000024
#define SW_PROF_MEM_PROTECT_ADDR_INDEX  0x00000009
#define SW_PROF_MEM_PROTECT_ADDR_RESET  0x00000000

__INLINE uint32_t sw_prof_mem_protect_addr_get(void)
{
    return REG_PL_RD(SW_PROF_MEM_PROTECT_ADDR_ADDR);
}

__INLINE void sw_prof_mem_protect_addr_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_MEM_PROTECT_ADDR_ADDR, value);
}

// field definitions
#define SW_PROF_MEM_PROTECT_ADDR_MASK   ((uint32_t)0xFFFFFFFF)
#define SW_PROF_MEM_PROTECT_ADDR_LSB    0
#define SW_PROF_MEM_PROTECT_ADDR_WIDTH  ((uint32_t)0x00000020)

#define SW_PROF_MEM_PROTECT_ADDR_RST    0x0

__INLINE uint32_t sw_prof_mem_protect_addr_getf(void)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_ADDR_ADDR);
    ASSERT_ERR((localVal & ~((uint32_t)0xFFFFFFFF)) == 0);
    return (localVal >> 0);
}

__INLINE void sw_prof_mem_protect_addr_setf(uint32_t memprotectaddr)
{
    ASSERT_ERR((((uint32_t)memprotectaddr << 0) & ~((uint32_t)0xFFFFFFFF)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_ADDR_ADDR, (uint32_t)memprotectaddr << 0);
}

/**
 * @brief MEM_PROTECT_ISR_STATE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *     01   MEM_PROTECT_ISR_EXIT   0
 *     00   MEM_PROTECT_ISR_ENTER   0
 * </pre>
 */
#define SW_PROF_MEM_PROTECT_ISR_STATE_ADDR   0x1000D128
#define SW_PROF_MEM_PROTECT_ISR_STATE_OFFSET 0x00000028
#define SW_PROF_MEM_PROTECT_ISR_STATE_INDEX  0x0000000A
#define SW_PROF_MEM_PROTECT_ISR_STATE_RESET  0x00000000

__INLINE uint32_t sw_prof_mem_protect_isr_state_get(void)
{
    return REG_PL_RD(SW_PROF_MEM_PROTECT_ISR_STATE_ADDR);
}

__INLINE void sw_prof_mem_protect_isr_state_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_MEM_PROTECT_ISR_STATE_ADDR, value);
}

// field definitions
#define SW_PROF_MEM_PROTECT_ISR_EXIT_BIT     ((uint32_t)0x00000002)
#define SW_PROF_MEM_PROTECT_ISR_EXIT_POS     1
#define SW_PROF_MEM_PROTECT_ISR_ENTER_BIT    ((uint32_t)0x00000001)
#define SW_PROF_MEM_PROTECT_ISR_ENTER_POS    0

#define SW_PROF_MEM_PROTECT_ISR_EXIT_RST     0x0
#define SW_PROF_MEM_PROTECT_ISR_ENTER_RST    0x0

__INLINE void sw_prof_mem_protect_isr_state_pack(uint8_t memprotectisrexit, uint8_t memprotectisrenter)
{
    ASSERT_ERR((((uint32_t)memprotectisrexit << 1) & ~((uint32_t)0x00000002)) == 0);
    ASSERT_ERR((((uint32_t)memprotectisrenter << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_ISR_STATE_ADDR,  ((uint32_t)memprotectisrexit << 1) | ((uint32_t)memprotectisrenter << 0));
}

__INLINE void sw_prof_mem_protect_isr_state_unpack(uint8_t* memprotectisrexit, uint8_t* memprotectisrenter)
{
    uint32_t localVal = REG_PL_RD(SW_PROF_MEM_PROTECT_ISR_STATE_ADDR);

    *memprotectisrexit = (localVal & ((uint32_t)0x00000002)) >> 1;
    *memprotectisrenter = (localVal & ((uint32_t)0x00000001)) >> 0;
}

__INLINE void sw_prof_mem_protect_isr_exit_setf(uint8_t memprotectisrexit)
{
    ASSERT_ERR((((uint32_t)memprotectisrexit << 1) & ~((uint32_t)0x00000002)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_ISR_STATE_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_ISR_STATE_ADDR) & ~((uint32_t)0x00000002)) | ((uint32_t)memprotectisrexit << 1));
}

__INLINE void sw_prof_mem_protect_isr_enter_setf(uint8_t memprotectisrenter)
{
    ASSERT_ERR((((uint32_t)memprotectisrenter << 0) & ~((uint32_t)0x00000001)) == 0);
    REG_PL_WR(SW_PROF_MEM_PROTECT_ISR_STATE_ADDR, (REG_PL_RD(SW_PROF_MEM_PROTECT_ISR_STATE_ADDR) & ~((uint32_t)0x00000001)) | ((uint32_t)memprotectisrenter << 0));
}

/**
 * @brief DATA_PTR_LINE register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  15:00        DATA_PTR_LINE   0x0
 * </pre>
 */
#define SW_PROF_DATA_PTR_LINE_ADDR   0x1000D12C
#define SW_PROF_DATA_PTR_LINE_OFFSET 0x0000002C
#define SW_PROF_DATA_PTR_LINE_INDEX  0x0000000B
#define SW_PROF_DATA_PTR_LINE_RESET  0x00000000

__INLINE void sw_prof_data_ptr_line_set(uint32_t value)
{
    REG_PL_WR(SW_PROF_DATA_PTR_LINE_ADDR, value);
}

// field definitions
#define SW_PROF_DATA_PTR_LINE_MASK   ((uint32_t)0x0000FFFF)
#define SW_PROF_DATA_PTR_LINE_LSB    0
#define SW_PROF_DATA_PTR_LINE_WIDTH  ((uint32_t)0x00000010)

#define SW_PROF_DATA_PTR_LINE_RST    0x0

__INLINE void sw_prof_data_ptr_line_setf(uint16_t dataptrline)
{
    ASSERT_ERR((((uint32_t)dataptrline << 0) & ~((uint32_t)0x0000FFFF)) == 0);
    REG_PL_WR(SW_PROF_DATA_PTR_LINE_ADDR, (uint32_t)dataptrline << 0);
}


#endif // _REG_SW_PROFILING_H_

