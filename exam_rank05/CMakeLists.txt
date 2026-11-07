add_executable(biginit
        level-01/biginit/main.cpp
        level-01/biginit/bigint-vector/bigint-vector.cpp
)

target_include_directories(biginit PRIVATE
        level-01/biginit/bigint-vector
)
