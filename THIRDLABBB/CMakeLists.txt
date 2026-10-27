cmake_minimum_required(VERSION 3.16)
project(THIRDLABBB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(THIRDLABBB main.cpp Money.cpp BankAccount.cpp)

# Явно указываем стандарт даже при совпадении со стандартом по умолчанию.
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(THIRDLABBB PRIVATE -std=c++14 -Wall -Wextra -Wpedantic)
endif()
