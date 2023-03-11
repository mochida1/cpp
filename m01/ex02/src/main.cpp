/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:35:42 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 17:45:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <bits/stdc++.h>

int main (void)
{
	system ("clear");
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory address of the string variable:\t" << &str << std::endl;
	std::cout << "The memory address held by stringPTR:\t\t" << stringPTR << std::endl;
	std::cout <<  "The memory address held by stringREF:\t\t" << &stringREF << std::endl;

	std::cout << "---------------------------------------" << std::endl;

	std::cout << "The value of the string variable:\t\t" << str << std::endl;
	std::cout << "The value pointed to by stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:\t\t" << stringREF << std::endl;

	return (0);
}
