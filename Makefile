# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbester <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 08:43:37 by cbester           #+#    #+#              #
#    Updated: 2018/08/24 09:14:26 by cbester          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM = lem-in
LIB_NAME = libft.a

FLAGS = -Wall -Wextra -Werror

FILE_DIR = ./includes/
LIB_DIR = ./libft/

FILE_NAMES = main.c step1.c step0.c step00.c free_all.c step2.c step3.c step4.c\
			 step000.c step01.c

LIBFT = $(addprefix $(LIB_DIR), $(LIB_NAME))
FILES = $(addprefix $(FILE_DIR), $(FILE_NAMES))

F_OBJ = $(FILES:.c=.o)

.PHONY: all clean fclean re norme

all: $(LEM)

$(LEM): $(LIB_NAME) $(F_OBJ)
	@gcc $(FLAGS) -o $(LEM) $(F_OBJ) $(LIBFT)
	@echo "\033[37mLem-in Built!\033[0m"

$(LIB_NAME):
	@make -C $(LIB_DIR)

%.o: %.c
	@echo "\033[36m[Creating\t$@]\033[0m"
	@gcc $(FLAGS) -c $< -o $@

norme:
	python pynorme.py

clean:
	@echo "\033[33mRemoving objects...\033[0m"
	@/bin/rm -f $(F_OBJ)
	@make clean -C $(LIB_DIR)
	@echo "\033[37mLem-in clean Complete!\033[0m"

fclean:
	@echo "\033[33mRemoving objects...\033[0m"
	@/bin/rm -f $(F_OBJ) $(LEM)
	@make fclean -C $(LIB_DIR)
	@echo "\033[37mLem-in fclean Complete!\033[0m"

re: fclean all
