add_library(MissionLogger
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionLogger/MissionLogger.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionLogger/MissionLogger.cpp
)
add_dependencies(MissionLogger MissionTimer Timer)

target_include_directories(MissionLogger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(MissionLogger PRIVATE MissionTimer Timer)