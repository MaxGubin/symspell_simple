cmake_minimum_required(VERSION 3.13)

project(GramSymSpell)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)



add_subdirectory(suggestions)

#target_link_libraries(GramSymSpell PUBLIC SugggestionGenerator)