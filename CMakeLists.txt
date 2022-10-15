cmake_minimum_required(VERSION 3.23)
project(schedule)

set(CMAKE_CXX_STANDARD 14)

add_executable(schedule main.cpp Classes/Aula.cpp Classes/Aula.h Classes/Student.cpp Classes/Student.h Classes/Turma.cpp Classes/Turma.h Classes/Horario.cpp Classes/Horario.h)
