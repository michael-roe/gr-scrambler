find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_SCRAMBLER gnuradio-scrambler)

FIND_PATH(
    GR_SCRAMBLER_INCLUDE_DIRS
    NAMES gnuradio/scrambler/api.h
    HINTS $ENV{SCRAMBLER_DIR}/include
        ${PC_SCRAMBLER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_SCRAMBLER_LIBRARIES
    NAMES gnuradio-scrambler
    HINTS $ENV{SCRAMBLER_DIR}/lib
        ${PC_SCRAMBLER_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-scramblerTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_SCRAMBLER DEFAULT_MSG GR_SCRAMBLER_LIBRARIES GR_SCRAMBLER_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_SCRAMBLER_LIBRARIES GR_SCRAMBLER_INCLUDE_DIRS)
