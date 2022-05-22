cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(data_structure)

set(CMAKE_DEBUG_POSTFIX d)

set(CXX_FLAGS
    -g
    # -DVALGRIND
    -DCHECK_PTHREAD_RETURN_VALUE
    -D_FILE_OFFSET_BITS=64
    -Wall
    -Wextra
    -Werror
    -Wconversion
    -Wno-unused-parameter
    -Wold-style-cast
    -Woverloaded-virtual
    -Wpointer-arith
    -Wshadow
    -Wwrite-strings
    -march=native
    # -MMD
    -rdynamic
    )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

# 设置生成文件输出路径
set(EXECUTABLE_OUTPUT_PATH, ./output/debug/bin)
add_executable(data_structure ./main/heap_test.cc)

target_include_directories(data_structure PUBLIC ./inc/)
target_include_directories(data_structure PRIVATE ./extern_inc/)

target_link_directories(data_structure PRIVATE ./lib/debug/)

target_link_libraries(data_structure PRIVATE gtest)
target_link_libraries(data_structure PRIVATE pthread)
include(src/CMakeLists.txt)

