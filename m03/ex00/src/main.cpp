/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:28:47 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 14:38:50 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main (void)
{
	std::srand(std::time(NULL));
	int random;
	int turn = 0;
	ClapTrap trap("Tr4p");
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

	return 1;
}
