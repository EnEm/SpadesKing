add_executable(game_demo game_demo.cpp)
add_executable(training_demo training_demo.cpp)
add_executable(bot_demo bot_demo.cpp)

target_link_libraries(game_demo PRIVATE spades)
target_link_libraries(training_demo PRIVATE bot)
target_link_libraries(bot_demo PRIVATE bot)