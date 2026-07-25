add_library(src OBJECT)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_sources(src
    PRIVATE
        types.cpp
        ops.cpp
        factors.cpp
)

target_link_libraries(src
    PUBLIC
        include
)
