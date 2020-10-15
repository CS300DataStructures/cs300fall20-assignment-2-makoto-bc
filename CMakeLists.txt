cmake_minimum_required(VERSION 3.17)
project(assignment-2)

set(CMAKE_CXX_STANDARD 17)

set(
    SOURCES
    bookstore_manager.cpp
    book_list.cpp
    book.cpp
)

add_subdirectory(tests)

add_executable(assignment-2 ass2.cpp ${SOURCES})

add_library(libassignment-2 STATIC ${SOURCES})