# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 11:09:35 by oavelar           #+#    #+#              #
#    Updated: 2021/05/29 12:15:43 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
LIBFT = ./libft
INCLUDE = includes

CH_SRCS				:= 			 src/checker.c 
								 
PS_SRCS				:=			 src/push_swap.c \
								 src/sort.c \
								 src/sort_top_a.c \
								 src/sort_top_a_2.c 

RAND 				:=			src/main.c

SRCS				:=			 src/move_swap.c \
								 src/move_swap2.c \
								 src/move_swap3.c \
								 src/list_function.c \
								 src/list2_function.c \
								 src/mid_point.c \
								 src/print_stack.c \
								 src/check.c \
								 src/parse_help.c
								
OBJ					:=			src/move_swap.o \
								src/move_swap2.o \
								src/move_swap3.o \
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

FLAGS = -Wall -Wextra -Werror -fsanitize=address

CC	  = gcc

GREEN					:= \033[1;32m
BLUE					:= \033[0;34m
RED						:= \033[1;31m
YELLOW				    := \033[1;33m
COLOR_OFF			    := \033[0m

all: $(NAME1) $(NAME2)

$(NAME1): $(SRCS) $(CH_SRCS)
						@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
						make -C $(LIBFT)
						@$(CC) $^ -Llibft -lft -o ${NAME1} $(FLAGS) 
						@echo "$(GREEN)[Checker BUILT]$(COLOR_OFF)"

$(NAME2): $(SRCS) $(PS_SRCS)
						@echo "$(BLUE)[Building libraries...]$(COLOR_OFF)"
						make -C $(LIBFT)
						$(CC) $^ -Llibft -lft -o ${NAME2} $(FLAGS) 
						@echo "$(GREEN)[Push_swap BUILT]$(COLOR_OFF)"

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
						make clean -C $(LIBFT)
						rm -f $(OBJ)
					  @echo "$(YELLOW)[Objects removed]$(COLOR_OFF)"

fclean: clean
										@make fclean -C $(LIBFT)
										@rm -f $(NAME1) $(NAME2)
										@echo "$(RED)[All cleared]$(COLOR_OFF)"

re: fclean all
