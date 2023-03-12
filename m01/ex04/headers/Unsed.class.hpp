/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unsed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:51:42 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 13:27:30 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

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

	private:
		std::string		_outFileName;
		std::string		_inFileName;
		std::string		_s1;
		std::string		_s2;
		std::fstream	_inFile;
		std::fstream	_outFile;
};
