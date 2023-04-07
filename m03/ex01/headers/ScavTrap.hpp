/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:28:30 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 16:16:04 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	//------------ OCF
	ScavTrap(void);									// default constructor
	ScavTrap(ScavTrap const &instance);				// copy constructor
	ScavTrap & operator=(const ScavTrap &instance);	// copy operator constructor
	~ScavTrap(void);								// default destructor
	//------------
	ScavTrap(std::string name);
	void attack(const std::string& target);
	void guardGate(void);
	void toggleGuardGate(void);
	bool isGuardGate(void);
private:
	bool	_isGuardGate;

};
