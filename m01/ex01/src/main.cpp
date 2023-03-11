/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:30:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 17:27:55 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int main(void)
{
	Zombie *horde = zombieHorde(42, ("zombie"));
	Zombie *steve = new Zombie("Steve");
	Zombie Fred("Fred is temporary");
	Fred.announce();
	steve->announce();
	delete [] horde;
	delete steve;
}
