/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:30:06 by mochida           #+#    #+#             */
/*   Updated: 2023/11/12 19:26:41 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input) : _input(input){
	this->_verbose = false;
	return ;
}
RPN::~RPN(void){
	return ;
}

void RPN::printInput(void){
	std::cout << this->_input << std::endl;
}

bool RPN::validateInput(std::string input){
	const std::string validChars = " /*-+";
	bool numberFlag = false;
	size_t pos = 0;
	for (std::string::iterator i = input.begin(); i != input.end(); i++)
	{
		if (!isdigit(*i))
		{
			size_t loc = validChars.find(*i, 0);
		 	if (*i == 0 && loc == 0){
				std::cerr << "First char in argument is not a digit" << std::endl;
				return false;
			}
			if (loc == std::string::npos){
				std::cerr << "Invalid character in argument: [" << *i << "]" << std::endl;
				return false;
			}
			numberFlag = false;
		}
		else if (numberFlag == false)
		{
			int compare = 15000;
			std::string substr = input.substr(pos);
			std::stringstream ss;
			ss << substr;
			ss >> compare;
			if (compare > 9)
			{
				std::cerr << "Invalid value in argument" << std::endl;
				return false;
			}
		}
		pos++;
	}
	return true;
}

void RPN::setVerbose(bool status){
	this->_verbose = status;
}

void RPN::run(void){
	std::deque<int> stack;
	size_t pos = 0;
	int temp = 0;
	int temp2 = 0;
	if (this->_verbose)
		std::cout << "input: [" << this->_input << "]" << std::endl;
	for (std::string::iterator it = this->_input.begin(); it != this->_input.end(); it++)
	{
		if (std::isdigit(*it)){
			temp = *it - '0';
			stack.push_front(temp);
		}
		else if (*it == ' '){
			pos++;
			continue;
		}
		else if (*it == '+'){
			if (this->_verbose)
				std::cout << "add ";

			temp = *stack.begin();
			if (this->_verbose)
				std::cout << *stack.begin();
			stack.pop_front();

			temp += *stack.begin();
			if (this->_verbose)
				std::cout << " + " << *stack.begin() << " = " << temp << std::endl;
			stack.pop_front();

			stack.push_front(temp);
		}
		else if (*it == '-')
		{
			if (this->_verbose)
				std::cout << "sub ";

			temp = *stack.begin();
			if (this->_verbose)
				std::cout << *stack.begin();
			stack.pop_front();

			temp2 = *stack.begin();
			if (this->_verbose)
				std::cout << " - " << *stack.begin() << " = " << temp << std::endl;
			stack.pop_front();

			stack.push_front(temp2 -temp);
		}
		else if (*it == '*')
		{
			if (this->_verbose)
				std::cout << "mul ";

			temp = *stack.begin();
			if (this->_verbose)
				std::cout << *stack.begin();
			stack.pop_front();

			temp *= *stack.begin();
			if (this->_verbose)
				std::cout << " * " << *stack.begin() << " = " << temp << std::endl;
			stack.pop_front();

			stack.push_front(temp);
		}
		else if (*it == '/')
		{
			if (this->_verbose)
				std::cout << "div ";

			temp = *stack.begin();
			if (this->_verbose)
				std::cout<< *stack.begin();
			stack.pop_front();

			temp2 = *stack.begin();
			if (this->_verbose)
				std::cout << " / " << *stack.begin() << " = " << temp << std::endl;
			stack.pop_front();

			stack.push_front(temp2 / temp);
		}
		else{
			std::cerr << "Error: somehow you fucked up!" << std::endl;
			return ;
		}
		pos++;
	}
	std::cout << *stack.begin() << std::endl;
}