/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:30:18 by mochida           #+#    #+#             */
/*   Updated: 2023/11/12 19:25:40 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char *argv[]){
	if (argc != 2)
	{
		std::cerr << "ERROR: Wrong input!" << std::endl;
		return 1;
	}
	std::string input(argv[1]);
	if (input.compare("subject")){
		if (RPN::validateInput(input) == false)
		{
			std::cerr << "Preparsing error: Bad input!" << std::endl;
			return 1;
		}
		RPN rpn(input);
		rpn.run();
		return 0;
	}
	

	RPN rpn1(std::string("8 9 * 9 - 9 - 9 - 4 - 1 +")); //42
	rpn1.setVerbose(true);
	rpn1.run();
	std::cout << "expected 42\n" << std::endl;

	RPN rpn2(std::string("7 7 * 7 -")); //42
	rpn2.setVerbose(true);
	rpn2.run();
	std::cout << "expected 42\n" << std::endl;

	RPN rpn3(std::string("1 2 * 2 / 2 * 2 4 - +"));
	rpn3.setVerbose(true);
	rpn3.run();
	std::cout << "expected 0\n" << std::endl;

	RPN rpn4(std::string("(1 + 1)"));
	rpn4.setVerbose(true);
	rpn4.run();
	std::cout << "expected error (note that this was not preparsed as a command line argument)\n" << std::endl;

	RPN rpn5(std::string("12 8 - 3 * 6 / 2 + 20 * + +"));
	rpn5.setVerbose(true);
	rpn5.run();
	std::cout << "expected 0\n" << std::endl;


	// validator at: https://www.dcode.fr/reverse-polish-notation 
	return 0;	
}