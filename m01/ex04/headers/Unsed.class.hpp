/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unsed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:51:42 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 21:19:36 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

class Unsed {
	public:
		Unsed(std::string file, std::string s1, std::string s2)
		~Unsed(void);
	private:
		std::string		_outFileName;
		std::string		_inFileName;
		std::string		_s1;
		std::string		_s2;
		std::fstream	_inFile;
		std::fstream	_ouFile;
};
