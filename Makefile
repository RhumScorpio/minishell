# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 13:12:34 by alewalla          #+#    #+#              #
#    Updated: 2023/02/28 12:47:09 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
DIR_LIB = ./includes/libft
LIB = $(DIR_LIB)/libft.a

SRCS = 	main.c						\
		ft_block_maker.c			\
		ft_parsing.c				\
		ft_putstruct.c				\
		ft_set_first_block.c		\
		ft_tokenl_utils.c			\
		ft_expand.c					\
		ft_replace_dollar.c			\
		ft_envp_to_envl.c			\
		ft_envl_utils.c				\
		ft_envl_utils2.c			\
		ft_pwd.c					\
		ft_check_tokenl.c			\
		ft_prep_exec.c				\
		ft_envl_to_envp.c			\
		ft_merge_block.c			\
		ft_heredoc.c				\
		ft_exec.c					\
		ft_set_absolute_path.c		\
		ft_echo.c					\
		ft_export.c					\
		ft_unset.c					\
		ft_cd.c						\
		ft_signal.c					\
		ft_check_expand.c			\
		ft_exec_utils.c				\
		ft_isbuiltins.c				\
		ft_builtins.c				\
		ft_exit.c					\
		ft_free.c					\
		ft_replace_dollar_utils.c	\
		ft_check_tokenl_utils.c 	\
		ft_error_msg.c				\

OBJS = $(SRCS:.c=.o)

PATH_OBJS	=	.objs/

F_OBJS		=	$(addprefix $(PATH_OBJS), $(OBJS))

DEPENDENCIES = $(SRCS:.c=.d)

CC = clang

INCLUDES = -I./includes -I./includes/libft
CFLAGS = -Wall -Wextra -Werror -g3 -MMD $(INCLUDES)

RM = rm -rf

all: $(PATH_OBJS) $(NAME)

$(NAME): $(F_OBJS) $(LIB)
	$(CC) $(CFLAGS) -g -lreadline -o $(NAME) $(F_OBJS) $(LIB) 

$(PATH_OBJS):	
	mkdir -p $(PATH_OBJS)

$(PATH_OBJS)%.o	:	%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIB): $(DIR_LIB)
	@make -C $(DIR_LIB)

clean:
	$(RM) $(F_OBJS) $(PATH_OBJS) $(DEPENDENCIES)
	$(MAKE) -C $(DIR_LIB) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIR_LIB) fclean

re: fclean all

-include $(DEPENDENCIES)

.PHONY: all clean fclean re
