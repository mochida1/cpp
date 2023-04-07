/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:28:47 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 16:28:24 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void is_arg(void)
{
	ScavTrap defConstr;
	ScavTrap argConstr(">>NAME<<");
	ScavTrap copyConstr(defConstr);
	ScavTrap opConstr;

	opConstr = argConstr;

	return ;
}

void no_arg(void)
{
	std::srand(std::time(NULL));
	int random;
	int turn = 0;
	ScavTrap trap("Tr4p");
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

int main (int argc, char *argv[])
{
	(void) (argv);
	if (argc == 1)
		no_arg();
	else
		is_arg();
	return 0;
}
