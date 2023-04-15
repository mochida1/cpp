/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtStd.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:09:59 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/15 16:55:22 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_STRING_H
# define FT_STRING_H

#include <cstring>
#include <string>
#include <iostream>
#include <cctype>

# ifndef very
# define very long
# endif //very

class ft_std {
	public:
	// constructor/desctructor
	ft_std(void);
	~ft_std(void);

	//string ops
	static std::string to_string(very long int num, int base);
	static bool		isOnlySpace(std::string &str);

	private:
};

#endif // FT_STRING_H
