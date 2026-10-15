cmake_minimum_required(VERSION 3.10)

project(render_training)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(tst test/tst.cpp)
target_include_directories(tst PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
