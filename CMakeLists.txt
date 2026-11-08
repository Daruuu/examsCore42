cmake_minimum_required(VERSION 3.28)

project(42_exam LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(set_exam_warnings target_name)
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-Wall -Wextra -Werror)
    endif()
endfunction()

#add_subdirectory(exam_rank02)
#add_subdirectory(exam_rank03)
#add_subdirectory(exam_rank04)
add_subdirectory(exam_rank05)

add_executable(practice01
        practice01/miniserver.c
)

set_target_properties(practice01 PROPERTIES
        C_STANDARD 11
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS OFF
)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(practice01 PRIVATE -Wall -Wextra -Werror)
endif()
