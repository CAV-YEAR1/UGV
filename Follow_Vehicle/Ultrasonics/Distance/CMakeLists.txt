cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

add_executable(testUltrasonic testDistance.cpp moving_average.hpp moving_average.cpp distance.hpp distance.cpp jetsonGPIO.cpp jetsonGPIO.hpp hcsr04.cpp hcsr04.hpp)
