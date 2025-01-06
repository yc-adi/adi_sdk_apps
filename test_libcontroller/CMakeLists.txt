# Copyright (c) 2024 Analog Devices, Inc. All Rights Reserved.
# This software is proprietary to Analog Devices, Inc. and its licensors.
# Released under the terms of the "LICENSE.md" file in the root directory.

cmake_minimum_required(VERSION 3.22)

include($ENV{ADI_SDK}/cmake/sdk.cmake)

# Extract the folder name to use as the project name 
get_filename_component(PROJECT_FOLDER_NAME ${CMAKE_SOURCE_DIR} NAME)

project(
    ${PROJECT_FOLDER_NAME}
    VERSION 1.0
    LANGUAGES C CXX ASM
)

add_executable(
    ${CMAKE_PROJECT_NAME}.elf
    main.c
)

# Add include directories
target_include_directories(${CMAKE_PROJECT_NAME}.elf PRIVATE
    ${CMAKE_SOURCE_DIR}/plf/hudson/reg_inc
    ${CMAKE_SOURCE_DIR}/plf/hudson
)

# Link libcontroller.a
target_link_libraries(${CMAKE_PROJECT_NAME}.elf ${CMAKE_SOURCE_DIR}/plf/hudson/libcontroller.a)

set(CMAKE_BUILD_TYPE Debug)
set_target_properties(${CMAKE_PROJECT_NAME}.elf PROPERTIES LINK_FLAGS "-Wl,-Map=${CMAKE_PROJECT_NAME}.map")

if(CONFIG_TEST_OPTION)
    message("CONFIG_TEST_OPTION enabled")
endif()
