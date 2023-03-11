/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:51:23 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 17:26:17 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	SetName(std::string name);

private:
	std::string _name;
};

#endif // ZOMBIE_HPP
