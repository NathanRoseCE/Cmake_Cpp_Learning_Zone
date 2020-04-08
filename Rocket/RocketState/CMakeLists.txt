add_library(RocketState
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RocketState/RocketState.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RocketState/RocketState.cpp
)
target_include_directories(RocketState PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
function(create_RocketState_test)
    set(options WILL_FAIL)
    set(args NAME SOURCE PASS_REGEX)
    set(list_args)
    cmake_parse_arguments(
        PARSE_ARGV 0
        test
        "${options}"
        "${args}"
        "${list_args}"
    )
    
    foreach(arg IN ${test_UNPARSED_ARGUMENTS}) 
        message(WARNING "Unparsed Arguement: ${arg}")
    endforeach()

    add_executable(${test_NAME} ${test_SOURCE} ${RocketStateSources})
    target_link_libraries(${test_NAME} PRIVATE RocketState)
    #target_include_directories(${test_NAME} PRIVATE ${RocketStateDirectory})

    add_test(${test_NAME} ${test_NAME})

    if(DEFINED ${test_PASS_REGEX})
        set_property(TEST ${test_NAME}
            PROPERTY PASS_REGULAR_EXPRESSION ${test_PASS_REGEX}
        )  
    endif()
    set_property(TEST ${test_NAME}
        PROPERTY WILL_FAIL
        "${test_WILL_FAIL}"
    )
endfunction()

create_RocketState_test(
    NAME "equal_test"
    SOURCE "tests/src/EqualTest.cpp"
)
create_RocketState_test(
    NAME "not_equal_test"
    SOURCE "tests/src/NotEqualTest.cpp"
)
create_RocketState_test(
    NAME "magnitude_test"
    SOURCE "tests/src/MagnitudeTest.cpp"
)
create_RocketState_test(
    NAME "vector_add_test"
    SOURCE "tests/src/VectorAddTest.cpp"
)
create_RocketState_test(
    NAME "vector_scale_test"
    SOURCE "tests/src/VectorScaleTest.cpp"
)
create_RocketState_test(
    NAME "set_values_test"
    SOURCE "tests/src/SetValuesTest.cpp"
)
create_RocketState_test(
    NAME "set_zero_test"
    SOURCE "tests/src/SetZeroTest.cpp"
)
create_RocketState_test(
    NAME "singleton_test"
    SOURCE "tests/src/SingletonTest.cpp"
)