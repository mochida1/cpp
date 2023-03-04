/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:14:45 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/04 16:54:11 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "teste.class.hpp"

Teste::Teste(void)
{
	std::cout << "Constructed class" << std::endl;
	return;
}

Teste::~Teste(void)
{
	std::cout << "Destroyed class" << std::endl;
	return;
}

void	Teste::set_number(int number)
{
	this->number = number;
	return;
}

void	Teste::print_number(void)
{
	std::cout << "[int number]: " << this->number << std::endl;
}

void	Teste::set_charptr(char *ptr)
{
	this->charptr = ptr;
	return;
}

void	Teste::print_charptr(void)
{
	std::cout << "[char *charptr]: " << this->charptr << std::endl;
}

void	Teste::set_string(std::string str)
{
	this->str = str;
}

void	Teste::print_string(void)
{
	std::cout << "[string str]: " << this->str << std::endl;
}

int	main(void)
{
	Teste class_test_instance;
	char *test_charptr = (char *)("I am a char array :)");
	std::string	str = "Me be strong!";

	class_test_instance.set_number(24);
	class_test_instance.print_number();

	class_test_instance.set_charptr(test_charptr);
	class_test_instance.print_charptr();

	class_test_instance.set_string(str);
	class_test_instance.print_string();

	return (0);
}
