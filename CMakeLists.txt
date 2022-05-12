cmake_minimum_required(VERSION 3.13)

project(GramSymSpell VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

include_directories("include")

file(GLOB SRCS src/*.cpp include/*.h)

add_library(edit_distance STATIC ${SRCS})

enable_testing()

file(GLOB TST_SRCS test/*.cpp include/*.h)

add_executable(
  edit_distance_test
  ${TST_SRCS}
)

target_link_libraries(
  edit_distance_test
  edit_distance
  gmock
  gtest_main
  dictionary_generator
)

include(GoogleTest)
gtest_discover_tests(edit_distance_test)

# Vocabulary generator utility.

file(GLOB GENERATOR_SRCS src/generator/*.cpp)

add_executable(
  dictionary_generator
  ${GENERATOR_SRCS}
)