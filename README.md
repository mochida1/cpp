# cpp
clear && c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o test_bin && valgrind --leak-check=full --trace-children=yes --track-origins=yes ./test_bin
