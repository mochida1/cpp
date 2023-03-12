/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:36:15 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 20:50:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>

int main (void)
{
	std::string memes[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"random",
		"info",
		"debug",
		"warning",
		"error",
		"derp",
		"lalala",
		"mmooo",
		"burger",
	};
	int len = *(&memes + 1) - memes;
	int random_number;
	Harl meme;
	while (1)
	{
		random_number = rand() % len;
		meme.complain(memes[random_number]);
	}
}
