add_library(FiringCircuit
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FiringCircuit/FiringCircuit.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/FiringCircuit/FiringCircuit.cpp
)
add_dependencies(FiringCircuit MissionLogger MissionTimer Timer)
target_link_libraries(FiringCircuit PRIVATE MissionLogger MissionTimer Timer)

target_include_directories(FiringCircuit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)


function(create_firing_circuit_test)
    set(options)
    set(args NAME SOURCE PASS_REGEX)
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
    target_link_libraries(${test_NAME} PRIVATE FiringCircuit)
    add_test(${test_NAME} ${test_NAME})
    if(DEFINED ${test_PASS_REGEX})
        set_property(TEST ${test_NAME}
            PROPERTY PASS_REGULAR_EXPRESSION ${test_PASS_REGEX}
        )
    endif()
endfunction()