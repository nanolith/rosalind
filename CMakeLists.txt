cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0048 NEW)
PROJECT(rosalind VERSION 0.0.1 LANGUAGES C CXX)

INCLUDE(CheckSymbolExists)

#pkgconfig
find_package(PkgConfig REQUIRED)
#minunit package
pkg_search_module(minunit REQUIRED IMPORTED_TARGET minunit)

#Build config.h
configure_file(compile_opts.h.cmake include/rosalind_bootstrap/compile_opts.h)

#source files
file(GLOB_RECURSE ROSALIND_BOOTSTRAP_SOURCES src/bootstrap/*.c)
list(
    FILTER ROSALIND_BOOTSTRAP_SOURCES
    EXCLUDE REGEX ".*/main[.]c")
file(GLOB ROSALIND_BOOTSTRAP_SOURCES_MAIN src/bootstrap/main.c)

#test files
file(GLOB_RECURSE ROSALIND_BOOTSTRAP_TEST_SOURCES test/bootstrap/*.cpp)

include_directories(include)
include_directories(${CMAKE_BINARY_DIR}/include)

ADD_EXECUTABLE(
    rcc-stage0 ${ROSALIND_BOOTSTRAP_SOURCES} ${ROSALIND_BOOTSTRAP_SOURCES_MAIN})
TARGET_COMPILE_OPTIONS(
    rcc-stage0 PRIVATE -fPIC -O2
    -Wall -Werror -Wextra -Wpedantic)

ADD_EXECUTABLE(testbootstrap
    ${ROSALIND_BOOTSTRAP_SOURCES} ${ROSALIND_BOOTSTRAP_TEST_SOURCES})
TARGET_COMPILE_OPTIONS(
    testbootstrap PRIVATE -g -O0 --coverage ${minunit_CFLAGS}
                       -Wall -Werror -Wextra -Wpedantic)
TARGET_LINK_OPTIONS(testbootstrap PRIVATE --coverage)
TARGET_LINK_LIBRARIES(
    testbootstrap PRIVATE -g -O0 --coverage PkgConfig::minunit)
SET_SOURCE_FILES_PROPERTIES(
    ${ROSALIND_BOOTSTRAP_TEST_SOURCES} PROPERTIES
    COMPILE_FLAGS "${STD_CXX_20}")

ADD_CUSTOM_TARGET(
    test
    COMMAND testbootstrap
    DEPENDS testbootstrap
    USES_TERMINAL)
