add_library(MissionLogger
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionLogger/MissionLogger.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionLogger/MissionLogger.cpp
)
add_dependencies(MissionLogger MissionTimer Timer)

target_include_directories(MissionLogger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(MissionLogger PRIVATE MissionTimer Timer)


function(create_mission_logger_test)
    set(options WILL_FAIL)
    set(args NAME SOURCE PASS_REGEX TIMEOUT TIMEOUT_AFTER_MATCH)
    set(list_args)
    cmake_parse_arguments(
        PARSE_ARGV 0
        test
        "${options}"
        "${args}"
        "${list_args}"
    )
    
    foreach(arg IN LISTS test_UNPARSED_ARGUMENTS)
        message(WARNING  "Unparsed Arguement: ${arg}")
    endforeach()

    add_executable(${test_NAME} ${test_SOURCE})
    target_link_libraries(${test_NAME} PRIVATE MissionLogger MissionTimer Timer)
    add_test(${test_NAME} ${test_NAME})

    set_tests_properties("${test_NAME}"
        PROPERTIES WILL_FAIL "${test_WILL_FAIL}"
    ) 
    
    if(DEFINED test_PASS_REGEX)
        set_property(TEST "${test_NAME}"
            PROPERTY PASS_REGULAR_EXPRESSION "${test_PASS_REGEX}"
        )
    endif()
    if(DEFINED test_TIMEOUT)
        set_tests_properties( ${test_NAME}
            PROPERTIES TIMEOUT ${test_TIMEOUT}
        )
    endif()
endfunction()

create_mission_logger_test(
    NAME "Mission_Logger_Singleton_Test"
    SOURCE "tests/src/singletonTest.cpp"
)

create_mission_logger_test(
    NAME "Mission_Logger_Time_Test"
    SOURCE "tests/src/missionTimeTest.cpp"
)

create_mission_logger_test(
    NAME "Mission_Logger_Status_Test"
    SOURCE "tests/src/logStatusTest.cpp"
)

create_mission_logger_test(
    NAME "Mission_Logger_Issues_Test"
    SOURCE "tests/src/logIssuesTest.cpp"
)

create_mission_logger_test(
    NAME "Mission_Logger_Event_Test"
    SOURCE "tests/src/logEventTest.cpp"
)
create_mission_logger_test(
    NAME "Mission_Logger_No_Time_Test"
    SOURCE "tests/src/hideTimeTest.cpp"
)