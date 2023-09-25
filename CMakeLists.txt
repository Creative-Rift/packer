## CMAKE VAR
## <=====================================>
cmake_minimum_required( VERSION 3.17...3.22 )
set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/ )
## <=====================================>

project( "SW Packer"
        VERSION
        1.1
        DESCRIPTION
        "Pack all resources into one file"
        LANGUAGES
        CXX
        )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/${CMAKE_PROJECT_VERSION} )
set( PREFIX_MESSAGE "[${PROJECT_NAME}] ")

## <=====================================>

message(${PREFIX_MESSAGE} "Build type set to: " ${CMAKE_BUILD_TYPE})
message(${PREFIX_MESSAGE} "Current cmake location: " ${CMAKE_CURRENT_SOURCE_DIR})
message(${PREFIX_MESSAGE} "Project location: " ${CMAKE_SOURCE_DIR})
message(${PREFIX_MESSAGE} "Project system: " ${CMAKE_SYSTEM_NAME})

option(SWFP_COMP "Define if the packer will enable compact process" )

## IMPORTED STATIC LIBRARY NAME
set( STATIC_LIB_NAME
        )

## IMPORTED STATIC LIBRARY .lib file
set( STATIC_LIB
        )

list(LENGTH STATIC_LIB_NAME  list_len)
math(EXPR LIST_LEN "${list_len} - 1")

if (${LIST_LEN} GREATER_EQUAL 0)

    foreach(ctr RANGE ${LIST_LEN})
        list(GET STATIC_LIB_NAME ${ctr} lib)
        list(GET STATIC_LIB ${ctr} filelib)
        add_library(${lib} STATIC IMPORTED)
        set_target_properties(${lib} PROPERTIES
                IMPORTED_LOCATION ${filelib}
        )
    endforeach()
endif ()

include(cmake/Packer.cmake)
include(cmake/UnPacker.cmake)