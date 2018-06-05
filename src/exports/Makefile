# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okurache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 19:59:59 by okurache          #+#    #+#              #
#    Updated: 2018/01/23 20:00:01 by okurache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftin.a

CC = gcc -Wall -Wextra -Werror

LC = ar rc

SRC_DIR = src

OBJ_DIR = obj

SRC_N =	fd_reader/new_fd_reader.c \
		fd_reader/fd_reader_init.c \
		fd_reader/del_fd_reader.c \
		fd_reader/fd_reader_dinit.c \
		fd_reader/fd_reader_is_opened.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_N:.c=.o))

IMPORTS_PATH = ../../imports

LIBFT_PATH = $(IMPORTS_PATH)/okurache_libft

LIBFT_A = libft.a

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/fd_reader

$(NAME): $(OBJ_DIR) $(OBJ)
	$(LC) $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

#$(LIBFT_PATH)/$(LIBFT_A):
#	@make -C $(LIBFT_PATH)/ all
#
#libclean:
#	@make -C $(LIBFT_PATH)/ clean
#
#libfclean:
#	@make -C $(LIBFT_PATH)/ fclean
#
#libre:
#	@make -C $(LIBFT_PATH)/ re