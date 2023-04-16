/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:05:36 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/15 22:25:44 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_ContactsFilled = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

bool	PhoneBook::Add(void) {
	int rc = 0;
	// std::cout << "Contacts filled: " << this->_ContactsFilled << std::endl;
	if (this->_ContactsFilled > 7)
		this->_ContactsFilled = 7;
	rc = this->_ContactArray[this->_ContactsFilled].SetContactData();
	if (rc != true)
		return rc;
	this->_ContactArray[this->_ContactsFilled].SetIndex(this->_ContactsFilled);

	if (this->_ContactsFilled < 8)
		this->_ContactsFilled++;
	return (true);


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
	int	lmax;
	int index;
	// std::cout << "contacts filled: " <<this->_ContactsFilled<<std::endl;
	if (this->_ContactsFilled == 0)
	{
		std::cerr << "No entries yet" << std::endl;
		return (true);
	}
std::cout << "CONTACTS FILLED:" << this->_ContactsFilled << std::endl;
	lmax = this->_ContactsFilled;
	if (this->_ContactsFilled > 8)
		lmax = 8;
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < lmax; i++)
	{
		print_format(ft_std::to_string(this->_ContactArray[i].GetIndex() + 1, 10), 0);
		print_format(this->_ContactArray[i].GetFirstName(), 0);
		print_format(this->_ContactArray[i].GetLastName(), 0);
		print_format(this->_ContactArray[i].GetNickname(), 1);
	}
	index = 0;
	while (index < 1 || index > this->_ContactsFilled)
	{
		index = this->_PromptForIndex();
		if (index == (-1 * (__INT32_MAX__) - 1))
			return (false);
		if (index < 1 || index > this->_ContactsFilled)
			std::cout << "Please insert an index between 1 and " << this->_ContactsFilled<< std::endl;
	}
	this->_PrintContact(index);
	return (true);
}

int		PhoneBook::_PromptForIndex(void)
{
	std::string str;
	int ret;
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cin.clear();
		return (-1 * (__INT32_MAX__) - 1);
	}
	ret = ft_std::stoi(str);
	return ret;
}

void	PhoneBook::_PrintContact(int index) const
{
	(void) (index);
	std::cout << "Print contact here" << std::endl;
}

int		PhoneBook::PromptUser(void) {
	std::string str;

	std::cout << "Please choose an option: <ADD>, <SEARCH>, <EXIT>" << std::endl;
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (ACTION_EOF);
	if (str.compare("ADD") == 0)
		return (ACTION_ADD);
	if (str.compare("SEARCH") == 0)
		return (ACTION_SEARCH);
	if (str.compare("EXIT") == 0)
		return (ACTION_EXIT);
	else
		return 0;
}

bool	PhoneBook::DoAction (int control) {
	if (control == ACTION_ADD)
	{
		std::cout << "ACTION ADD" << std::endl;
		if (this->Add())
			return (true);
	}
	if (control == ACTION_SEARCH)
	{
		std::cout << "ACTION SEARCH" << std::endl;
		if (this->Search())
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
		this->_ContactArray[i].SetFirstName("FN [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[i].SetLastName("LN [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[i].SetNickname("NN [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[i].SetPhoneNumber("123 [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[i].SetDarkestSecret("BOO [" + ft_std.to_string(i, 10) + "]");
		this->_ContactArray[i].SetIndex(i);
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
	std::cout << "----------------------------------------" << std::endl;
}
