cmake_minimum_required(VERSION 3.20)
project(katalog_ksiazek)
set(CMAKE_CXX_STANDARD 11)

find_package(Catch2 3 REQUIRED)
add_executable(tests InputHelper_test.cpp InputHelper.cpp InputHelper.h Directory_test.cpp Directory.h Directory.cpp )
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(katalog_ksiazek main.cpp Book.h Directory.cpp Directory.h CLI.cpp CLI.h InputHelper.cpp InputHelper.h FileDirectory.cpp FileDirectory.h )
