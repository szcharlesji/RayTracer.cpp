cmake_minimum_required(VERSION 3.25)
project(RayTracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RayTracer
        main.cpp
        vec3.h
        color.h)
