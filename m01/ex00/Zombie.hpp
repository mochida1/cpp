/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:23 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 14:00:23 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);

private:
	std::string _name;
};

#endif // ZOMBIE_H
