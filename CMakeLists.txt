cmake_minimum_required(VERSION 3.16)
project(MontOlympiad CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# main.cpp directly #includes the .cpp source files,
# so only main.cpp is listed here to avoid duplicate symbols.
add_executable(olympiad src/main.cpp)

target_include_directories(olympiad PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/src/external
)

# Copy data files next to the built executable so relative paths work at runtime.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/data
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
