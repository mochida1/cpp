/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:49 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/15 18:57:47 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "FtStd.hpp"

int main(int argc, char *argv[])
{
	PhoneBook	PhoneBook;
	int		control;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:49 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/15 17:28:52 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "FtStd.hpp"

int main(int argc, char *argv[])
{
	PhoneBook	PhoneBook;
	int		control;
	std::string argument;

	control = 1;

	int		max;
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

	std::string argument;

	control = 1;

	int		max;
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
