## PROJECT VAR
## <=====================================>
set( EXEC "SWEngine-unpacker_${CMAKE_PROJECT_VERSION}" )
set( EXT cpp )
## <=====================================>

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/file/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/unpack/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/file/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/unpack/
        )

## GET SOURCES
## <=====================================>
set(TMP "")
foreach(filePath ${SRC_FOLDERS})
    string(APPEND TMP "${filePath}*.${EXT};")
endforeach()
file(GLOB SRC ${TMP})
## <=====================================>


## OUTPUT
## <=====================================>
## EXECUTABLE
add_executable(${EXEC} ${SRC})
## <=====================================>

target_compile_definitions(${EXEC} PUBLIC "SWFP_UNPACKER")

## ADD INCLUDES
## <=====================================>
target_include_directories(${EXEC} PUBLIC ${INC_FOLDERS})
## <=====================================>

## ADD PARAMETER
## <=====================================>
if(MSVC)
    target_compile_options(${EXEC} PRIVATE "/MP")
endif()
## <=====================================>

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set_target_properties(${EXEC} PROPERTIES
            DEBUG_POSTFIX "d")
endif()