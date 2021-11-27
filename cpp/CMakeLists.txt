cmake_minimum_required(VERSION 3.20)

project(metagame)

add_executable(meta 
  src/Allocator.cpp
  src/main.cpp
)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O2 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

target_include_directories(meta PRIVATE ./include)

add_custom_command(
  TARGET meta
  POST_BUILD
  COMMAND cp meta ${CMAKE_CURRENT_SOURCE_DIR}/../dist/meta.wasm
)
