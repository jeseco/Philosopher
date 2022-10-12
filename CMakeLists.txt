cmake_minimum_required(VERSION 3.18.0)

set(CMAKE_C_COMPILER gcc)
project(philo)

add_executable(philo srcs/main.c)

add_subdirectory(srcs)

target_compile_options(philo PRIVATE -Wextra -Wall -Werror -pthread)

target_include_directories(philo PUBLIC 
						"includes/"
						"includes/parsing/")

# Add CMocka CMake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmocka)

if (UNIT_TESTING)
	find_package(cmocka 1.1.0 REQUIRED)
	include(AddCMockaTest)
	add_subdirectory(test)
endif()
