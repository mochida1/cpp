/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:07:43 by mochida           #+#    #+#             */
/*   Updated: 2023/11/12 15:57:19 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "iostream"

int main (int argc, char *argv[])
{
		if (argc < 2 || argc > 2){
		std::cerr << "Wrong number of arguments" << std::endl;;
		return 1;
	}
	
	if (BitcoinExchange::validateFiles(argv[1])){
		return 1;
	}
	BitcoinExchange bc(argv[1]);
	bc.run();
}