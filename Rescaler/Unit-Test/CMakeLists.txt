cmake_minimum_required(VERSION 3.14)
project(COMMON_LIB_RESCALER_GTEST)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

########################################
# GTEST stuff
#
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#########################################
# Setup files and directories
#
set(RESCALER_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_subdirectory(${RESCALER_DIR} common_lib_rescaler_bld)

list(APPEND LINK_LIBRARIES
  COMMON_LIB_INT_RESCALER
)

list(APPEND INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${RESCALER_DIR}
)

list(APPEND SOURCES
  IntegerRescaler-test.cpp
)

########################################
# Setup project
#
add_executable(COMMON_LIB_RESCALER_GTEST
  ${SOURCES}
)

target_include_directories(COMMON_LIB_RESCALER_GTEST PUBLIC
  ${INCLUDE_DIRS}
)

target_link_libraries(COMMON_LIB_RESCALER_GTEST PUBLIC
  ${LINK_LIBRARIES}
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(COMMON_LIB_RESCALER_GTEST)
