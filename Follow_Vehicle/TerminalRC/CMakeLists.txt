cmake_minimum_required(VERSION 3.5)
set( CMAKE_CXX_STANDARD 11)

project (RemoteControl)
add_executable(RemoteControl sshControl.cpp ../../PWMCode/Jetson/PWM.hpp ../../PWMCode/Jetson/PWM.cpp ../../I2C_Code/Jetson/I2C.hpp ../../I2C_Code/Jetson/I2C.cpp)
