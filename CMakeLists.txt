cmake_minimum_required(VERSION 3.20)
project(OrderMatchingEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic -O3)

include_directories(include)

# Primary Engine Target
add_executable(matching_engine src/main.cpp)

# Test Targets
add_executable(test_price_level tests/test_price_level.cpp)