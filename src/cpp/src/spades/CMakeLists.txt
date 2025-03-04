set(SOURCES
    card.cpp
    player.cpp
    trick.cpp
    round.cpp
    match.cpp
    game.cpp
    team.cpp
)

add_library(spades ${SOURCES})

target_include_directories(spades PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(spades PUBLIC
    ${CMAKE_SOURCE_DIR}/include/src/spades
)