# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 20:46:24 by akokoshk          #+#    #+#              #
#    Updated: 2018/03/08 21:26:42 by akokoshk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLXFLAG = -lmlx -framework OpenGL -framework AppKit
NAME = fractol
SOURCES = sources/ft_initialise.c sources/ft_keyhook.c \
	sources/ft_mandelbrot_func1.c sources/main.c \
	sources/ft_img.c sources/ft_julia.c \
	sources/ft_mandelbrot.c sources/ft_mandelbrot_func2.c
OBJECTS = $(SOURCES:.c=.o)
LIBFOLDER = libft

all: $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJECTS)
	@make -C $(LIBFOLDER)
	@$(CC) $(FLAGS) $(MLXFLAG) $(OBJECTS) -L $(LIBFOLDER) -lft -o $(NAME)
	@echo "fractol compiled"

clean:
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFOLDER)
	@echo "fractol cleaned"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFOLDER)
	@echo "fractol fcleaned"

re:	fclean all
