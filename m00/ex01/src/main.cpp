/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:49 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/15 22:12:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "FtStd.hpp"

int main(int argc, char *argv[])
{
	PhoneBook	PhoneBook;
	int		control;
	std::string argument;
	int		max;

	control = 1;
	max = 8;
	if (argc != 1)
	{
		argument = argv[1];
		if (!argument.compare("autoadd"))
		{
			std::cout << "Auto Add Called. Adding 8 serialized contacts to list" << std::endl;
			PhoneBook.AutoAddSmall(max);
		}
	}

	while (control != ACTION_EXIT)
	{
		control = PhoneBook.PromptUser();
		if (control == ACTION_EOF)
		{
			std::cout << "EOF detected. Now leaving" << std::endl;
			return 0;
		}
		PhoneBook.DoAction(control);

	}
	return (0);
}
