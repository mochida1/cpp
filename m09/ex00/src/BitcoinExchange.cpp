/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:07:49 by mochida           #+#    #+#             */
/*   Updated: 2023/11/12 16:18:18 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//------------ OCF
BitcoinExchange::BitcoinExchange(void){
	this->_fileName = "";
	this->_csvFileName = "data.csv";
	this->_totalCsvLines = this->_readTotalCsvLines();
	this->_csvData = this->_populateCsvData();
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange & instance){
	*this = instance;
	return ;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange & instance){
	this->_fileName = instance.getFileName();
	this->_csvFileName = instance.getCsvFileName();
	this->_totalCsvLines = instance.getTotalCsvLines();
	this->_csvData = instance.getCsvData();
	return *this;
}

BitcoinExchange::~BitcoinExchange(void){
	return ;
}
//------------
BitcoinExchange::BitcoinExchange(char *filename){
	this->_fileName = std::string(filename);
	this->_csvFileName = "data.csv";
	this->_totalCsvLines = this->_readTotalCsvLines();
	this->_csvData = this->_populateCsvData();
	return ;
}
BitcoinExchange::BitcoinExchange(std::string filename){
	this->_fileName = filename;
	this->_csvFileName = "data.csv";
	this->_totalCsvLines = this->_readTotalCsvLines();
	this->_csvData = this->_populateCsvData();
	return ;
}

// ----------------------------- GETTERS 

std::string BitcoinExchange::getFileName(void){
	return this->_fileName;	
}

std::string BitcoinExchange::getCsvFileName(void){
	return this->_csvFileName;
}

int BitcoinExchange::getTotalCsvLines(void){
	return this->_totalCsvLines;
}

std::set<std::string> BitcoinExchange::getCsvData(void){
	return this->_csvData;
}

// ----------------------------------------- TESTS

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

	// input file
	std::string toCompare;
	std::fstream file;
	int lineCount = 0;
	file.open(file_name, std::ios::in);
	if (file.is_open() == false){
		
		std::cerr << "File " + std::string(file_name) + " can't be opened." << std::endl;
		return -1;
	}
	while(getline(file, toCompare)){
		int dotCount = 0;
		lineCount++;
		if (lineCount == 1){
			if (toCompare.compare("date | value")){
				std::cerr << "Wrong data.csv formatting at line 1. Expected \"date | value\", found: [" << toCompare << "]" << std::endl;
				file.clear();
				file.seekg(0);
				file.close();
				return -1;
			}
			continue;
		}
		for (size_t i = 0; i < toCompare.length(); i++){
			if(i == 4 || i == 7){
				if (toCompare[i] != '-'){
					std::cerr << "Wrong input file formatting at line ["<< lineCount <<"] expected '-', found '"<< toCompare[i]<< "'" << std::endl;
					file.clear();
					file.seekg(0);
					file.close();
					return -1;
				}
				continue;
			}
			if (i==10){
				if(toCompare[i] != ' ' || toCompare.length() < (size_t)(i+2) || (toCompare[i+1] != '|' || toCompare[i+2] != ' ')) {
					std::cerr << "Error! Wrong input file formatting at line ["<< lineCount <<"]" << std::endl;
					file.clear();
					file.seekg(0);
					file.close();
					return -1;
				}
				continue;
			}
			if (i == 11 || i == 12)
				continue;;
			if (i == 13 && toCompare[i] == '-')
				continue;
			else if(std::isdigit(toCompare[i]))
				continue;
			else if(toCompare[i] == '.')
			{
				dotCount++;
				if(dotCount >= 2){
					std::cerr << "Error! Wrong input file formatting at line ["<< lineCount <<"]" << std::endl;
					file.clear();
					file.seekg(0);
					file.close();
					return -1;
				}
				continue;
			}
			std::cerr << "Wrong input file formatting at line ["<< lineCount <<"]" << std::endl;
			file.clear();
			file.seekg(0);
			file.close();
			return -1;
		}
		toCompare.clear();
	}
	file.clear();
	file.seekg(0);
	file.close();
	toCompare.clear();

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
	std::set<std::string> tempSet;
	lineCount = 0;
	while(getline(file, toCompare))
	{
		char dotCount = 0;
		lineCount++;
		// line 1 
		if (lineCount == 1){
			if (toCompare.compare("date,exchange_rate"))
			{
				std::cerr << "Wrong data.csv formatting at line 1 : "<< toCompare.compare("date,exchange_rate") << std::endl;
				file.clear();
				file.seekg(0);
				file.close();
				return -1;
			}
			continue;
		}
		// set allocation
		std::pair<std::set<std::string>::iterator, bool> setRetValue;
		setRetValue = tempSet.insert(toCompare);
		if (setRetValue.second == false)
		{
			std::cout << "Error! Duplicated line [" << lineCount << "] in CSV file: \"" << toCompare << "\"" << std::endl;
			file.clear();
			file.seekg(0);
			return -1;
		}
		// checks line formatting
		for (size_t i = 0; i < toCompare.length(); i++)
		{	
			if (i == 4 || i == 7){
				if (toCompare[i] != '-'){
					std::cerr << "Wrong data.csv formatting at line [" << lineCount << "], column [" << i << "]: expected '-', found '" << toCompare[i] <<"'" << std::endl;
					file.clear();
					file.seekg(0);
					file.close();
					return -1;
				}
				continue;
			}
			else if(i == 10){
				if (toCompare[i] != ',')
				{
					std::cerr << "Wrong data.csv formatting at line [" << lineCount << "], column [" << i << "]: expected ',', found '" << toCompare[i] <<"'" << std::endl;
					file.clear();
					file.seekg(0);
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
				file.clear();
				file.seekg(0);
				file.close();
				return -1;
			}
		}
		toCompare.clear();
	}
	file.clear();
	file.seekg(0);
	file.close();
	if (file.is_open() == true){
		std::cerr << "Failed closing file at " << __FUNCTION__ <<"():" << __LINE__ << std::endl;
		return -1;
	}
	return 0;
}

int BitcoinExchange::testSet(void){
	std::set<std::string>::iterator it;
	int i = 0;
	for (it = this->_csvData.begin(); it != this->_csvData.end(); it++)
	{
		i++;
		std::cout << "[" << i << "] : [" << *it << "]" << std::endl;
	}
	if (i==0)
		return 1;
	return 0;
}

int BitcoinExchange::testConstructors(void){
	BitcoinExchange defCons;
	assert (defCons.getFileName().compare("") == 0);

	BitcoinExchange argConStr(std::string("test"));
	assert (argConStr.getFileName().compare(std::string("test")) == 0);
	assert (argConStr.getCsvFileName().compare(std::string("data.csv")) == 0);
	
	char cStringFileName[] = "test_c";
	BitcoinExchange argConCStr(cStringFileName);
	assert (argConCStr.getFileName().compare(std::string(cStringFileName)) == 0);
	assert (argConCStr.getCsvFileName().compare(std::string("data.csv")) == 0);

	argConStr = argConCStr;
	assert (argConStr.getFileName().compare(std::string("test_c")) == 0);
	assert (argConStr.getCsvFileName().compare(std::string("data.csv")) == 0);

	return 0;
}

// ----------------------------------------- INTERNAL

int BitcoinExchange::_readTotalCsvLines(void){
	std::fstream file;
	std::string temp;
	file.open(this->_csvFileName.c_str(), std::ios::in);
	if (file.is_open() == false){
		std::cerr << "CSV file can't be opened." << std::endl;
		return -1;
	}
	int lines = 0;
	while (getline(file, temp))
	{
		lines++;
	}
	file.close();
	return (lines);
}

std::set<std::string> BitcoinExchange::_populateCsvData(void){
	std::fstream csv_file;
	std::set<std::string> ret;
	csv_file.open(this->_csvFileName.c_str(), std::ios::in);
	if(csv_file.is_open() == false){
		std::cerr << "CSV file can't be opened." << std::endl;
		return ret;
	}
	std::string temp;
	std::pair<std::set<std::string>::iterator, bool> setRetValue;

	while (getline(csv_file, temp))
	{
		setRetValue = ret.insert(temp);
		if (setRetValue.second == false)
			std::cerr << "WTF just happened?!!? at " << __FUNCTION__ << std::endl;
	}
	if(csv_file.is_open())
		csv_file.close();
	return ret;
}

std::string BitcoinExchange::_readCurrentInputLine(void){
	std::string ret;
	static std::fstream _inputFile;

	if (_inputFile.is_open() == false)
	{
		_inputFile.open(this->_fileName.c_str(), std::fstream::in);
	}
	if (_inputFile.is_open() == false)
	{
		std::cerr << "Input file isn't open at " << __FUNCTION__ << std::endl;
		ret.clear();
		return "ERROR: NOT OPENED!";
	}
	if (getline(_inputFile, ret))
	{
		if (ret.compare("date | value") == 0)
		{
			ret.clear();
			getline(_inputFile, ret);
		}
		if (_inputFile.good())
			return ret;
	}
	if (ret.compare("") == 0)
		return "EOF";
	return ret;

}

// ----------------------------------------- RUN!
// 0123456789
// 2022-01-24
static int compareDate(std::string input, std::string csv){
	u_int16_t inputYear = 0;
	u_int16_t csvYear = 0;
	u_int16_t inputMonth = 0;
	u_int16_t csvMonth = 0;
	u_int16_t inputDay = 0;
	u_int16_t csvDay = 0;

	if(csv.compare("date,exchange_rate") == 0)
		return -1;

	// years
	for (int i = 0; i < 4; i++)
	{
		inputYear *= 10;
		inputYear += input[i] - '0';
		csvYear *= 10;
		csvYear+= csv[i] - '0';
	}
	if (inputYear < csvYear)
		return -1;
	if (inputYear > csvYear)
		return 1;
	// months
	for (int i = 5; i < 7; i++)
	{
		inputMonth *= 10;
		inputMonth += input[i] - '0';
		csvMonth *= 10;
		csvMonth+= csv[i] - '0';
	}
	if (inputYear == csvYear && inputMonth < csvMonth)
		return -1;
	if (inputYear == csvYear && inputMonth > csvMonth)
		return 1;
	// days
	for (int i = 8; i < 10; i++)
	{
		inputDay *= 10;
		inputDay += input[i] - '0';
		csvDay *= 10;
		csvDay+= csv[i] - '0';
	}
	if (inputYear == csvYear && inputMonth == csvMonth && inputDay < csvDay)
		return -1;
	if (inputYear == csvYear && inputMonth == csvMonth && inputDay > csvDay)
		return 1;
		
	return 0;
}

static float getInputValue(std::string inputLine){
	std::string value(inputLine.substr(13, (inputLine.length() - 13)));
	return std::atof(value.c_str());
}

static float getCsvValue(std::string csvLine){
	std::string value(csvLine.substr(11, (csvLine.length() - 11)));
	return std::atof(value.c_str());
}

float multiplyValues(std::string currentInputLine, std::string csvLine){
	return getInputValue(currentInputLine) * getCsvValue(csvLine);
}

bool checkEarleistEntry(std::string input, std::string csvEarliest){
	if (compareDate(input, csvEarliest) == -1)
		return false;
	return true;
}

typedef enum e_InputError
{
	ok = 0,
	badYear = 1,
	badMonth = 2,
	badDay = 3,
	badSize = 4,
	badValueNegative = 5,
	badValueTooLarge = 6,
	badFormatting = 7,
	badNoPreviousCsvEntry = 8
} t_InputError;
// A valid value must be either a float or a positive integer, between 0 and 100
static t_InputError validateInput(std::string input, std::string csvEarliest){
	const std::string stringFormat("0000-00-00 | 1");
	u_int16_t inputYear = 0;
	u_int16_t inputMonth = 0;
	u_int16_t inputDay = 0;

	if (input.compare("EOF") == 0)
		return ok;
	// years
	for (int i = 0; i < 4; i++)
	{
		inputYear *= 10;
		inputYear += input[i] - '0';
	}
	if (input[4] != '-')
		return badYear; 

	// months
	for (int i = 5; i < 7; i++)
	{
		inputMonth *= 10;
		inputMonth += input[i] - '0';
	}
	if (input[7] != '-' || inputMonth > 12)
		return badMonth;

	// days
	for (int i = 8; i < 10; i++)
	{
		inputDay *= 10;
		inputDay += input[i] - '0';
	}
	if (inputDay > 31)
		return badDay;
	if (input.length() < stringFormat.length())
		return badFormatting;
	bool dotFound = false;
	for (std::string::iterator i = input.begin() ; i < input.end(); i++){
		if (!std::isdigit(*i)) 
			if (*i != '-' && *i != ' ' && *i != '.' && *i != '|')
				return badFormatting;
		if (*i == '.')
		{
			if (dotFound)
				return badFormatting;
			if(dotFound == false)
				dotFound = true;
		}
	}
	if (input[13] == '-')
		return badValueNegative;
	std::string value(input.substr(13, (input.length() - 13)));
	float fValue = getInputValue(input);
	if (fValue < 0 || fValue > 1000)
		return badValueTooLarge;
	if (checkEarleistEntry(input, csvEarliest) == false)
		return badNoPreviousCsvEntry;
	return ok;
}

void BitcoinExchange::run(void){
	std::string currentInputLine;
	std::string temp;
	bool found = false;

	std::set<std::string>::iterator it;
	it = this->_csvData.begin();

	while (1) // percorre o input
	{
		currentInputLine = this->_readCurrentInputLine();
		t_InputError rc = validateInput(currentInputLine, *this->_csvData.begin());
		
		if (rc == ok)
			;
		else if (rc == badYear) {
			std::cout << "Input error: badYear => \"" << currentInputLine << "\"" << std::endl;
			continue;
		}
		else if (rc == badMonth){
			std::cout << "Input error: badMonth => \"" << currentInputLine << "\"" << std::endl;
			continue;
		}
		else if (rc == badDay){
			std::cout << "Input error: badDay => \"" << currentInputLine << "\"" << std::endl;
			continue;
		}
		else if (rc == badSize){
			std::cout << "Input error: badSize => \"" << currentInputLine << "\"" << std::endl;
			continue;
		}
		else if (rc == badValueNegative){
			std::cout << "Input error: badValueNegative => \"" << currentInputLine << "\"" << std::endl;
			continue;
		}
		else if (rc == badValueTooLarge){
			std::cout << "Input error: badValueTooLarge => \"" << currentInputLine << "\"" << std::endl;
			continue;
		}
		else if (rc == badFormatting){
			std::cout << "Input error: badFormatting => \"" << currentInputLine << "\"" << std::endl;
			continue;
		}
		else if (rc == badNoPreviousCsvEntry){
			std::cout << "Input error: badNoPreviousCsvEntry => \"" << currentInputLine << "\" earliest entry: \"" << *this->_csvData.begin() << "\"" << std::endl;
			continue; 
		}
		else{
			std::cout << "validate input ret:wtf?!!?" << std::endl;
		}

		if (currentInputLine.compare("EOF") == 0)
			return ;

		found = false;
		for ( it = this->_csvData.begin(); it != this->_csvData.end(); it++) //percorre csv
		{
			if (found == true)
				break;
			if (compareDate(currentInputLine, *it) == 0){
				found = true;
				std::cout << "inputDate = csvDate : [" << currentInputLine << "] : [" << *it << "] => " << multiplyValues(currentInputLine, *it) << std::endl;
			}
			else if (compareDate(currentInputLine, *it) == -1){
				if(it != this->_csvData.begin()){
					found = true;
					it--;
					std::cout << "inputDate > csvDate : [" << currentInputLine << "] : [" << *it << "] => " << multiplyValues(currentInputLine, *it) << std::endl;
					//faz as operacoes especificas com a ultima posicao do iterador
					it++;
				}
			}
			else{
				found = false;
			}
		}
		if (found == false)
		{
			// ugly workaround
			it--;
			it--;
			std::cout << "lastIndex:" << currentInputLine << "] : [" << *it << "]" << std::endl;
			//faz as operacoes especificas com ultimo iterador
		}
	}

}
