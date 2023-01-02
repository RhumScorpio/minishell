# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 20:58:41 by clesaffr          #+#    #+#              #
#    Updated: 2023/01/02 21:34:06 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

CC			=	gcc

CFLAGS		=  -g3 -Wall -Werror -Wextra

SRCS		=	main.c	
				
INCLUDES	=	-Iincludes

LIBFT		=	libft.a

PATH_LIBFT	=	libft/

PATH_OBJS	=	.objs/

PATH_SRCS	=	srcs/

F_OBJS		=	$(addprefix $(PATH_OBJS), $(OBJS))

F_LIBFT		=	$(addprefix $(PATH_LIBFT), $(LIBFT))

OBJS		=	$(SRCS:.c=.o)

UNAME		:= $(shell uname)

all				: lib $(PATH_OBJS) $(NAME)

lib				: 
					make -C $(PATH_LIBFT)

$(PATH_OBJS)	:	
					mkdir -p $(PATH_OBJS)

$(NAME)			:	$(F_OBJS)
					$(CC) $(CFLAGS) $(INCLUDES) -L$(PATH_LIBFT) -lreadline -o $(NAME) $(F_OBJS) 

$(PATH_OBJS)%.o	:	$(PATH_SRCS)%.c
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean			:
					rm -rf $(F_OBJS) $(PATH_OBJS)
					make clean -C $(PATH_LIBFT)

fclean			:	clean
					rm -f $(NAME)
					make fclean -C $(PATH_LIBFT)

re				:	fclean all

.PHONY: clean fclean all re lib
