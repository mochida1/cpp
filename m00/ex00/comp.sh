clear
c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp -o megaphone
echo "\e[32mNO ARGUMENTS\e[0m"
./megaphone
echo "\e[32mARG: 'abcdef0123456789'\e[0m"
./megaphone 'abcdef0123456789'
echo "\e[32mARG: \"abcdef\" \"0123456789\"\e[0m"
./megaphone "abcdef" "0123456789"
echo "\e[32mARG: \"abc \" \"def\" \"0123456789\" \" 0\" \" 1\" \" 2\" \" !\" \e[0m"
./megaphone "abc " "def " "0123456789" " 0" " 1" " 2" " !"
echo "\e[32mDamnit \" ! \" \"Sorry students, I thought this thing was off.\"\e[0m"
./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
