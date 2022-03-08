cmake_minimum_required(VERSION 3.21)
project(SNP C)
set(CMAKE_C_STANDARD 17)

message("===========")
message(${CMAKE_CURRENT_SOURCE_DIR})
message("===========")

file(GLOB SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/A01/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/A02/*.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/A01/*.c
        ${CMAKE_CURRENT_SOURCE_DIR}/A02/*.c
        )

file(GLOB HEADER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/Headers/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Headers/*.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/A01/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/A01/*.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/A02/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/A02/*.hpp
        )

add_executable(SNP ${SOURCE_FILES} ${HEADER_FILES} main.c A02/Aufgabe2_32.c A02/Aufgabe2_32.h)
