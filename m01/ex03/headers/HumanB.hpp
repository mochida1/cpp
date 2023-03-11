/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:13:46 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 19:51:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name, Weapon &anyWeapon);
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &anyWeapon);
		void	attack(void);
		std::string const getName(void);

	private:
		std::string	_name;
		Weapon		*_weapon;
};
