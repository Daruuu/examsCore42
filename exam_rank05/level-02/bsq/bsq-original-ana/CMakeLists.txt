cmake_minimum_required(VERSION 3.16)

project(bsq_exam C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Buenas opciones para debug
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(bsq_exam
        bsq_exam.c
)

target_include_directories(bsq_exam PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_compile_definitions(bsq_exam PRIVATE
        _POSIX_C_SOURCE=200809L
)

target_compile_options(bsq_exam PRIVATE
        -Wall
        -Wextra
        -Werror
        -g3
        -O0
)

# Opcional: sanitizers para detectar errores de memoria
# Descomenta si estás usando GCC o Clang
# target_compile_options(bsq_exam PRIVATE -fsanitize=address,undefined)
# target_link_options(bsq_exam PRIVATE -fsanitize=address,undefined)