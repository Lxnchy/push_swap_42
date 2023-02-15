# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jehubert <jehubert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 15:38:49 by jehubert          #+#    #+#              #
#    Updated: 2023/02/15 14:15:34 by jehubert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

LIBFT = libft/libft.a

SRCS = srcs/moves.c \
		srcs/create_list.c \
		srcs/utils.c \
		srcs/main.c \
		srcs/three_case.c \
		srcs/t_move_utils.c \
		srcs/do_moves.c \
		srcs/max_sorted_list.c \
		srcs/push_b.c \
		srcs/lst_utils.c \
		srcs/fill.c \
		srcs/value_check.c \
		srcs/tab.c \
		srcs/clean.c \
		srcs/parsing.c

B_SRCS = srcs/checker_bonus.c \
		srcs/create_list.c \
		srcs/utils.c \
		srcs/lst_utils.c \
		srcs/clean.c \
		srcs/parsing.c \
		srcs/moves.c \
		srcs/moves_bonus.c \
		srcs/value_check.c \
		srcs/tab.c \
		srcs/max_sorted_list.c

OBJS = $(patsubst %,objs/%,$(notdir ${SRCS:.c=.o}))

B_OBJS = $(patsubst %,objs/%,$(notdir ${B_SRCS:.c=.o}))

CFLAGS = -Wall -Wextra -Werror -g3 -O0

objs/%.o : srcs/%.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	$(OBJS)
	make --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	echo "\e[2;21mMANDATORY DONE !"

${BONUS}:	$(OBJS) $(B_OBJS)
	make --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT) -o $(BONUS)
	echo "\e[2;21mBONUS DONE !"

all: $(NAME)

clean:
	make --no-print-directory -C ./libft clean
	rm -f $(OBJS) $(B_OBJS)
	echo "\e[2;21m.o FILES DELETED !"

fclean:	clean
	make --no-print-directory -C ./libft fclean
	rm -f $(NAME) $(BONUS)
	echo "\e[2;21mBINARY FILES DELETED !"

re: fclean all

bonus: $(BONUS)

.PHONY: all clean fclean re
.SILENT: $(OBJS) $(NAME) $(BONUS) $(B_OBJS) bonus all clean fclean re