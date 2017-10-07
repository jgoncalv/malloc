# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/27 15:05:44 by jgoncalv          #+#    #+#              #
#    Updated: 2017/03/28 20:05:35 by jgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

LINK		=	libft_malloc.so
NAME		=	$(LINK:.so=$(addprefix _, $(HOSTTYPE)).so)

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -g

LIBFT_DIR	=	libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
LIBFT_INC	=	$(LIBFT_DIR)include/

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_FILE	=	malloc.c\
	zone_list.c\
	zone_size.c\
	create_new_zone.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_FILE:.c=.o))

all:			$(NAME)

$(NAME):		$(LIBFT_LIB) $(OBJ_DIR) $(OBJS)
	rm -rf $(LINK)
	$(CC) $(FLAGS) -I $(INC_DIR) -I $(LIBFT_INC) $(LIBFT_LIB) $(OBJS) -shared -o $(NAME)
	ln -s $(NAME) $(LINK)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_INC)

clean:			cleanlib
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LINK)

cleanlib:
	@make -C $(LIBFT_DIR) clean

fclean:			clean fcleanlib
	@rm -rf $(NAME)

fcleanlib:		cleanlib
	@make -C $(LIBFT_DIR) fclean

re:				fclean all

relib:			fcleanlib $(LIBFT_LIB)

.PHONY:			fclean clean re relib cleanlib fcleanlib

-include $(OBJS:.o=.d)
