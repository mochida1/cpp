/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:12:07 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/04 17:34:06 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_list.class.hpp"

Init_list::Init_list(int pi, std::string pstr, char pa, void *pptr) : i(pi), str(pstr), a(pa), ptr(pptr) {
	std::cout << "Constructing..." << std::endl;
}

Init_list::~Init_list(void) {
	std::cout << "Destroying..." << std::endl;
}

void	Init_list::print_data(void) {
	std::cout << "[i]: " << this->i << std::endl;
	std::cout << "[str]: " << this->str << std::endl;
	std::cout << "[a]: " << this->a << std::endl;
	std::cout << "[ptr]: " << this->ptr << std::endl;
}

int	main(void) {
	int ppp;
	char *charp = (char *) ("me be charptr");
	void *pp;
	pp = &ppp;
	Init_list teste(51, "I AM STRING", 'c', pp);
	Init_list teste2(42, "i am string", 'x', charp);
	teste.print_data();
	teste2.print_data();
}
