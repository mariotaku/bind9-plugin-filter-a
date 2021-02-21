cmake_minimum_required (VERSION 3.10)
project(bind9-plugin-filter-a
    VERSION 9.16.11
    LANGUAGES C
)

find_library(BIND9_LIB libbind9.so)
get_filename_component(BIND9_LIBDIR ${BIND9_LIB} DIRECTORY)
find_file(FILTER_AAAA_LIB filter-aaaa.so ${BIND9_LIBDIR})
get_filename_component(BIND9_PLUGIN_DIR ${FILTER_AAAA_LIB} DIRECTORY)
message(${BIND9_PLUGIN_DIR})

add_library(filter-a SHARED filter-a.c)
set_target_properties(filter-a PROPERTIES PREFIX "")

install(TARGETS filter-a
    LIBRARY DESTINATION ${BIND9_PLUGIN_DIR}
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Mariotaku Lee")
SET(CPACK_DEBIAN_PACKAGE_DEPENDS "bind9 (>= 9.16)")
INCLUDE(CPack)