/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:55:57 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 13:24:28 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Teste.class.hpp"

int main (void)
{
	int nbr;

	std::cout << "Number of objects to initialize: ";
	std::cin >> nbr;
	Teste cl_inst[nbr];
	return (0);
}
