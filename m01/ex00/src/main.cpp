/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:20 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 21:40:31 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "Zombie.h"

int	main(void)
{
	Zombie *fred;
	fred = newZombie("fred");
	randomChump("NPC");
	Zombie george("George");
	george.announce();
	george.~Zombie();
	new (&george) Zombie("Bill");
	george.announce();

	/*
		NPC does not exists outside of randomChump scope.
		Objects are a variable, and as such, when not allocated to the heap
		or not declared as static, are destroyed afterwards.
	*/
	fred->announce();

	delete fred;
}
