add_library(StateMachine
    ${CMAKE_CURRENT_SOURCE_DIR}/src/StateMachine/StateMachine.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/StateMachine/StateMachine.cpp
)
target_include_directories(StateMachine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_dependencies(StateMachine RocketState MissionLogger MissionTimer Timer)
target_link_libraries(StateMachine 
    PRIVATE RocketState MissionLogger MissionTimer Timer
)   



