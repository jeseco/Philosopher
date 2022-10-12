file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${INCLUDE_DIRECTORIES}/*.h")

add_subdirectory(parsing/)

target_include_directories(parsing PUBLIC
							"${PROJECT_SOURCE_DIR}/includes/"
							"${PROJECT_SOURCE_DIR}/includes/parsing/")

target_link_libraries(philo parsing)

target_compile_options(parsing PRIVATE -Wextra -Wall -Werror -pthread)
