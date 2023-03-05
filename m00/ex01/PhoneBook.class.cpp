/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:52 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 19:55:36 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	this->_ContactsFilled = 0;
	std::cout << "Creating PhoneBook" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "Destroying PhoneBook" << std::endl;
	return ;
}

bool	PhoneBook::Add(void) {
	std::cout << "Contacts filled: " << this->_ContactsFilled << std::endl;
	if (this->_ContactsFilled == 7)
	{
		if (this->_ContactArray[this->_ContactsFilled].SetContactData() == false)
			return (false);
		if (this->_ContactArray[this->_ContactsFilled].SetIndex(this->_ContactsFilled) == false)
			return (false);
		else
			return (true);
	}
	if (this->_ContactArray[this->_ContactsFilled].SetContactData() == false)
		return (false);
	if (this->_ContactArray[this->_ContactsFilled].SetIndex(this->_ContactsFilled) == false)
		return (false);
	else
	{
		this->_ContactsFilled++;
		return (true);
	}

}

bool	PhoneBook::AutoAddSmall(int number_of_contacts) {
	ft_std	ft_std;
	for (int i = 0; i < number_of_contacts; i++)
	{
		this->_ContactArray[i].SetFirstName("FN" + ft_std.to_string(i, 10));
		this->_ContactArray[i].SetLastName("LN" + ft_std.to_string(i, 10));
		this->_ContactArray[i].SetNickname("NN" + ft_std.to_string(i, 10));
		this->_ContactArray[i].SetPhoneNumber("123 " + ft_std.to_string(i, 10));
		this->_ContactArray[i].SetDarkestSecret("BOO" + ft_std.to_string(i, 10));
	}
	return (true);
}

void	PhoneBook::PrintContactData(int index) {
	std::cout << "Printing object [" << this->_ContactArray[index].GetIndex() << "] stuff." << std::endl;
	std::cout << this->_ContactArray[index].GetFirstName() << std::endl;
	std::cout << this->_ContactArray[index].GetLastName() << std::endl;
	std::cout << this->_ContactArray[index].GetNickname() << std::endl;
	std::cout << this->_ContactArray[index].GetPhoneNumber() << std::endl;
	std::cout << this->_ContactArray[index].GetDarkestSecret() << std::endl;
}
