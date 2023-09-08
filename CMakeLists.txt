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
        0.1
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
set(PREFIX_MESSAGE "[${PROJECT_NAME}] ")

## <=====================================>

message(${PREFIX_MESSAGE} "Build type set to: " ${CMAKE_BUILD_TYPE})
message(${PREFIX_MESSAGE} "Current cmake location: " ${CMAKE_CURRENT_SOURCE_DIR})
message(${PREFIX_MESSAGE} "Project location: " ${CMAKE_SOURCE_DIR})
message(${PREFIX_MESSAGE} "Project system: " ${CMAKE_SYSTEM_NAME})


include(cmake/Packer.cmake)
include(cmake/UnPacker.cmake)
