cmake_minimum_required(VERSION 3.5)
set( CMAKE_CXX_STANDARD 11)

project(JetsonMoterControl)

add_executable(RemotePWM ../../PWMCode/Jetson/PWM.hpp ../../PWMCode/Jetson/PWM.cpp remote.cpp ../../I2C_Code/Jetson/I2C.hpp ../../I2C_Code/Jetson/I2C.cpp)
