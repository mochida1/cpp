/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:06:05 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 19:54:44 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


#include <iostream>

int main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "------------" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "------------" << std::endl;
	{
		Weapon club = Weapon("Zap Gun");

		HumanB bill("Bill");
		bill.attack();
		std::cout << "* " << bill.getName() << " picks up a " << club.getType() << " from the ground." << std::endl;
		bill.setWeapon(club);
		bill.attack();

		HumanA ted("Ted", club);
		ted.attack();
		std::cout << "** All guns are evolving...." << std::endl;
		club.setType("LAZORS");
		bill.attack();
		ted.attack();
	}
	std::cout << "------------" << std::endl;
	return (0);
}

