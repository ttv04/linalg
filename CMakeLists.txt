cmake_minimum_required(VERSION 3.23)

enable_testing()

project(linalg)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(include/linalg)
add_subdirectory(src)

add_library(linalg STATIC)

# PUBLIC so dependents (e.g. main) get headers from `include`
# and object code from `src`
target_link_libraries(linalg
    PUBLIC
        include
        src
)

add_subdirectory(tests)
