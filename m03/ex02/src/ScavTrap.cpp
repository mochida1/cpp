/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:28:24 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 16:16:41 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << ">>\t[ScavTrap] Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &instance)
{
	std::cout << ">>\t[ScavTrap] Copy constructor called" << std::endl;
	*this = instance;

	return ;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &instance)
{
	std::cout << ">>\t[ScavTrap] Copy assignment operator called" << std::endl;
	this->_name = instance.getName();
	this->_hitPoints = instance.getHitPoints();
	this->_attackDamage = instance.getAttackDamage();

	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << ">>\t[ScavTrap] Default destructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) // call constructors that initializes the _name variable by calling it's parent's argument constructor and inheriting it's name from it.
{
	std::cout << ">>\t[ScavTrap] Argument construcor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "\033[1;90m" + this->_name + " has no energy to attack..." + "\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[95m>>\t" + this->_name + " swings at " + target + ", hitting for " << this->_attackDamage << "!" << std::endl;
	this->_energyPoints--;
	return ;
}

void ScavTrap::guardGate(void)
{
	if (this->_isGuardGate != true)
	{
		this->_isGuardGate = true;
		std::cout << this->_name + " is now guarding the gate!" << std::endl;
		return ;
	}
	std::cout << this->_name + " is already guarding a gate!" << std::endl;
	return ;
}

void ScavTrap::toggleGuardGate(void)
{
	if (this->_isGuardGate == true)
	{
		std::cout << this->_name + " is no longer guarding a gate" << std::endl;
		this->_isGuardGate = false;
		return ;
	}
	this->guardGate();
	return ;
}

bool ScavTrap::isGuardGate(void)
{
	return this->_isGuardGate;
}
