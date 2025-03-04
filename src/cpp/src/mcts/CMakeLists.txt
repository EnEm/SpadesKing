set(SOURCES
    node.cpp
    playout.cpp
    search.cpp
    tree.cpp
)

add_library(mcts ${SOURCES})

target_include_directories(mcts PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(mcts PUBLIC
    ${CMAKE_SOURCE_DIR}/include/src/mcts
)