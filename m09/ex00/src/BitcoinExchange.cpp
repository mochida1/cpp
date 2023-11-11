/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:07:49 by mochida           #+#    #+#             */
/*   Updated: 2023/11/11 11:34:35 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//------------ OCF
BitcoinExchange::BitcoinExchange(void){
	this->_fileName = "";
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange & instance){
	*this = instance;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange & instance){
	this->_fileName = instance.getFileName();
	return *this;
}

BitcoinExchange::~BitcoinExchange(void){
	return ;
}
//------------
BitcoinExchange::BitcoinExchange(char *filename){
	this->_fileName = std::string(filename);
	return ;
}
BitcoinExchange::BitcoinExchange(std::string filename){
	this->_fileName = filename;
}

std::string BitcoinExchange::getFileName(void){
	return this->_fileName;	
}

int BitcoinExchange::validateFiles(char *file_name){
	struct stat input_file;
	struct stat data_file;
	std::string toParse(file_name);
	if (toParse.compare("data.csv") == 0){
		std::cerr << "ERROR! data.csv cannot be used as the input file!" << std::endl;
		return -1;
	}
	if (stat(file_name, &input_file) == -1){
		std::cerr << "File " + std::string(file_name) + " can't be accessed." << std::endl;
		return -1;
	}
	if (stat("data.csv", &data_file) == -1){
		std::cerr << "File data.csv can't be accessed at local directory." << std::endl;
		return -1;
	}
	std::fstream file;
	file.open(file_name, std::ios::in);
	if (file.is_open() == false){
		std::cerr << "File " + std::string(file_name) + " can't be opened." << std::endl;
		return -1;
	}
	file.close();

	//Parsing of data.csv
	if (file.is_open() == true){
		std::cerr << "Failed closing file at " << __FUNCTION__ <<"():" << __LINE__ << std::endl;
		return -1;
	}
	file.open("data.csv");
	if (file.is_open() == false){
		std::cerr << "File data.csv can't be open." << std::endl;
		return -1;
	}
		std::string toCompare;
	int lineCount = 0;
	while(getline(file, toCompare))
	{
		char dotCount = 0;
		lineCount++;
		if (lineCount == 1){
			if (toCompare.compare("date,exchange_rate"))
			{
				std::cerr << "Wrong data.csv formatting at line 1 : "<< toCompare.compare("date,exchange_rate") << std::endl;
				file.close();
				return -1;
			}
			continue;
		}
		// checks line formatting
		for (size_t i = 0; i < toCompare.length(); i++)
		{
			if (i == 4 || i == 7){
				if (toCompare[i] != '-'){
					std::cerr << "Wrong data.csv formatting at line [" << lineCount << "], column [" << i << "]: expected '-', found '" << toCompare[i] <<"'" << std::endl;
					file.close();
					return -1;
				}
				continue;
			}
			else if(i == 10){
				if (toCompare[i] != ',')
				{
					std::cerr << "Wrong data.csv formatting at line [" << lineCount << "], column [" << i << "]: expected ',', found '" << toCompare[i] <<"'" << std::endl;
					file.close();
					return -1;
				}
				continue;
			}
			else if (!std::isdigit(toCompare[i])){
				if (i >= 12 && toCompare[i] == '.' && isdigit(toCompare[i - 1]))
					if (i != toCompare.length() && isdigit(toCompare[i + 1])){ 
						dotCount++;
						if (dotCount < 2)
							continue;
					}
				std::cerr << "Wrong data.csv formatting at line [" << lineCount << "], column [" << i << "]: expected digit, found '" << toCompare[i] <<"'" << std::endl;
				file.close();
				return -1;
			}
		}
	}
	file.close();
	if (file.is_open() == true){
		std::cerr << "Failed closing file at " << __FUNCTION__ <<"():" << __LINE__ << std::endl;
		return -1;
	}
	return 0;
}

int BitcoinExchange::unitTests(void){
	
}