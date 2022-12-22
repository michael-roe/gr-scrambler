INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SCRAMBLER scrambler)

FIND_PATH(
    SCRAMBLER_INCLUDE_DIRS
    NAMES scrambler/api.h
    HINTS $ENV{SCRAMBLER_DIR}/include
        ${PC_SCRAMBLER_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SCRAMBLER_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/scramblerTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SCRAMBLER DEFAULT_MSG SCRAMBLER_LIBRARIES SCRAMBLER_INCLUDE_DIRS)
MARK_AS_ADVANCED(SCRAMBLER_LIBRARIES SCRAMBLER_INCLUDE_DIRS)
