/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Teste.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:59:06 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 13:21:53 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Teste.class.hpp"

int Teste::_instance_nbr = 0;

Teste::Teste(void)
{
	std::cout << "Constructing teste class instance " << this->_instance_nbr << std::endl;
	this->_instance_nbr++;
	return ;
}

Teste::~Teste(void)
{
	this->_instance_nbr--;
	std::cout << "Destroying teste class instance " << this->_instance_nbr << std::endl;
	return ;
}
