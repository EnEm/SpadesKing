include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(card_test spades_tests/card_test.cpp)

target_link_libraries(card_test PRIVATE spades gtest gtest_main)

add_test(NAME SpadesTest COMMAND card_test)