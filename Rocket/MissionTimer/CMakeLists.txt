project(MissionTimer VERSION 0.1)

add_library(MissionTimer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionTimer/MissionTimer.hpp    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionTimer/MissionTimer.cpp 
)

target_link_libraries(MissionTimer PRIVATE Timer)
add_dependencies(MissionTimer Timer)
target_include_directories(MissionTimer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

