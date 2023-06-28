/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochida <mochida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:03:16 by mochida           #+#    #+#             */
/*   Updated: 2023/06/27 22:12:08 by mochida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>

//this is a data carrier struct. It only carries some random data.
struct Data {
	Data(void);
	~Data(void);
	Data(const Data &instance);
	Data &operator=(const Data & instance);

	Data(std::string a, std::string b, unsigned int c, char d);

	std::string		aString;
	std::string		anotherString;
	unsigned int	anUnsignedInt;
	char			aSingleChar;
};

#endif //DATA_HPP