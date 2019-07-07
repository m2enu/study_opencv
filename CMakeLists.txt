set(PRJNAME study_opencv)
cmake_minimum_required(VERSION 3.0)
project(${PRJNAME})

file(COPY resource/ DESTINATION ${PROJECT_BINARY_DIR}/resource/)
add_definitions(-DRESOURCE_DIR="${PROJECT_BINARY_DIR}/resource/")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

add_executable(${PRJNAME} src/main.cpp)

find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
    target_link_libraries(${PRJNAME} ${OpenCV_LIBS})
endif()
