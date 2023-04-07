/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:28:47 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 17:50:32 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void no_arg(void)
{
	ScavTrap defConstr;
	ScavTrap argConstr(">>NAME<<");
	ScavTrap copyConstr(defConstr);
	ScavTrap opConstr;

	opConstr = argConstr;

	return ;
}

void clap(void)
{
	std::srand(std::time(NULL));
	int random;
	int turn = 0;
	ClapTrap trap("Cl4pTr4p");
	std::string target = "monster";

	while (!explode(trap))
	{
		std::cout << std::endl;
		std::cout << "\033[47;30m-------Turn: [" << turn << "] Rand: [" << random << "]-------\033[0m" << std::endl;
		turn++;
		std::cout << "\033[100;95m" + trap.getName() + "\tHP: " <<  trap.getHitPoints() << "\tEP: " << trap.getEnergyPoints() << "\tAD: " << trap.getAttackDamage() << "\033[0m" << std::endl;
		random = std::rand() % 3;
		// std::cout << "rand : [" << random << "]" << std::endl;
		if (random == 0)
			trap.attack(target);
		else if (random == 1)
			trap.beRepaired(1);
		else if (random == 2)
			trap.takeDamage(1);
	}

	return ;
}

void scav(void)
{
	std::cout << "\t\tRunning ScavTrap tests" << std::endl;
	std::srand(std::time(NULL));
	int random;
	int turn = 0;
	ScavTrap trap("Sc4vTr4p");
	std::string target = "monster";

	while (!explode(trap))
	{
		std::cout << std::endl;
		std::cout << "\033[47;30m-------Turn: [" << turn << "] Rand: [" << random << "]-------\033[0m" << std::endl;
		turn++;
		std::cout << "\033[100;95m" + trap.getName() + "\tHP: " <<  trap.getHitPoints() << "\tEP: " << trap.getEnergyPoints() << "\tAD: " << trap.getAttackDamage() << "\tGuard: " << trap.isGuardGate() <<"\033[0m" << std::endl;
		random = std::rand() % 5;
		// std::cout << "rand : [" << random << "]" << std::endl;
		if (random == 0)
			trap.attack(target);
		else if (random == 1)
			trap.beRepaired(1);
		else if (random == 2)
			trap.takeDamage(10);
		else if (random == 3)
			trap.guardGate();
		else if (random == 4)
			trap.toggleGuardGate();
	}

	return ;
}

void frag(void)
{
	std::cout << "\t\tRunning FragTrap tests" << std::endl;
	std::srand(std::time(NULL));
	int random;
	int turn = 0;
	FragTrap trap("Fr4vTr4p");
	std::string target = "monster";
	int monster_hp = 100;

	while (!explode(trap))
	{
		std::cout << std::endl;
		std::cout << "\033[47;30m-------Turn: [" << turn << "] Rand: [" << random << "]-------\033[0m" << std::endl;
		turn++;
		std::cout << "\033[100;95m" + trap.getName() + "\tHP: " <<  trap.getHitPoints() << "\tEP: " << trap.getEnergyPoints() << "\tAD: " << trap.getAttackDamage() << "\033[0m" << std::endl;
		random = std::rand() % 3;
		// std::cout << "rand : [" << random << "]" << std::endl;
		if (random == 0)
		{
			trap.attack(target);
			monster_hp -= trap.getAttackDamage();
			if (monster_hp <= 0)
			{
				trap.highFiveGuys();
				return ;
			}
		}
		else if (random == 1)
			trap.beRepaired(1);
		else if (random == 2)
			trap.takeDamage(30);
	}
	return ;
}

int main (int argc, char *argv[])
{
	std::string argument;
	if (argc > 2)
	{
		std::cerr << "Error: too many arguments." << std::endl;
		std::cerr << "Try [./claptrap] or [./claptrap scav] or [./claptrap frag]" << std::endl;
		return 1;
	}
	if (argc > 1)
		argument = argv[1];
	if (argc == 1)
		no_arg();
	else if (!argument.compare("clap"))
		clap();
	else if (!argument.compare("scav"))
		scav();
	else if (!argument.compare("frag"))
		frag();
	else
	{
		std::cerr << "invalid argument. Please type better." << std::endl;
		return 1;
	}
	return 0;
}
