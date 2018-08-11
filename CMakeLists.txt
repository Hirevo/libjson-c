
cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra -Wunused -Wuninitialized -O3")

add_library(json STATIC
    src/clear
    src/is
    src/json
    src/pack
    src/remove_comments
    src/trim
    src/parse/base
    src/parse/list
    src/parse/parse
    src/parse/types
    src/serialize/base
    src/serialize/object)

target_include_directories(json PRIVATE "../vec/src")
target_include_directories(json PRIVATE "../hmap/src")
target_include_directories(json PRIVATE "../str/src")
