/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unsed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:10:26 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 16:59:06 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Unsed.class.hpp"

Unsed::Unsed(std::string file, std::string s1, std::string s2) : _outFileName(file + ".replace"), _inFileName(file), _s1(s1), _s2(s2) {
	return ;
}

Unsed::Unsed(void) {
	return ;
}

Unsed::~Unsed(void) {
	return ;
}

bool	Unsed::setOutFileName(std::string str) {
	this->_outFileName = str;
	if (this->_outFileName == str)
		return (true);
	return (false);
}

bool	Unsed::setInFileName(std::string filename) {
	this->_inFileName = filename;
	if (this->_inFileName == filename)
		return (true);
	return (false);
}

bool	Unsed::setS1(std::string str) {
	this->_s1 = str;
	if (this->_s1 == str)
		return (true);
	return (false);
}

bool	Unsed::setS2(std::string str) {
	this->_s2 = str;
	if (this->_s2 == str)
		return (true);
	return (false);
}

std::string const &Unsed::getOutFileName(void) {
	return (this->_outFileName);
}

std::string const &Unsed::getInFileName(void) {
	return (this->_inFileName);
}

bool	Unsed::openInFile(void) {
	std::string line;
	std::stringstream stream;

	std::cout << "opening file [" << this->_inFileName << "]" << std::endl;
	this->_inFile.open(this->_inFileName.c_str(), std::fstream::in );
	if (this->_inFile.is_open() == false)
		return (false);
	this->_inFileIsOpen = true;
	while (std::getline(this->_inFile, line))
	{
		stream << line << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
	this->_fileContent = stream.str();
	if (!this->_inFile.eof())
		return (false);
	this->_inFile.clear();
	return (true);
}

bool	Unsed::isInFileOpen(void) {
	if (this->_inFileIsOpen == true)
		return (true);
	return (false);
}

bool	Unsed::closeInFile(void) {

	this->_inFile.close();
	if (this->_inFile.fail())
	{
		std::cerr << "Couldn't close file [" << this->_inFileName << "]" << std::endl;
		return (false);
	}
	this->_inFileIsOpen = false;
	return (true);
}

void	Unsed::printFileContent(void) {
	std::cout << this->_fileContent << std::endl;
	return ;
}

bool	Unsed::doTrFileContent(void) {
	int idx;

	idx = this->_fileContent.find(this->_s1);
	if (idx == -1)
		return (false);
	while (idx != -1)
	{
		std::cout << "string found: " << idx << std::endl;
		this->_fileContent.erase(idx, this->_s1.size());
		this->_fileContent.insert(idx, this->_s2);
		idx = this->_fileContent.find(this->_s1);
	}
	return (true);
}

bool	Unsed::writeToOutFile(void) {
	std::fstream out_file;

	this->_outFile.open(this->_outFileName.c_str(), std::fstream::out | std::fstream::trunc);
	if (this->_outFile.fail())
	{
		std::cerr << "Failed to create new file" << std::endl;
		return (false);
	}
	this->_outFile << this->_fileContent;
	if (this->_outFile.fail())
	{
		std::cerr << "Couldn't complete write operation to output file" << std::endl;
		return (false);
	}
	this->_outFile.close();
		if (this->_outFile.fail())
	{
		std::cerr << "Failed to close output file" << std::endl;
		return (false);
	}
	return (true);
}
