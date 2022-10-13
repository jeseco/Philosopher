add_library(parsing parsing.c ft_atol.c ft_isdigit.c ${HEADER_LIST})

target_include_directories(parsing PUBLIC
							"${CMAKE_BUILD_DIR}/includes")

target_compile_options(parsing PRIVATE -Wextra -Wall -Werror -pthread)
