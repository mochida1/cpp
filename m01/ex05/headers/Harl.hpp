/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:36:31 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 20:12:02 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	public:
	Harl(void);
	~Harl(void);
	void	complain( std::string level );

	private:
	std::string _debugMessage;
	std::string _infoMessage;
	std::string _warningMessage;
	std::string _errorMessage;
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};

#endif // HARL_HPP
