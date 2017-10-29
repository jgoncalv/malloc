# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 15:05:44 by jgoncalv          #+#    #+#              #
#    Updated: 2017/10/29 15:00:55 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LINK		=	libft_malloc.so
NAME		=	$(LINK:.so=$(addprefix _, $(HOSTTYPE)).so)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

SRC_DIR		=	src/
INC_DIR		=	include/
OBJ_DIR		=	obj/

SRC_FILE	=	malloc.c\
	zone_list.c\
	zone_size.c\
	create_new_zone.c\
	realloc.c\
	free.c\
	show_alloc_mem.c\
	putfct.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
	rm -rf $(LINK)
	$(CC) $(FLAGS) -I $(INC_DIR) $(OBJS) -shared -o $(NAME)
	ln -s $(NAME) $(LINK)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LINK)


fclean:			clean
	rm -rf $(NAME)

re:				fclean all

.PHONY:			fclean clean re

-include $(OBJS:.o=.d)
