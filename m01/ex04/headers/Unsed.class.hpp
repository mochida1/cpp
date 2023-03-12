/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unsed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:51:42 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 19:37:21 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef UNSED_CLASS_HPP
# define UNSED_CLASS_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Unsed {
	public:
		Unsed(std::string file, std::string s1, std::string s2);
		Unsed(void);
		~Unsed(void);
		bool	setOutFileName(std::string str);
		bool	setInFileName(std::string filename);
		bool	setS1(std::string str);
		bool	setS2(std::string str);
		std::string const &getOutFileName(void);
		std::string const &getInFileName(void);
		bool	openInFile(void);
		bool	isInFileOpen(void);
		bool	closeInFile(void);
		void	printFileContent(void);
		bool	doTrFileContent(void);
		bool	writeToOutFile(void);

	private:
		std::string		_outFileName;
		std::string		_inFileName;
		std::string		_s1;
		std::string		_s2;
		std::fstream	_inFile;
		std::fstream	_outFile;
		bool			_inFileIsOpen;
		std::string		_fileContent;
};

#endif // UNSED_CLASS_HPP
