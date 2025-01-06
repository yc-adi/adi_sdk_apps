/*
 * Copyright (c) 2024 Analog Devices, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * @file
 * @brief  version information header file.
 */

#ifndef VERSION_H
#define VERSION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup PLF_VERSION
 *  \{ */

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/*! \brief      PLF Version structure. */
typedef struct
{
  uint8_t major;
  uint8_t minor;
  uint8_t patch;
  uint32_t commit;
  char *buildDate;
} PlfVersion_t;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

/*************************************************************************************************/
/*!
 *  \brief      Get versioning information.
 *
 *  \return     PLF Version structure.
 */
/*************************************************************************************************/
const PlfVersion_t *PlfGetVersion(void);

/*! \} */    /* PLF_VERSION */

#ifdef __cplusplus
};
#endif

#endif /* VERSION_H */
