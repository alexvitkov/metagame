cmake_minimum_required(VERSION 3.20)

project(metagame)

add_executable(meta 
  src/Actor.cpp
  src/Allocator.cpp
  src/Debug.cpp
  src/Main.cpp
  src/Libc.cpp
  src/Ostream.cpp
  src/Renderer.cpp
  src/Vector3.cpp
)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O2 -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

  add_definitions(-DACTOR_ADD_CHILD_CALLBACK)

target_include_directories(meta PRIVATE ./include)

add_custom_command(
  TARGET meta
  POST_BUILD
  COMMAND python ../wasm-sourcemap.py --dwarfdump /usr/bin/llvm-dwarfdump -w ${CMAKE_CURRENT_SOURCE_DIR}/../dist/meta.wasm --source-map-url meta.wasm.map -o ${CMAKE_CURRENT_SOURCE_DIR}/../dist/meta.wasm.map meta

)

