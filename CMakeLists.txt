cmake_minimum_required(VERSION 3.18.0)

project(philo)

set(CMAKE_C_COMPILER gcc)

add_subdirectory(srcs)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmocka)

if (UNIT_TESTING)
	find_package(cmocka 1.1.0 REQUIRED)
	include(AddCMockaTest)
	add_subdirectory(test)
endif()
