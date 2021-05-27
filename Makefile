# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 11:09:35 by oavelar           #+#    #+#              #
#    Updated: 2021/05/27 17:05:47 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUS				:= push_swap
NAME_CHE				:= check
CFLAGS					:= -Wall -Wextra -Werror
CC 							:= gcc
LIB							:= ./libft
SRCS 						:= src

SRC_CHE				:= 			 src/checker.c \
								 
SRC_PUS				:=			 src/push_swap.c \
								 src/sort.c \
								 src/sort_top_a.c \
								 src/sort_top_a_2.c 

SRCS				:=			 src/move_swap.c \
								 src/move_swap2.c \
								 src/move_swap3.c \
								 src/list_function.c \
								 src/list2_function.c 

RAND				:=			main.c
								
OBJ					:=			src/move_swap.o \
								src/move_swap2.o \
								src/move_swap2.o \
								src/list_function.o \
								src/list2_function.o \
								src/mid_point.o \
								src/print_stack.o \
								src/sort.o \
								src/ckeck.o \
								src/sort_top_a.o \
								src/sort_top_a_2.o \
								src/push_swap.o \
								src/checker.o \
								src/main.o \
								src/parse_help.o


GREEN					:= \033[1;32m
BLUE					:= \033[0;34m
RED						:= \033[1;31m
YELLOW				    := \033[1;33m
COLOR_OFF			    := \033[0m

all: $(NAME_CHE) $(NAME_PUS)

$(NAME_CHE): $(SRCS) $(SRC_CHE)
						@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
						make -C $(LIB)
						@$(CC) -Llibft -lft -o ${NAME_CHE} $(CFLAGS)
						@echo "$(GREEN)[Checker BUILT]$(COLOR_OFF)"

$(NAME_PUS): $(SRCS) $(SRC_PUS)
						@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
						make -C $(LIB)
						$(CC) -Llibft -lft -o ${NAME_PUS} $(CFLAGS)
						@echo "$(GREEN)[Push_swap BUILT]$(COLOR_OFF)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
						rm -rf $(NAME_PUS) $(NAME_CHE)
					  @echo "$(YELLOW)[Objects removed]$(COLOR_OFF)"

fclean: clean
										@make fclean -C $(LIB)
										@rm -f $(NAME_CHE) $(NAME_PUS)
										@echo "$(RED)[All cleared]$(COLOR_OFF)"

re: fclean all