cmake_minimum_required(VERSION 3.1)
project(TCPServer VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(THREADS_PREFER_PTHREAD_FLAG ON)

add_executable(
    TCPServer
    main.cpp
    TcpServerController.hpp
    TcpServerController.cpp
    TcpNewConnectionAcceptor.hpp
    TcpNewConnectionAcceptor.cpp
    TcpClientDbManager.hpp
    TcpClientDbManager.cpp
    TcpClientServiceManager.hpp
    TcpClientServiceManager.cpp
    NetworkUtils.hpp
    NetworkUtils.cpp
)

find_package(Threads REQUIRED)
target_link_libraries(TCPServer PUBLIC Threads::Threads)

