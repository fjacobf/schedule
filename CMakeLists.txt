cmake_minimum_required(VERSION 3.23)
project(schedule)

set(CMAKE_CXX_STANDARD 14)

add_executable(schedule main.cpp Classes/Time_slot.cpp Classes/Time_slot.h Classes/Student.cpp Classes/Student.h Classes/Class.cpp Classes/Class.h)
