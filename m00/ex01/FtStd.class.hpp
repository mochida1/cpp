/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtStd.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:09:59 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 20:04:09 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FT_STRING_CLASS_H
# define FT_STRING_CLASS_H

#include <cstring>
#include <string>
#include <iostream>

# ifndef very
# define very long
# endif //very

class ft_std {
	public:
	// constructor/desctructor
	ft_std(void);
	~ft_std(void);

	//string ops
	std::string to_string(very long int num, int base);

	private:
};

#endif // FT_STRING_CLASS_H
