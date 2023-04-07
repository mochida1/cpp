/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:51:07 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 17:43:41 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	//------------ OCF
	FragTrap(void);									// default constructor
	FragTrap(FragTrap const &instance);				// copy constructor
	FragTrap & operator=(const FragTrap &instance);	// copy operator constructor
	~FragTrap(void);								// default destructor
	//------------
	FragTrap(std::string name);
	void attack(const std::string& target);
	void highFiveGuys(void);
private:

};

#endif // FRAGTRAP_HPP
