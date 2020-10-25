cmake_minimum_required(VERSION 3.2)
project(zenn)

find_package(OpenCV REQUIRED PATHS "../build")

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")


if (NOT LOGGING_SOURCE)
	set(LOGGING_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../external-modules/spdlog")
endif()
if (NOT OPEN_CV_SOURCE)
	set(OPEN_CV_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../external-modules/opencv")
endif()

# Set C++ standard to C++17
# Compiler options:
# -g: Produce debug messages during compilation
# -pthread:
# -o0: Optimiser - reduce compile time and produce expected results (may need reconsideration)
message ("Default C++ version: ${CMAKE_CXX_STANDARD}")
set(CMAKE_CXX_STANDARD 17)                                            
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -g -O0")
message ("Building with C++ version: ${CMAKE_CXX_STANDARD}")

include_directories(${LOGGING_SOURCE}/include/spdlog)
include_directories(${OPEN_CV_SOURCE}/include)
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/image-processing)

FILE(GLOB SOURCE_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/image-processing/*
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} spdlog ${OpenCV_LIBS})