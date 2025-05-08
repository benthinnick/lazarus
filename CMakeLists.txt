cmake_minimum_required(VERSION 3.14)
project(TaskManagerServer)

set(CMAKE_CXX_STANDARD 17)


# Source files
set(SOURCES
    main.cpp
)

# Build the executable

find_package(Boost REQUIRED)

add_executable(task_server ${SOURCES})
target_link_libraries(task_server PRIVATE ${Boost_INCLUDE_DIRS})

