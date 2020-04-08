add_library(MissionTimer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionTimer/MissionTimer.hpp    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionTimer/MissionTimer.cpp 
    MissionTimer   
)
target_link_libraries(MissionTimer PRIVATE Timer)
target_include_directories(MissionTimer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

