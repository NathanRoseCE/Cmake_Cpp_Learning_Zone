add_library(Timer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Timer/Timer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Timer/Timer.cpp
)

target_include_directories(Timer 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)