cmake_minimum_required(VERSION 3.5)
set( CMAKE_CXX_STANDARD 11)

project(jetson-arduino)

add_executable(JetsonArduino i2c-arduino.cpp)
