file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${INCLUDE_DIRECTORIES}/*.h")

add_subdirectory(parsing/)


target_compile_options(parsing PRIVATE -Wextra -Wall -Werror -pthread)
