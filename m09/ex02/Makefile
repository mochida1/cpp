# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mochida <mochida@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 13:42:57 by hmochida          #+#    #+#              #
#    Updated: 2023/11/23 22:07:15 by mochida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
MAKEFLAGS = --no-print-directory
BUILDDIR = objs
VPATH = src

# headers
INCLUDES = -I ./headers

# Lists sources. Manually because of norm...
MAIN = main.cpp PmergeMe.cpp

# Names sources
SOURCES = $(MAIN)

# Names objects
OBJS = $(addprefix $(BUILDDIR)/, $(SOURCES:%.cpp=%.o))

# Compiler
CC = c++
CF = -Wall -Wextra -Werror -std=c++98
GDB = -ggdb
GO = ./$(NAME) `shuf -i 1-22 -n 21 | tr "\n" " "`
VAL = valgrind --trace-children=no --leak-check=full --track-origins=yes \
		./$(NAME) `shuf -i 1-100000 -n 3001 | tr "\n" " "`
#		./$(NAME) 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
#		./$(NAME) 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
#		./$(NAME) `shuf -i 1-100000 -n 21 | tr "\n" " "`
#		./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`
#		./$(NAME) `shuf -i 1-100000 -n 12 | tr "\n" " "`
#		./$(NAME) 3 5 9 7 11 13 1 17 15 19 21

$(NAME): $(BUILDDIR) $(OBJS)
	@printf "Compiling $(NAME)\n"
	@$(CC) $(CF) $(OBJS) $(INCLUDES) -o $(NAME)
	@printf "Done!\n"

$(NAME_TEST): $(TEST_OBJS)
	@printf "Compiling test files...\n"
	@$(CC) $(CF) $(TEST_OBJS) $(INCLUDES) -o $(NAME_TEST)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: %.cpp
	@$(CC) $(CF) $(GDB) $(INCLUDES) -c $< -o $@

all: $(NAME)

test:
	@make -C tests/
	@printf "\n"
	@./tests/tester

clean:
	@rm -rf $(BUILDDIR)
	@rm -f vgcore*

fclean: clean
	@rm -f $(NAME)
	@rm -f vgcore*

re: fclean all

# from here on shit ain't mandatory or bonus
run: all
	$(VAL)

go: all
	$(GO)

fs: $(NAME_FS)
	./$(NAME_FS)

git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
