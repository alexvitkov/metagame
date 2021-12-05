set(TARGET_TRIPLE wasm32-unknown-unknown)
set(COMMON_FLAGS "-ffreestanding -nostdlib -fno-rtti -fno-exceptions -fvisibility=hidden")
set(LD_FLAGS "--no-entry --initial-memory=5242880 --export-dynamic --export=__wasm_call_ctors")
set(LD "wasm-ld ${LD_FLAGS} <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_LINK_EXECUTABLE ${LD})
set(CMAKE_CXX_LINK_EXECUTABLE ${LD})

set(CMAKE_C_COMPILER_TARGET ${TARGET_TRIPLE})
set(CMAKE_CXX_COMPILER_TARGET ${TARGET_TRIPLE})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS}")
