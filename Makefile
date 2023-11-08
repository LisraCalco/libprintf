# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegendr <tlegendr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:14:59 by tlegendr          #+#    #+#              #
#    Updated: 2023/11/08 16:15:00 by tlegendr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the output name (e.g., your static library or binary)
NAME = libftprintf.a

# Source files
SRC =	ft_printf.c ft_utils_hex.c
# Object files derived from source files
OBJ = $(SRC:.c=.o)

# Compiler and compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default target (builds the final output)
all: $(NAME)

# Pattern rule for compiling source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the final output (static library)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean everything, including the final output
fclean: clean
	rm -f $(NAME)

re: fclean all

# Phony target to avoid conflicts with files named "clean" or "fclean"
.PHONY: all clean fclean re
