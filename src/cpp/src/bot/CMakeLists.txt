set(SOURCES
    decision.cpp
    hybrid.cpp
    style.cpp
)

add_library(bot ${SOURCES})

target_include_directories(bot PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(bot PUBLIC
    ${CMAKE_SOURCE_DIR}/include/src/bot
)

target_link_libraries(bot PRIVATE spades mcts neat)