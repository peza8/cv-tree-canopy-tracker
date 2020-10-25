cmake_minimum_required(VERSION 3.2)
project(zenn)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/libs)

add_subdirectory(external-modules/spdlog)     # Builds the logging library
add_subdirectory(external-modules/opencv)     # Builds OpenCV
add_subdirectory(zenn)                        # Builds Zenn