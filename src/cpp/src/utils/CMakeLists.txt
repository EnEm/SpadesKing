set(SOURCES
    config.cpp
    random.cpp
    stats.cpp
)

add_library(utils ${SOURCES})

target_include_directories(utils PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(utils PUBLIC
    ${CMAKE_SOURCE_DIR}/include/src/utils
)