cmake_minimum_required(VERSION 3.5)
set( CMAKE_CXX_STANDARD 11)

project(JetsonMoterControl)

add_executable(JAPWM I2CPWM.hpp I2CPWM.cpp PWMMain.cpp)
