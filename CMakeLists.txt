cmake_minimum_required(VERSION 3.9)
project(ft_fractol C)

set(CMAKE_C_STANDARD 99)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -lm -framework OpenGL -framework AppKit")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -lm -framework OpenGL -framework AppKit")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit")

add_executable(ft_fractol sources/main.c sources/ft_fractol.h sources/ft_img.c sources/ft_initialise.c sources/ft_mandelbrot.c sources/ft_keyhook.c sources/ft_julia.c sources/ft_mandelbrot_func1.c sources/ft_mandelbrot_func2.c)

link_directories(libft sources)

target_link_libraries(ft_fractol ${CMAKE_SOURCE_DIR}/libft/libft.a)