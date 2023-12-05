cmake_minimum_required(VERSION 3.24.3)
project(Sistema_Bancario)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sistema_Bancario
        main.cpp
        Account.cpp
        Account.h
        Bank.cpp
        Bank.h
        CheckingAccount.cpp
        CheckingAccount.h
        SavingsAccount.cpp
        SavingsAccount.h
)

set_target_properties(Sistema_Bancario PROPERTIES OUTPUT_NAME "main")
