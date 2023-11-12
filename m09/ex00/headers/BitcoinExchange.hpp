/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:07:53 by mochida           #+#    #+#             */
/*   Updated: 2023/11/12 16:16:30 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include "cassert"
#include "cstdlib" // system()
#include <set>
#include "fstream"
#include "sys/stat.h"
#include<sstream>

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

	// ----------- Getters
	std::string getFileName(void);
	std::string getCsvFileName(void);
	int getTotalCsvLines(void);
	std::set<std::string> getCsvData(void);
	// ----------- Setters

	// ----------- Tests
	static int validateFiles(char *file_name);
	static int testConstructors(void);
	int testSet(void);
	void run(void);
protected:
private:
	std::string _csvFileName;
	std::string _fileName;
	int _totalCsvLines;
	std::set<std::string> _csvData;
	// ----------- Methods
	int _readTotalCsvLines(void);
	std::set<std::string> _populateCsvData(void);
	std::string _readCurrentInputLine(void);
};

#endif //BITCOINEXCHANGE_HPP