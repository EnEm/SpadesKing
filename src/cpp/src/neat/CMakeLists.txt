set(SOURCES
    evolution.cpp
    genome.cpp
    network.cpp
    species.cpp
)

add_library(neat ${SOURCES})

target_include_directories(neat PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(neat PUBLIC
    ${CMAKE_SOURCE_DIR}/include/src/neat
)