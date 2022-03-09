cmake_minimum_required(VERSION 3.20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD 17)

# Search in our custom directory
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH};thirdparty/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

add_compile_options(-Wall)

project(main)

add_executable(${PROJECT_NAME} main.cpp)

find_package(AWSSDK REQUIRED COMPONENTS s3)
target_link_libraries(main ${AWSSDK_LINK_LIBRARIES})
