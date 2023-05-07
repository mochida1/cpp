/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:01:32 by hmochida          #+#    #+#             */
/*   Updated: 2023/05/06 21:38:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int idx = 0; idx < 100; idx++)
		this->_ideas[idx] = "";
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain & instance)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = instance;
	return ;
}

Brain & Brain::operator=(const Brain & instance)
{
	int	i;

	std::cout << "Brain copy operator constructor called" << std::endl;
	for (i = 0; i < 100; i++)
	{
		this->_ideas[i] = instance.getIdeas(i);
	}
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain default destructor called" << std::endl;
	return ;
}

Brain::Brain(std::string serialIdea)
{
	std::string temp;
	std::stringstream ss;
	for (int idx = 0; idx < 100; idx++)
	{
		ss.str("");
		ss.clear();
		ss << (idx + 1);
		temp = serialIdea + ss.str();
		this->_ideas[idx] = temp;
	}
	return ;
}

const std::string* Brain::getIdeas(void) const
{
	return this->_ideas;
}

const std::string Brain::getIdeas(int ideaIdx) const
{
	if (ideaIdx < 0 || ideaIdx > 99)
		return ("");
	return this->_ideas[ideaIdx];
}

void Brain::setIdeas(const std::string * ideas)
{
	for (int i = 0; i < 99; i++)
		this->_ideas[i] = ideas[i];
	return ;
}

void Brain::printIdeas(void) const
{
	for (int i = 0; i < 99; i++)
	{
		if (this->_ideas->compare("") )
			std::cout << this->_ideas[i] << std::endl;
	}
	return ;
}

void Brain::printIdeas(int idx) const
{
	std::cout << this->_ideas[idx] << std::endl;
	return ;
}

void Brain::printBrainAdress(void) const
{
	void *ptr = (void *)(this);
	std::cout << "Brain Address: " << ptr << std::endl;
	return ;
}

void Brain::printIdeasAdresses(void) const
{
	for (int i = 0; i < 99; i++)
		std::cout << &this->_ideas[i] << std::endl;
	return ;
}
