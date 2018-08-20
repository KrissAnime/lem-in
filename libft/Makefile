# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbester <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/21 08:58:42 by cbester           #+#    #+#              #
#    Updated: 2018/08/20 12:43:33 by cbester          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_FILE = main.c
FLAGS = -Wall -Wextra -Werror
COMPILER = gcc
NAME = libft.a
FILES_DIR = ./

FUNCTIONS = ft_bzero.c ft_memalloc.c ft_memchr.c ft_memcpy.c ft_memccpy.c\
			ft_memdel.c ft_memmove.c ft_memset.c ft_strclr.c ft_strdel.c\
			ft_striter.c ft_striteri.c ft_putendl.c ft_putendl_fd.c ft_putstr.c\
			ft_putstr_fd.c ft_putchar.c ft_putchar_fd.c ft_putnbr.c\
			ft_putnbr_fd.c ft_itoa.c ft_strcat.c ft_strchr.c ft_strrchr.c\
			ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strnew.c\
			ft_strdup.c ft_strsplit.c ft_strncpy.c ft_strcpy.c ft_strstr.c\
		   	ft_strsub.c ft_strtrim.c ft_strnstr.c ft_atoi.c ft_isalnum.c\
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memcmp.c\
			ft_tolower.c ft_toupper.c ft_strcmp.c ft_strequ.c ft_strlcat.c\
			ft_strlen.c ft_strncmp.c ft_strnequ.c ft_lstnew.c ft_lstdelone.c\
			ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_abs.c\
			get_next_line.c get_next_line_var.c ft_numlen.c ft_dubcheck.c\
			ft_array_size.c ft_findchar.c wdmatch.c ft_array_grow.c\
			free_array.c ft_array_shrink.c free_big_array.c new_array.c\
			print_array.c

FILES = $(addprefix $(FILES_DIR), $(FUNCTIONS))
OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "\033[37mCreating Library...\033[0m"
	@ar rcs $(NAME) $(OBJECTS)
	@ranlib	$(NAME)
	@echo "\033[37mLibrary Built!\033[0m"

%.o: %.c
	@echo "\033[32mCreating\t$@\033[0m"
	@$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	@echo "\033[33mRemoving object files...\033[0m"
	@/bin/rm -f $(OBJECTS)
	@echo "\033[33mRemoving libft.h.gch file\033[0m"
	@/bin/rm -f libft.h.gch
	@echo "\033[37mLibrary clean completed!\033[0m"

fclean:
	@echo "\033[33mRemoving object files...\033[0m"
	@/bin/rm -f $(OBJECTS)
	@echo "\033[33mRemoving libft.h.gch file\033[0m"
	@/bin/rm -f libft.h.gch
	@echo "\033[33mRemoving libft.a\033[0m"
	@/bin/rm -f $(NAME)
	@echo "\033[37mLibrary fclean completed!\033[0m"

re: fclean all
