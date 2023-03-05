/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:49 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 18:02:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

int main(void)
{
	PhoneBook PhoneBook;
	Contact ctc;
	if (!ctc.SetContactData())
		return (1);

	std::cout << "Printing object stuff." << std::endl;
	std::cout << ctc.GetFirstName() << std::endl;
	std::cout << ctc.GetLastName() << std::endl;
	std::cout << ctc.GetNickname() << std::endl;
	std::cout << ctc.GetPhoneNumber() << std::endl;
	std::cout << ctc.GetDarkestSecret() << std::endl;
	return (0);
}
