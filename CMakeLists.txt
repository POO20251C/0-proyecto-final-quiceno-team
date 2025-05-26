cmake_minimum_required(VERSION 3.31)
project(Mazmorra)

set(CMAKE_CXX_STANDARD 20)

add_executable(Mazmorra main.cpp
        heroe.cpp
        heroe.h
        enemigo.cpp
        enemigo.h
        item.cpp
        item.h
        inventario.cpp
        inventario.h
        sala.cpp
        sala.h
        personaje.cpp
        personaje.h
        scoremanager.cpp
        scoremanager.h
        mazmorra.cpp
        mazmorra.h
        equipo.cpp
        equipo.h)
