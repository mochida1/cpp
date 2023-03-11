/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:36:40 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 19:51:29 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon &anyWeapon);
		~HumanA(void);
		void	attack(void);
		std::string const getName(void);

	private:
		std::string	_name;
		Weapon		*_weapon;
};
