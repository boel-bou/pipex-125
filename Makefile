# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 12:40:42 by boel-bou          #+#    #+#              #
#    Updated: 2024/01/31 12:40:46 by boel-bou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BONUS = pipex_bonus

SRC = ft_split.c pipex.c process_child_one.c process_child_two.c search_path.c \
	utils.c utils2.c utils3.c

SRC_BONUS = pipex_bonus.c process_child_bonus.c search_path.c ft_split.c utils2.c \
	utils.c process_child_one.c process_child_two.c get_next_line.c functions1_bonus.c \
	functions2_bonus.c process_child_one_bonus.c process_child_two_bonus.c close_functions.c \
	utils3.c process_child_heredoc.c

CC = cc 

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_BONUS) : $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)	

clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)
	rm -rf $(NAME_BONUS)

re : fclean all

.PHONY : all clean fclean re bonus
