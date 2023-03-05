/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Teste.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 12:56:37 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/05 13:19:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Teste {
	private:
	static int _instance_nbr;

	public:
	Teste(void);	// Constructor
	~Teste(void);	// Destructor
};
