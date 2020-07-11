cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(check_environment)

add_executable(check_environment helloworld.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
    target_compile_definitions(check_environment PUBLIC "IS_LINUX")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for macOS")
    target_compile_definitions(check_environment PUBLIC "IS_MACOS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windwos")
    target_compile_definitions(check_environment PUBLIC "IS_WINDOWS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for AIX")
    target_compile_definitions(check_environment PUBLIC "IS_AIX")
endif()

