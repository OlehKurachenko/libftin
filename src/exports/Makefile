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

LC_ADD = ar -q

SRC_DIR = src

OBJ_DIR = obj

SRC_N =	buffered_fd_reader/buffered_fd_reader_init.c \
		buffered_fd_reader/buffered_fd_reader_dinit.c \
		buffered_fd_reader/new_buffered_fd_reader.c \
		buffered_fd_reader/del_buffered_fd_reader.c \
		buffered_fd_reader/buffered_fd_reader_is_opened.c \
		buffered_fd_reader/buffered_fd_reader_is_readable.c \
		buffered_fd_reader/buffered_fd_reader_has_str.c \
		buffered_fd_reader/buffered_fd_reader_has_llint.c \
		buffered_fd_reader/buffered_fd_reader_has_lluint.c \
		buffered_fd_reader/buffered_fd_reader_read_char.c \
		buffered_fd_reader/buffered_fd_reader_read_line.c \
		buffered_fd_reader/buffered_fd_reader_read_line_to_array.c \
		buffered_fd_reader/buffered_fd_reader_read_str.c \
		buffered_fd_reader/buffered_fd_reader_read_str_to_array.c \
		buffered_fd_reader/buffered_fd_reader_read_llint.c \
		buffered_fd_reader/buffered_fd_reader_read_lluint.c \
		buffered_fd_reader/buffered_fd_reader_read_ldouble.c \
		buffered_fd_reader/buffered_fd_reader_lookup_char.c \
		buffered_fd_reader/buffered_fd_reader_pass_spaces.c \
		buffered_fd_reader/buffered_fd_reader_read_line_delim.c \
		buffered_fd_reader/buffered_fd_reader_read_line_delim_to_array.c \
		buffered_fd_reader/buffered_fd_reader_pass_line.c \
		buffered_fd_reader/buffered_fd_reader_read_buffer.c

INCLUDES = includes/

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_N:.c=.o))

IMPORTS_PATH = ../../imports

LIBFT_PATH = $(IMPORTS_PATH)/okurache_libft

LIBFT_A = libft.a

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/buffered_fd_reader

$(NAME): $(LIBFT_PATH)/$(LIBFT_A) $(OBJ_DIR) $(OBJ)
	cp $(LIBFT_PATH)/$(LIBFT_A) $(NAME)
	$(LC_ADD) $(NAME) $(OBJ)

clean: libclean
	rm -rf $(OBJ_DIR)

fclean: libfclean clean
	rm -f $(NAME)

re: fclean all

shortre: shortfclean all

shortfclean:
	rm -rf $(OBJ_DIR)
	rm -f $(NAME)


$(LIBFT_PATH)/$(LIBFT_A):
	@make -C $(LIBFT_PATH)/ all

libclean:
	@make -C $(LIBFT_PATH)/ clean

libfclean:
	@make -C $(LIBFT_PATH)/ fclean

libre:
	@make -C $(LIBFT_PATH)/ re