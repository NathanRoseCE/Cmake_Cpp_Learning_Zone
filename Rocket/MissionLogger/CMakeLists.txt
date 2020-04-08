add_library(MissionLogger
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionLogger/MissionLogger.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionLogger/MissionLogger.cpp
)

target_link_directories(MissionLogger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(MissionLogger PRIVATE MissionTimer)