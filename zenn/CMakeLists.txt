cmake_minimum_required(VERSION 3.2)
project(zenn)

if (NOT LOGGING_SOURCE)
	set(LOGGING_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/../external-modules/spdlog")
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

FILE(GLOB SOURCE_FILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp 
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} spdlog)