/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:44 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/15 18:23:12 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	std::cout << "Constructing contact " << std::endl;
}

Contact::~Contact(void) {
	std::cout << "Destroying contact " << std::endl;
}

bool		Contact::SetFirstName(std::string str) {
	this->_FirstName = str;
	if (this->_FirstName.compare(str))
		return (true);
	return (false);
}

bool		Contact::SetLastName(std::string str) {
	this->_LastName = str;
	if (this->_LastName.compare(str))
		return (true);
	return (false);
}

bool		Contact::SetNickname(std::string str) {
	this->_Nickname = str;
	if (this->_Nickname.compare(str))
		return (true);
	return (false);
}

bool		Contact::SetPhoneNumber(std::string str) {
	this->_PhoneNumber = str;
	if (this->_PhoneNumber.compare(str))
		return (true);
	return (false);
}

bool		Contact::SetDarkestSecret(std::string str) {
	this->_DarkestSecret = str;
	if (this->_DarkestSecret.compare(str))
		return (true);
	return (false);
}

bool		Contact::SetIndex(int index) {
	if (index > 7)
		index = 7;
	this->_Index = index;
	if(this->_Index == index)
		return (true);
	return (false);
}

bool		Contact::_ParseUserInput(std::string str)
{
	if (str.empty())
	{
		std::cerr << "Error: please insert a value" << std::endl;
		return (false);
	}
	if (ft_std::isOnlySpace(str))
	{
		std::cerr << "Error: input can't be comprised of only spaces" << std::endl;
		return (false);
	}

	return (true);
}

bool		Contact::_ParsePhoneNumber(std::string str)
{
	std::cout << "AQUI!!!!" << std::endl;
	size_t i = str.find_first_not_of(' ', 0);
	if (i == (size_t) (-1))
		i = 0;
	else
	{
		if (str[i] == '+')
			i++;
	}

	for (; i < str.length(); i++)
	{
		if (std::isalpha(str[i]))
		{
			std::cerr << "Please input a valid phone number" << std::endl;
			return false;
		}
	}
	return true;
}

int		Contact::SetContactData(void) {
	std::string	lFirstName;
	std::string	lLastName;
	std::string	lNickname;
	std::string	lPhoneNumber;
	std::string	lDarkestSecret;

std::cout << "INDEX: ["<< this->_Index << "]" << std::endl;
	std::cout << "Please insert first name: ";
	std::getline(std::cin, lFirstName);
	if (std::cin.eof())
		return -1;
	if (!this->_ParseUserInput(lFirstName))
		return (false);

	std::cout << "Please insert last name: ";
	std::getline(std::cin, lLastName);
	if (std::cin.eof())
		return -1;
	if (!this->_ParseUserInput(lLastName))
		return (false);

	std::cout << "Please insert nickname: ";
	std::getline(std::cin, lNickname);
	if (std::cin.eof())
		return -1;
	if (!this->_ParseUserInput(lNickname))
		return (false);

	std::cout << "Please insert phone number: ";
	std::getline(std::cin, lPhoneNumber);
	if (std::cin.eof())
		return -1;
	if (this->_ParseUserInput(lPhoneNumber) == false)
		return (false);
	if (this->_ParsePhoneNumber(lPhoneNumber) == false)
		return(false);

	std::cout << "Please insert darkest secret: ";
	std::getline(std::cin, lDarkestSecret);
	if (std::cin.eof())
		return -1;
	if (!this->_ParseUserInput(lDarkestSecret))
		return (false);

	this->SetFirstName(lFirstName);
	this->SetLastName(lLastName);
	this->SetNickname(lNickname);
	this->SetPhoneNumber(lPhoneNumber);
	this->SetDarkestSecret(lDarkestSecret);
	return (true);
}

int			Contact::GetIndex(void) const {
	return (this->_Index);
}

std::string	Contact::GetFirstName(void) const {
	return (this->_FirstName);
}

std::string	Contact::GetLastName(void) const {
	return (this->_LastName);
}

std::string	Contact::GetNickname(void) const {
	return (this->_Nickname);
}

std::string	Contact::GetPhoneNumber(void) const {
	return (this->_PhoneNumber);
}

std::string	Contact::GetDarkestSecret(void) const {
	return (this->_DarkestSecret);
}
