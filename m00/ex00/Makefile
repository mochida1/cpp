NAME = megaphone
SRC = megaphone.cpp

all:
	@echo "\e[34m**** Compiling megaphone ****\n\e[0m"
	@c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp -o $(NAME)

clean:
	echo "nope"

fclean:
	rm $(NAME)

teste: all
	@echo "\e[34m\t**** Running tests ****\n\e[0m"
	@echo "\e[32mARG: 'abcdef0123456789'\e[0m"
	@./$(NAME) 'abcdef0123456789'
	@echo "\e[32mARG: \"abcdef\" \"0123456789\"\e[0m"
	@./$(NAME) "abcdef" "0123456789"
	@echo "\e[32mARG: \"abc \" \"def\" \"0123456789\" \" 0\" \" 1\" \" 2\" \" !\" \e[0m"
	@./$(NAME) "abc " "def " "0123456789" " 0" " 1" " 2" " !"
	@echo "\e[32mDamnit \" ! \" \"Sorry students, I thought this thing was off.\"\e[0m"
	@./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@echo "\e[32mNO ARGUMENTS\e[0m"
	@./$(NAME) && echo "\n\t\e[31mSHOULD'VE FAILED HERE!\e[0m\n" || echo "\n\e[34m\t**** Tests Done ****\n\e[0m"
