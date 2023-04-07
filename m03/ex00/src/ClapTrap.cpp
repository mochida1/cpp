/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:29:54 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 14:41:11 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "[ClapTrap] Default constructor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;

	return ;
}

ClapTrap::ClapTrap(ClapTrap const &instance)
{
	std::cout << "[ClapTrap] Copy constructor called" << std::endl;
	*this = instance;

	return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &instance)
{
	std::cout << "[ClapTrap] Copy assignment operator called" << std::endl;
	this->_name = instance.getName();
	this->_hitPoints = instance.getHitPoints();
	this->_attackDamage = instance.getAttackDamage();

	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "[ClapTrap] Default destructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Argument construcor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	return ;
}

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}

int	ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int	ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "\033[1;90m" + this->_name + " has no energy to attack..." + "\033[0m" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "\033[95m" + this->_name + " attacks " + target + " causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > INT_MAX)
	{
		std::cout << "Cheat mode is disabled. You can't do/take more than " << INT_MAX << " damage!" << std::endl;
		return ;
	}
	std::cout << "\033[31m" + this->_name + " has taken " << amount << " damage!\033[0m" << std::endl;
	this->_hitPoints -= (int) (amount);
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "\033[1;90m" + this->_name + " has no energy to repair itself..." + "\033[0m" << std::endl;
		return ;
	}
	this->_energyPoints--;
	if (amount > INT_MAX)
	{
		std::cout << "Cheat mode is disabled. You can't heal more than " << INT_MAX << " damage!" << std::endl;
		return ;
	}
	if ((this->_hitPoints + amount) > INT_MAX)
	{
		std::cout << this->_name + " has turned IDDQ on!" << std::endl;
		this->_hitPoints = INT_MAX;
		return ;
	}
	std::cout << "\033[1;92m" + this->_name + " is repaired by " << amount << "\033[0m" << std::endl;
	this->_hitPoints += (int) (amount);
	return ;
}

bool ClapTrap::isDead(void)
{
	if (this->_hitPoints > 0 )
		return false;
	std::cout << "\033[1;41m" + this->_name + " has died!" + "\033[0m" << std::endl;
	return true;
}

// ------------- nonmember functions

bool explode(ClapTrap &instance)
{
	if (instance.isDead())
	{
		std::cout << instance.getName() + " exploderized!" << std::endl;
		return true;
	}
	return false;
}
