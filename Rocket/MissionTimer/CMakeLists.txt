project(MissionTimer VERSION 0.1)

add_library(MissionTimer
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionTimer/MissionTimer.hpp    
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MissionTimer/MissionTimer.cpp 
)

target_link_libraries(MissionTimer PRIVATE Timer)
add_dependencies(MissionTimer Timer)
target_include_directories(MissionTimer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

function(create_mission_timer_test)
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
    target_link_libraries(${test_NAME} PRIVATE MissionTimer Timer)
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


create_mission_timer_test(
    NAME "MissionTimer_Proper_Start_Test"
    SOURCE "tests/src/ProperStart.cpp"
)
create_mission_timer_test(
    NAME "MissionTimer_Singleton_Test"
    SOURCE "tests/src/ProperStart.cpp"
)
create_mission_timer_test(
    NAME "MissionTimer_Test_Time_Test"
    SOURCE "tests/src/TestTime.cpp"
)
