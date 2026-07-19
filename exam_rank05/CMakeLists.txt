add_executable(biginit
        level-01/biginit/main.cpp
        level-01/biginit/bigint.cpp
)

target_include_directories(biginit PRIVATE level-01/biginit)

add_executable(biginit_try01
        level-01/biginit/original-ana/main.cpp
        level-01/biginit/original-ana/bigint.cpp
)

target_include_directories(biginit_try01 PRIVATE
        level-01/biginit/original-ana
)

# Si bigint02.cpp es otra versión ejecutable, puedes activar esto:
# add_executable(biginit_v2
#     main.cpp
#     bigint02.cpp
# )
#
# target_include_directories(biginit_v2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})