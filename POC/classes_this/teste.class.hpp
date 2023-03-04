/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:12:27 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/04 16:46:39 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Teste {
private:
	int			number;
	char		*charptr;
	std::string	str;
public:
	Teste(void);
	~Teste(void);
	void	print_number(void);
	void	set_number(int number);

	void	print_charptr(void);
	void	set_charptr(char *ptr);

	void	set_string(std::string str);
	void	print_string(void);
};

