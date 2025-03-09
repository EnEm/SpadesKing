include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.16.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(googletest)

add_executable(spades_test spades_test.cpp)

target_link_libraries(spades_test PRIVATE spades gtest gtest_main)

add_test(NAME SpadesTest COMMAND spades_test)