cmake_minimum_required (VERSION 3.10)

project (copy_move)

# This are variables.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

# Which files that we compile.
file (GLOB source_files "${source_dir}/*.cc")

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads)
add_executable (${PROJECT_NAME} ${source_files})

#target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
