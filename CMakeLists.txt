#/**********************************************************\ 
# 
# Auto-generated CMakeLists.txt for the CpABEPlugin project
#
#\**********************************************************/

# Written to work with cmake 2.6
cmake_minimum_required (VERSION 2.6)
set (CMAKE_BACKWARDS_COMPATIBILITY 2.6)

Project(${PLUGIN_NAME})

file (GLOB GENERAL RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    [^.]*.cpp
    [^.]*.h
    [^.]*.cmake
    )

include_directories(${PLUGIN_INCLUDE_DIRS})

#find_library(GLIB_LIBRARY glib-2.0)
#find_library(GMP_LIBRARY gmp)
#find_library(CRYPTO_LIBRARY crypto)
#find_library(PBC_LIBRARY pbc)
#find_library(BSWABE_LIBRARY bswabe)

set(ABE_INCLUDE_DIRS
    /usr/include/glib-2.0
    /usr/lib/x86_64-linux-gnu/glib-2.0/include
    )

include_directories(${ABE_INCLUDE_DIRS})




# Generated files are stored in ${GENERATED} by the project configuration
SET_SOURCE_FILES_PROPERTIES(
    ${GENERATED}
    PROPERTIES
        GENERATED 1
    )

SOURCE_GROUP(Generated FILES
    ${GENERATED}
    )

SET( SOURCES
    ${GENERAL}
    ${GENERATED}
    )

# This will include Win/projectDef.cmake, X11/projectDef.cmake, Mac/projectDef 
# depending on the platform
include_platform()

#this will build a Chrome package
#add_chrome_package(${PLUGIN_NAME}
#	${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/ 
#	"${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/${FBSTRING_PluginFileName}.dll"
#	"${CMAKE_CURRENT_SOURCE_DIR}/sign/package_key.pem"
#	${PROJECT_NAME})

#this will build a XPI package using XPISigner (see http://code.google.com/p/xpisigner/ )
# add_signed_xpi_installer(${PLUGIN_NAME}
# 	${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/ 
#   "${FB_BIN_DIR}/${PLUGIN_NAME}/${CMAKE_CFG_INTDIR}/${FBSTRING_PluginFileName}.dll"
# 	$ENV{XPI_PATH} 
# 	"${CMAKE_CURRENT_SOURCE_DIR}/sign/certificate.pfx" 
# 	"${CMAKE_CURRENT_SOURCE_DIR}/sign/passphrase.txt"
# 	${PROJECT_NAME})

#target_link_libraries(${PLUGIN_NAME} GLIB_LIBRARY GMP_LIBRARY CRYPTO_LIBRARY PBC_LIBRARY BSWABE_LIBRARY)

add_library(abecommon STATIC ${CMAKE_CURRENT_SOURCE_DIR}/common.c)

target_link_libraries(${PLUGIN_NAME} glib-2.0 gmp crypto pbc ${CMAKE_CURRENT_SOURCE_DIR}/libbswabe.a abecommon)
