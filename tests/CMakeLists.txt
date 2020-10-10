project(tests)

add_subdirectory(googletest)

add_executable(tests book_list.cpp)
target_link_libraries(tests gtest gtest_main libassignment-2)