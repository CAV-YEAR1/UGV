cmake_minimum_required(VERSION 3.5)
set( CMAKE_CXX_STANDARD 11)

project(ZedCamDepthMeasurement)

find_package(ZED 2 REQUIRED)
find_package(CUDA ${ZED_CUDA_VERSION} EXACT REQUIRED)

include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${ZED_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

link_directories(${ZED_LIBRARY_DIR})
link_directories(${CUDA_LIBRARY_DIRS})

ADD_EXECUTABLE(ZED ZedConfig.hpp ZedConfig.cpp)

TARGET_LINK_LIBRARIES(${execName} ${ZED_LIBRARIES}
${CUDA_CUDA_LIBRARY} ${CUDA_CUDART_LIBRARY} ${CUDA_NPP_LIBRARIES_ZED} )
