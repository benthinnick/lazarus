cmake_minimum_required(VERSION 3.6)
project(TaskManagerServer)

enable_testing()

find_package(PkgConfig REQUIRED)

add_subdirectory(src)
add_subdirectory(test)
