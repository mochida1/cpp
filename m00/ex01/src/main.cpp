/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:49 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 14:56:30 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "FtStd.class.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	int		control;

	control = 1;

	int		max;
	max = 9;
	// PhoneBook.AutoAddSmall(max);

	while (control != 4)
	{
		control = PhoneBook.PromptUser();
		PhoneBook.DoAction(control);
	}

	for (int i = 0; i < max; i++)
	{
		PhoneBook.PrintContactData(i);
	}
	return (0);
}
