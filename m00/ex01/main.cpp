/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:49 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 20:01:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "FtStd.class.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	int max;
	max = 8;

	PhoneBook.AutoAddSmall(max);
	for (int i = 0; i < max; i++)
		PhoneBook.PrintContactData(i);
	return (0);
}
