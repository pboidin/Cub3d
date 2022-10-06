# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: madelaha <madelaha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 15:58:44 by madelaha          #+#    #+#              #
#    Updated: 2022/10/05 20:19:03 by piboidin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Names
NAME		=	cub3D
NAME_BONUS	=	cub3D_bonus

#	Includes
-include make/mandatory/includes.mk
-include make/mandatory/srcs.mk
-include make/bonus/includes.mk
-include make/bonus/srcs.mk

#	Compilation
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
LINUX_MLX	=	minilibx-linux/
LINUX_MLX_SRC	=	https://github.com/42Paris/minilibx-linux.git
LIBS		=	./minilibx-linux/libmlx_Linux.a
USR_LIBS	=	-L/usr/lib -lXext -lm -lX11
INC_PATH	=	./mandatory/includes/
INC_PATH_BON	= 	./bonus/includes/

SRCS_OBJS	=	$(SRCS_SOURCES:.c=.o)
SRCS_OBJS_BON	=	$(SRCS_BONUS:.c=.o)

#	Delete
RM		=	rm -rf

#	Rules
#		Defaults
all:	linux_mlx $(NAME)
bonus:	linux_mlx $(NAME_BONUS)

#		Compile cub3D
$(NAME): $(INCLUDES) $(SRCS_OBJS)
	@make -C $(LINUX_MLX)
	@$(CC) -o $(NAME) $(SRCS_OBJS) $(LIBS) $(USR_LIBS) $(CFLAGS) -I $(INC_PATH)
	@echo "CUB CREATED"

#		Bonus
$(NAME_BONUS): $(INC_BONUS) $(SRCS_OBJS_BON)
	@make -C $(LINUX_MLX)
	@$(CC) -o $(NAME_BONUS) $(SRCS_OBJS_BON) $(LIBS) $(USR_LIBS) $(CFLAGS) -I $(INC_BONUS)
	@echo "CUB BONUS CREATED"

#		Install minilibx-linux
linux_mlx:
	@if [ ! -d $(LINUX_MLX) ]; then \
		git clone $(LINUX_MLX_SRC) ./$(LINUX_MLX); \
	fi; \

#		Clean
clean:
	$(RM) $(SRCS_OBJS) $(SRCS_OBJS_BON)
	make flcean -C ./$(LINUX_MLX)
	echo "CLEANING ALL .O PROJECTS"

#		FClean
fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	echo "CLEANING COMPILED PROGRAMS!"

#		Re
re:	fclean all


#		PHONY
.PHONY: all clean fclean re

