## PROJECT VAR
## <=====================================>
unset(EXEC)
set( EXEC "SWEngine-packer_${CMAKE_PROJECT_VERSION}" )
set( EXT cpp )
## <=====================================>

## SOURCE FOLDERS
set( SRC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/file/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/pack/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/log/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/exception/
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/utils/
        )
## INCLUDE FOLDERS
set( INC_FOLDERS
        ${CMAKE_CURRENT_SOURCE_DIR}/libraries/

        ${CMAKE_CURRENT_SOURCE_DIR}/includes/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/file/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/pack/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/log/
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/exception/
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

target_compile_definitions(${EXEC} PUBLIC "SWFP_PACKER")
if (${SWFP_COMP})
    message(${PREFIX_MESSAGE} "Compression process enabled!")
    target_compile_definitions(${EXEC} PUBLIC "SWFP_COMP")
endif ()

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

## IMPORTED STATIC LIBRARY NAME
set( STATIC_LIB_NAME
        zstd_static
        )

## IMPORTED STATIC LIBRARY .lib file
set( STATIC_LIB
        ${CMAKE_SOURCE_DIR}/libraries/zstd_static.lib
        )

## STATIC LIBRARY LINKING
## <=====================================>
target_link_libraries(${EXEC}
        PUBLIC
        ${STATIC_LIB_NAME}
)
## <=====================================>

if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    set_target_properties(${EXEC} PROPERTIES
            DEBUG_POSTFIX "d")
endif()