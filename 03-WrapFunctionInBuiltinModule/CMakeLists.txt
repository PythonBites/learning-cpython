cmake_minimum_required(VERSION 3.1.0)

# We use C++11
set(CMAKE_CXX_STANDARD 11)

# Define project
project(learning-cpython)

# Find, configure, and include Python
find_package(PythonLibs 3 REQUIRED)
include_directories("${PYTHON_INCLUDE_DIRS}")

# Add executable
add_executable(MyApp main.cpp)
target_link_libraries(MyApp ${PYTHON_LIBRARIES})
