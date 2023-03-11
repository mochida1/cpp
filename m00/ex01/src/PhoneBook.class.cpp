/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:42:52 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 22:24:30 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {
	this->_ContactsFilled = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

bool	PhoneBook::Add(void) {
	std::cout << "Contacts filled: " << this->_ContactsFilled << std::endl;
	if (this->_ContactsFilled > 8)
	{
		this->_ContactsFilled = 8;
		if (this->_ContactArray[this->_ContactsFilled - 1].SetContactData() == false)
			return (false);
		if (this->_ContactArray[this->_ContactsFilled - 1].SetIndex(this->_ContactsFilled) == false)
			return (false);
		else
			return (true);
	}
	if (this->_ContactArray[this->_ContactsFilled - 1].SetContactData() == false)
		return (false);
	if (this->_ContactArray[this->_ContactsFilled - 1].SetIndex(this->_ContactsFilled) == false)
		return (false);
	else
	{
		this->_ContactsFilled++;
		return (true);
	}

}

void print_format(std::string str, int is_end)
{
	int	to_fill;
	if (str.length() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	to_fill = 10 - str.length();
	if (to_fill > 0)
	{
		str.insert(0, to_fill, ' ');
	}
	if (str.length() == 10)
		std::cout << str;
	if (is_end == false)
		std::cout << "|";
	else
		std::cout << std::endl;

}

/*
index, first name, last name and nickname
Each column must be 10 characters wide. A pipe character (’|’) separates
them. The text must be right-aligned. If the text is longer than the column,
it must be truncated and the last displayable character must be replaced by a
dot (’.’).
*/
bool	PhoneBook::Search(void) {
	ft_std ft_std;
	int	lmax;
	std::cout << "contacts filled: " <<this->_ContactsFilled<<std::endl;
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	if (this->_ContactsFilled == 0)
		return (false);
	lmax = this->_ContactsFilled;
	if (this->_ContactsFilled > 8)
		lmax = 8;
	for (int i = 0; i < lmax; i++)
	{
		print_format(ft_std.to_string(this->_ContactArray[i].GetIndex(), 10), 0);
		print_format(this->_ContactArray[i].GetFirstName(), 0);
		print_format(this->_ContactArray[i].GetLastName(), 0);
		print_format(this->_ContactArray[i].GetNickname(), 1);
	}
	return (true);
}

int		PhoneBook::PromptUser(void) {
	std::string str;

	std::cout << "Please choose an option: <ADD>, <SEARCH>, <EXIT>" << std::endl;
	std::getline(std::cin, str);
	if (str.compare("ADD") == 0)
		return (ACTION_ADD);
	if (str.compare("SEARCH") == 0)
		return (ACTION_SEARCH);
	if (str.compare("EXIT") == 0)
		return (ACTION_EXIT);
	else
		return (false);
}

bool	PhoneBook::DoAction (int control) {
	if (control == ACTION_ADD)
	{
		std::cout << "ACTION ADD" << std::endl;
		this->Add();
		return (true);
	}
	if (control == ACTION_SEARCH)
	{
		std::cout << "ACTION SEARCH" << std::endl;
		this->Search();
		return (true);
	}
	if (control == ACTION_EXIT)
	{
		std::cout << "ACTION EXIT" << std::endl;
		return (true);
	}
	std::cout << "ACTION FAILED" << std::endl;
	return (false);
}

bool	PhoneBook::AutoAddSmall(int number_of_contacts) {
	ft_std	ft_std;
	for (int i = 0; i < number_of_contacts; i++)
	{
		int j = i;
		if (i > 7)
			j = 7;
		this->_ContactArray[j].SetFirstName("FN [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[j].SetLastName("LN [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[j].SetNickname("NN [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[j].SetPhoneNumber("123 [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[j].SetDarkestSecret("BOO [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[j].SetIndex(i);
		if (this->_ContactsFilled < 8)
			this->_ContactsFilled++;
	}
	return (true);
}

void	PhoneBook::PrintContactData(int index) {
	if (index > 7)
		index = 7;
	std::cout << "Printing object [" << index << "] stuff." << std::endl;
	std::cout << this->_ContactArray[index].GetIndex() << std::endl;
	std::cout << this->_ContactArray[index].GetFirstName() << std::endl;
	std::cout << this->_ContactArray[index].GetLastName() << std::endl;
	std::cout << this->_ContactArray[index].GetNickname() << std::endl;
	std::cout << this->_ContactArray[index].GetPhoneNumber() << std::endl;
	std::cout << this->_ContactArray[index].GetDarkestSecret() << std::endl;
}
