cmake_minimum_required(VERSION 3.9)
project(ft_fractol C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")

add_executable(ft_fractol main.c sources/ft_fractol.h sources/ft_img.c sources/ft_initialise.c sources/ft_mandelbrot.c sources/ft_keyhook.c)

link_directories(libft sources)

target_link_libraries(ft_fractol ${CMAKE_SOURCE_DIR}/libft/libft.a)