/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:12:02 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/04 17:34:07 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Init_list
{
private:
	int		i;
	std::string	str;
	char	a;
	void	*ptr;

public:
	Init_list(int pi, std::string pstr, char pa, void *pptr);
	~Init_list(void);
	void	print_data(void);
};
