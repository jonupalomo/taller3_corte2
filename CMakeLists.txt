cmake_minimum_required(VERSION 3.16)
project(EjerciciosExercism LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Soporte de hilos necesario para bank-account
find_package(Threads REQUIRED)

enable_testing()

# 1. Target para Bank Account
add_executable(ejecutable_bank_account
    bank_account_test.cpp
    bank_account.cpp
    bank_account.h
)
target_link_libraries(ejecutable_bank_account PRIVATE Threads::Threads)
add_test(NAME test_bank_account COMMAND ejecutable_bank_account)

# 2. Target para Crypto Square
add_executable(ejecutable_crypto_square
    crypto_square_test.cpp
    crypto_square.cpp
    crypto_square.h
)
add_test(NAME test_crypto_square COMMAND ejecutable_crypto_square)