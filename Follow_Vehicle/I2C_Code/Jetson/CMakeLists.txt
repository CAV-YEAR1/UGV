cmake_minimum_required(VERSION 3.5)
set( CMAKE_CXX_STANDARD 11)

project(JetsonMoterControl)

add_executable(I2C I2C.hpp I2C.cpp I2CMain.cpp)
