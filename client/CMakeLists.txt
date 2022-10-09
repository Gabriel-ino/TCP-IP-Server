cmake_minimum_required(VERSION 3.1)
project(SimpleClientApp VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(
    SimpleClientApp
    tcpclient.cpp
)


