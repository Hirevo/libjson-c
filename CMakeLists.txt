
cmake_minimum_required(VERSION 3.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -W -Wall -Wextra -Wunused -Wuninitialized")

add_library(json STATIC
    src/clear.c
    src/is.c
    src/item.c
    src/json.c
    src/pack.c
    src/remove_comments.c
    src/trim.c
    src/parse/base.c
    src/parse/list.c
    src/parse/parse.c
    src/parse/types.c
    src/serialize/base.c
    src/serialize/object.c
)
target_include_directories(json PUBLIC src)
add_dependencies(json vec hmap str)
target_link_libraries(json vec hmap str)
