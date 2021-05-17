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

NAME_PUS				:= push_swap
NAME_CHE				:= check
CFLAGS					:= -Wall -Wextra -Werror
CC 							:= gcc
LIB							:= ./libft/libft.a
SRCS 						:= src

SRC_CHE				:= src/check.c \
								 src/stack_op.c \
								 src/push_stack.c \
								 src/validate.c \
								 src/validate_help.c $(LIB)

SRC_PUS				:= src/push_swap.c \
								 src/push_stack.c \
								 src/sort.c \
								 src/stack_op.c \
								 src/validate.c \
								 src/help_function.c $(LIB)

INCLUDES			:= includes/

GREEN					:= \033[1;32m
BLUE					:= \033[0;34m
RED						:= \033[1;31m
YELLOW				:= \033[1;33m
COLOR_OFF			:= \033[0m

all: $(NAME_PUS) $(NAME_CHE)

$(NAME_CHE): 
						@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
						@$(CC) $(CFLAGS) $(INCLUDES) ${SRC_CHE} -o ${NAME_CHE}
						@echo "$(GREEN)[Checker BUILT]$(COLOR_OFF)"

$(NAME_PUS):
						@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
						$(CC) $(CFLAGS) $(INCLUDES) ${SRC_PUS} -o ${NAME_PUS}
						@echo "$(GREEN)[Push_swap BUILT]$(COLOR_OFF)"

clean:
						rm -rf $(NAME_PUS) $(NAME_CHE)
					  @echo "$(YELLOW)[Objects removed]$(COLOR_OFF)"

fclean: clean
										@make fclean -C $(LIB)
										@rm -f $(NAME_CHE) $(NAME_PUS)
										@echo "$(RED)[All cleared]$(COLOR_OFF)"

re: fclean all