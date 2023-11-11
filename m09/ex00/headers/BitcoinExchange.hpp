/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:07:53 by mochida           #+#    #+#             */
/*   Updated: 2023/11/11 11:34:27 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include "fstream"
#include "sys/stat.h"

class BitcoinExchange{
public:
	//------------ OCF
	BitcoinExchange(void); //default
	BitcoinExchange(BitcoinExchange & instance); //copy
	BitcoinExchange & operator=(BitcoinExchange & instance); //copy operator
	~BitcoinExchange(void); // default destructor
	//------------
	BitcoinExchange(char *filename);
	BitcoinExchange(std::string filename);
	static int validateFiles(char *file_name);
	std::string getFileName(void);
	int uintTests();
protected:
private:
	std::string _fileName;
};

#endif //BITCOINEXCHANGE_HPP