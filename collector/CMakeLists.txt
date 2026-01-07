add_executable(collector
    src/main.cpp
    src/proc_reader.cpp
    src/sampler.cpp
    src/writer.cpp
    src/queue.cpp
)

target_include_directories(collector
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)