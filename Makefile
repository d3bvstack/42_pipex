# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbarba-v <dbarba-v@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/13 13:08:31 by dbarba-v          #+#    #+#              #
#    Updated: 2025/06/14 17:29:33 by dbarba-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f


INCLUDES = -I./include -I./libft/include
LIBS = -L./libft/lib -lft
LIBFT = ./libft/lib/libft.a

SRCS = 	src/errors/errors.c \
        src/execution/cmd.c \
        src/execution/launch.c \
        src/free/pipex.c \
        src/initialization/pipex_utils.c \
        src/initialization/pipex.c \
        src/validation/argc.c \
        src/main.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: cleanlibft
	$(RM) $(OBJS)

fclean: clean fcleanlibft
	$(RM) $(NAME)

cleanlibft:
	make -C ./libft/ clean

fcleanlibft: cleanlibft
	make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re libft cleanlibft fcleanlibft