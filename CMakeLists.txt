cmake_minimum_required(VERSION 3.16)
project(MontOlympiad CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(olympiad src/main.cpp)

# Include directories
target_include_directories(olympiad PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/external
)

# Copy data folder next to the executable after build
add_custom_command(TARGET olympiad POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/src/data
    $<TARGET_FILE_DIR:olympiad>/data
)
