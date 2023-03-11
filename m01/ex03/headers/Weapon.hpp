/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:09:49 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 18:31:45 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon{
public:
	Weapon(void);
	Weapon(std::string type);
	std::string const &getType(void);
	void	setType(std::string type);
	void	attack(void);
private:
	std::string _type;
};

#endif // WEAPON_HPP
