cmake_minimum_required(VERSION 3.16)
project(HomeRemoteProtocolTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(protocol_test protocol_test.cpp)
target_include_directories(protocol_test PRIVATE
    ../libraries/HomeRemoteProtocol/include
)
