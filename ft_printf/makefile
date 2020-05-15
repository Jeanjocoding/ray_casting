# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlucille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 11:41:17 by tlucille          #+#    #+#              #
#    Updated: 2020/02/14 11:41:21 by tlucille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB_DIR = libft/

LIBFT_A = libft.a

FILE_DIR = srcs

INC_DIR = srcs

INCLUDES = $(FILE_DIR)/ft_printf.h		\

SRC = $(FILE_DIR)/arg_parser.c	\
	$(FILE_DIR)/apply_options.c		\
	$(FILE_DIR)/apply_utils.c 	\
	$(FILE_DIR)/ft_itoa_base.c 	\
	$(FILE_DIR)/ft_litoa_base.c		\
	$(FILE_DIR)/ft_litoa_unsigned.c		\
	$(FILE_DIR)/get_size.c	\
	$(FILE_DIR)/master_utils.c \
	$(FILE_DIR)/parser_utils.c \
	$(FILE_DIR)/printf_master.c \
	$(FILE_DIR)/options_initializer.c \
	$(FILE_DIR)/ft_atoi_base.c \
	$(FILE_DIR)/get_neg_hex.c \
	$(FILE_DIR)/handle_nulls.c \
	$(FILE_DIR)/get_unsigned_int.c \
	$(FILE_DIR)/ft_litoa.c \
	$(FILE_DIR)/get_ascii.c \
	$(FILE_DIR)/handle_them.c \
	$(FILE_DIR)/master_utils_nobuf.c \
	$(FILE_DIR)/prec_reduce.c \

CC = gcc

LIB_MAKER = Make -C

OBJS = $(patsubst %.c, %.o,$(SRC))

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

OBJ_LIB = $(LIB_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB_MAKER) $(LIB_DIR)
	@cp $(LIB_DIR)$(LIBFT_A) $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	$(LIB_MAKER) $(LIB_DIR) clean
	/bin/rm -f $(OBJS)

fclean: clean
	$(LIB_MAKER) $(LIB_DIR) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
