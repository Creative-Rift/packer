## CMAKE VAR
## <=====================================>
cmake_minimum_required( VERSION 3.20 )
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
## <=====================================>

project( "SW Packer"
        VERSION
        0.1
        DESCRIPTION
        "Pack all resources into one file"
        )

set(PREFIX_MESSAGE "[SWEngine-Packer] ")

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/file/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/pack/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/unpack/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/file/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/pack/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/unpack/
        )

message(${PREFIX_MESSAGE} "Build type set to: " ${CMAKE_BUILD_TYPE})
message(${PREFIX_MESSAGE} "Current cmake location: " ${CMAKE_CURRENT_SOURCE_DIR})
message(${PREFIX_MESSAGE} "Project location: " ${CMAKE_SOURCE_DIR})


if (WIN32)
    message(${PREFIX_MESSAGE} "Windows system detected, prepare project...")
    include(.cmake_windows.cmake)
else()
    message(FATAL_ERROR "System not supported!")
endif()