cmake_minimum_required(VERSION 3.0.0)

project(Calculator_Project VERSION 1.0.0)

# Libraries and executables are named TARGETS in the cmake

add_subdirectory(my_math)
add_subdirectory(my_print)

add_executable ( calculator
    main.cpp
)

target_link_libraries(calculator my_math my_print)