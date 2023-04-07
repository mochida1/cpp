/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:33:46 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/07 13:38:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>

class ClapTrap {
public:
	//------------ OCF
	ClapTrap(void);									// default constructor
	ClapTrap(ClapTrap const &instance);				// copy constructor
	ClapTrap & operator=(const ClapTrap &instance);	// copy operator constructor
	~ClapTrap(void);								// default destructor
	//------------
	ClapTrap(std::string name);

	//------------ Getters
	std::string	getName(void) const;
	int			getHitPoints(void) const;
	int			getEnergyPoints(void) const;
	int			getAttackDamage(void) const;
	//------------

	//------------ Setters
	//------------
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	bool isDead(void);

private:
	std::string _name;
	int	_hitPoints;
	int _energyPoints;
	int _attackDamage;

};

bool explode(ClapTrap &instance);
