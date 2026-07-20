cmake_minimum_required(VERSION 3.23)

project(linalg)

add_subdirectory(include/linalg)
add_subdirectory(src)
# add_subdirectory(tests)

add_library(linalg STATIC)

# PUBLIC so dependents (e.g. main) get headers from `include`
# and object code from `src`
target_link_libraries(linalg
    PUBLIC
        include
        src
)
