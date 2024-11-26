cmake_minimum_required(VERSION 3.29)
project(Caso_Final_Integrador_Tema_3)

set(CMAKE_CXX_STANDARD 17)

include_directories(script_loader)

add_executable(Caso_Final_Integrador_Tema_3
    script_loader/script_loader.cpp
    script_loader/script_loader.h
    main.cpp)
