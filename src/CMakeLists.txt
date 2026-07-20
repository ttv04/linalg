add_library(src OBJECT)

target_sources(src
    PRIVATE
        types.cpp
)

target_link_libraries(src
    PUBLIC
        include
)
