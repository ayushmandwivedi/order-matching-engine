cmake_minimum_required(VERSION 3.20)
project(OrderMatchingEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Optimization and warning flags
add_compile_options(-Wall -Wextra -Wpedantic -O3)

include_directories(include)

# Executable
add_executable(matching_engine src/main.cpp)