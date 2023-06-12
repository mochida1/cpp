/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:23:17 by hmochida          #+#    #+#             */
/*   Updated: 2023/06/11 20:51:26 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main (int argc, char *argv[]){
	char tests = 0;
	if (argc != 2)
	{
		std::cerr << "ERROR! Try again with valid inputs" << std::endl;
		return 1;
	}

	std::string argument(argv[1]);
	if (tests)
	{
		if (!ScalarConverter::tests())
			return 1;
	}
	if (!ScalarConverter::convert(argument))
	{
		std::cerr << "Error! Wrong input format!" << std::endl;
		return 2;
	}
}

