# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 13:42:57 by hmochida          #+#    #+#              #
#    Updated: 2023/03/12 18:31:42 by hmochida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = unsed
MAKEFLAGS = --no-print-directory
BUILDDIR = objs
VPATH = src

# headers
INCLUDES = -I ./headers

# Lists sources. Manually because of norm...
MAIN = main.cpp Unsed.class.cpp Parser.class.cpp

# Names sources
SOURCES = $(MAIN)

# Names objects
OBJS = $(addprefix $(BUILDDIR)/, $(SOURCES:%.cpp=%.o))

# Compiler
CC = c++
CF = -Wall -Wextra -Werror -std=c++98
GDB = -ggdb
VAL = valgrind --trace-children=no --leak-check=full --track-origins=yes \
		./$(NAME)

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
	@rm -rf *.replace
	@rm -f vgcore*

fclean: clean
	@rm -f $(NAME)
	@rm -rf *.replace
	@rm -f vgcore*

re: fclean all

# from here on shit ain't mandatory or bonus
run: all
	$(VAL)

fs: $(NAME_FS)
	./$(NAME_FS)

git: fclean
	git add -A
	git commit -m "make git"
	git push

PHONY:	all clean fclean re run
