# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 11:09:35 by oavelar           #+#    #+#              #
#    Updated: 2021/05/10 14:42:40 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SW				:= push_swap
NAME_CK				:= check
CFLAGS				:= -Wall -Wextra -Werror -g
CC 						:= gcc

SRC						:= src/math/get_input.c \
								 src/math/math_1.c \
								 src/math/math_2.c \
								 src/math/math_3.c \
								 src/math/math_buf.c \
								 src/math/med_verif.c

SRC_SW				:= src/push/push_swap.c

SRC_CK				:= src/utils/check.c \
								 src/utils/buf_utils.c \
								 src/utils/ft_verif_sort.c \
								 src/utils/list.c \
								 src/utils/sort.c \
								 src/utils/utils.c

OBJS					:= $(SRC:.c=.o)
OBJS_SW				:= $(SRC_SW:.c=.o)	
OBJS_CK				:= $(SRC_CK:.c=.o)

LIB						:= libft/
INCLUDES			:= -I./src/push/push_swap.h -I./libft/libft.h

GREEN					:= \033[1;32m
BLUE					:= \033[0;34m
RED						:= \033[1;31m
YELLOW				:= \033[1;33m
COLOR_OFF			:= \033[0m

all: $(NAME_SW) $(NAME_CK)

$(NAME_CK): $(OBJS_CK)
										@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
										@make -C $(LIB)
										@$(CC) $(CFLAGS) $(INCLUDES) ${SRC_CK}  -L $(LIB) -lft -o ${NAME_CK}
										@echo "$(GREEN)[Checker BUILT]$(COLOR_OFF)"

$(NAME_SW): $(OBJS_SW)
										@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
										@make -C $(LIB)
										$(CC) $(CFLAGS) $(INCLUDES) ${SRC_SW}  -L $(LIB) -lft -o ${NAME_SW}
										@echo "$(GREEN)[Push_swap BUILT]$(COLOR_OFF)"

clean:
										@make clean -C $(LIB)
										@rm -f $(OBJS)
										@echo "$(YELLOW)[Objects removed]$(COLOR_OFF)"

fclean: clean
										@make fclean -C $(LIB)
										@rm -f $(NAME_CK) $(NAME_SW)
										@echo "$(RED)[All cleared]$(COLOR_OFF)"

re: fclean all