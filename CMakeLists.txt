cmake_minimum_required(VERSION 3.15)

project(RocketStateMachine VERSION 0.1)
enable_testing()
add_compile_definitions(TESTING)

include_directories(PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory(Rocket)