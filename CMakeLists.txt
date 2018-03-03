cmake_minimum_required(VERSION 3.9)
project(push_swap)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

file(GLOB INC_LIB ./libft/includes/*.h)
file(GLOB INC_PROJ ./includes/*.h)
file(GLOB C_PUSH_SWAP ./push_swap_src/*.c)
file(GLOB C_CHECKER ./checker_src/*.c)
file(GLOB C_SRC ./src/*.c)
file(GLOB SOURCES_LIBC ./libft/libc/*.c)
file(GLOB SOURCES_PRINTF ./libft/printf/*.c)
set(INC ${INC_LIB} ${INC_PROJ})
set(LIBFT ${SOURCES_LIBC} ${SOURCES_PRINTF})

include_directories("./libft/includes" "./includes")
add_executable(checker ${INC} ${LIBFT} ${C_CHECKER} ${C_SRC})
add_executable(push_swap ${INC} ${LIBFT} ${C_PUSH_SWAP} ${C_SRC})
