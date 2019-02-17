cmake_minimum_required(VERSION 3.5)
set( CMAKE_CXX_STANDARD 11)

project(UGVRemoteControl)

set(PWM ../../PWMCode/Jetson/PWM.hpp ../../PWMCode/Jetson/PWM.cpp)
set(I2C ../../I2C_Code/Jetson/I2C.hpp ../../I2C_Code/Jetson/I2C.cpp)
set(source remote.hpp remote.cpp main.cpp)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(${PROJECT_NAME} ${PWM} ${I2C} ${source})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Widgets)
