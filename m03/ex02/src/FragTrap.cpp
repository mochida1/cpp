/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:51:27 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 17:47:20 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "***\t[FragTrap] Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const &instance)
{
	std::cout << "***\t[FragTrap] Copy constructor called" << std::endl;
	*this = instance;

	return ;
}

FragTrap & FragTrap::operator=(const FragTrap &instance)
{
	std::cout << "***\t[FragTrap] Copy assignment operator called" << std::endl;
	this->_name = instance.getName();
	this->_hitPoints = instance.getHitPoints();
	this->_attackDamage = instance.getAttackDamage();

	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "***\t[FragTrap] Default destructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) // call constructors that initializes the _name variable by calling it's parent's argument constructor and inheriting it's name from it.
{
	std::cout << "***\t[FragTrap] Argument construcor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

void FragTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "\033[1;90m" + this->_name + " has no energy to attack..." + "\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[95m***\t" + this->_name + " swings at " + target + ", hitting for " << this->_attackDamage << "!\033[0m" << std::endl;
	this->_energyPoints--;
	return ;
}

void FragTrap::highFiveGuys(void)
{
	std::string	answ;
	std::cout << "High five guys!" << std::endl;
	while (1)
	{
		std::cout << "Do high five? (Y)es / (N)o ..." <<std::endl;
		std::getline(std::cin, answ);
		if (!answ.compare("Y") || !answ.compare("y") || !answ.compare("Yes") || !answ.compare("yes"))
			std::cout << "YAAAAYYY! BEST DAY EVER!" << std::endl;
		else if (!answ.compare("N") || !answ.compare("n") || !answ.compare("No") || !answ.compare("no"))
			std::cout << "Guys? Guys...? ...okay..." << std::endl;
		else
		{
			std::cout << "What? Didn't get that..." << std::endl;
			continue ;
		}
		break ;
	}
	return ;
}
