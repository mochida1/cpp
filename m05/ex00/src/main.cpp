/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:56:58 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/03 19:40:00 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int test_constructors(void)
{
	try
	{
		std::cout << "\nMain : creating [def] at stack\t\t(default constructor)" << std::endl;
		Bureaucrat def;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught:\t" << e.what() << std::endl;
		return 1;
	}
	std::cout << "\nMain : creating [argus] at stack\t\t(argument constructor)" << std::endl;
	Bureaucrat argus("Argus" , 15);

	std::cout << "\nMain : copying FROM [argus] TO [def]" << std::endl;
	def = argus;

	std::cout << "\nMain : creating [copycon](argus) at stack\t\t(copy constructor)" << std::endl;
	Bureaucrat copycon(argus);

	std::cout << "\ndef is:\t\t" << def << std::endl;
	std::cout << "argus is:\t" << argus << std::endl;
	std::cout << "copycon is:\t" << copycon << std::endl;
}

int check_rc(int rc)
{
	if (rc == 0)
		return 0;
	else if (rc & 1)
	{

	}
}

int main (int argc, char *argv[])
{
	int rc;

	rc = 0;
	if (argc == 1)
		rc = test_constructors();
	if (check_rc(rc))
		return 1;

	return 0;
}
