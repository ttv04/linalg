add_library(include INTERFACE)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_sources(include
    INTERFACE
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/..
        FILES
            types.hpp
            ops.hpp
            factors.hpp
            solvers.hpp
)
