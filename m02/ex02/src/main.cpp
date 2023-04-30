/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:37:33 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/30 19:22:10 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstdlib>
#include <ctime>

void	do_subject(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

void do_custom_tests(void)
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( Fixed( -0.35f ) * Fixed( 5 ) );
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c(-0.35f * 5): " << c << "Float equivalent -1.75" << a.toFloat() << std::endl;
	std::cout << "min(a, b): " << Fixed::min( a, b ) << std::endl; // not described in the subject
	std::cout << "b + c: " << b + c << std::endl;
	std::cout << "b - c: " << b - c << std::endl;
	std::cout << "b * c: " << b * c << std::endl;
	std::cout << "b / c: " << b / c << std::endl;

	if (b > c)
		std::cout << "b(" << b << ") is greater than c(" << c << ")" << std::endl;
	else
		std::cout << "b(" << b << ") is NOT greater than c(" << c << ")" << std::endl;

	if (b < c)
		std::cout << "b(" << b << ") is smaller than c(" << c << ")" << std::endl;
	else
		std::cout << "b(" << b << ") is NOT smaller than c(" << c << ")" << std::endl;

	if (b <= c)
		std::cout << "b(" << b << ") is equal or smaller than c(" << c << ")" << std::endl;
	else
		std::cout << "b(" << b << ") is NOT equal or smaller than c(" << c << ")" << std::endl;

	if (b <= b)
		std::cout << "b(" << b << ") is equal or smaller than b(" << b << ")" << std::endl;
	else
		std::cout << "b(" << b << ") is NOT equal or smaller than b(" << b << ")" << std::endl;

	if (b >= c)
		std::cout << "b(" << b << ") is equal or greater than c(" << c << ")" << std::endl;
	else
		std::cout << "b(" << b << ") is NOT equal or greater than c(" << c << ")" << std::endl;

	if (c >= c)
		std::cout << "c(" << c << ") is equal or greater than c(" << c << ")" << std::endl;
	else
		std::cout << "c(" << c << ") is NOT equal or greater than c(" << c << ")" << std::endl;

	if (c == c)
		std::cout << "c(" << c << ") is equal to c(" << c << ")" << std::endl;
	else
		std::cout << "c(" << c << ") is NOT equal to c(" << c << "). Wich is weird." << std::endl;

	if (c == b)
		std::cout << "c(" << c << ") is equal to b(" << b << ")" << std::endl;
	else
		std::cout << "c(" << c << ") is NOT equal to b(" << b << ")" << std::endl;

	if (c != c)
		std::cout << "c(" << c << ") is NOT equal to c(" << c << ")." << std::endl;
	else
		std::cout << "c(" << c << ") is equal to c(" << c << ")" << std::endl;

	if (c != b)
		std::cout << "c(" << c << ") is NOT equal to b(" << b << ")" << std::endl;
	else
		std::cout << "c(" << c << ") is equal to b(" << b << ")" << std::endl;

	return ;
}

Fixed random_fixed(void)
{
	static bool	is_even;
	int			rng;
	int			signal;
	float		a;

	if (is_even)
	{
		rng = std::rand() % 5000;
		is_even = false;
	}
	else
	{
		rng = std::rand() % 10000;
		is_even = true;
	}
	if (std::rand() % 2)
		signal = -1;
	else
		signal = 1;
	a = (static_cast<float>(rng) / 100);
	a *= signal;

	Fixed ret( a );
	return ( ret );
}

void do_random(void)
{
	std::string line;
	Fixed b;
	Fixed c;

	while (std::getline(std::cin, line))
	{
		if (std::cin.eof())
			return ;
		b = random_fixed();
		c = random_fixed();
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
		std::cout << "min(a, b): " << Fixed::min( c, b ) << std::endl; // not described in the subject
		std::cout << "b + c: " << b + c << std::endl;
		std::cout << "b - c: " << b - c << std::endl;
		std::cout << "b * c: " << b * c << std::endl;
		std::cout << "b / c: " << b / c << std::endl;

		if (b > c)
			std::cout << "b(" << b << ") is greater than c(" << c << ")" << std::endl;
		else
			std::cout << "b(" << b << ") is NOT greater than c(" << c << ")" << std::endl;

		if (b < c)
			std::cout << "b(" << b << ") is smaller than c(" << c << ")" << std::endl;
		else
			std::cout << "b(" << b << ") is NOT smaller than c(" << c << ")" << std::endl;

		if (b <= c)
			std::cout << "b(" << b << ") is equal or smaller than c(" << c << ")" << std::endl;
		else
			std::cout << "b(" << b << ") is NOT equal or smaller than c(" << c << ")" << std::endl;

		if (b <= b)
			std::cout << "b(" << b << ") is equal or smaller than b(" << b << ")" << std::endl;
		else
			std::cout << "b(" << b << ") is NOT equal or smaller than b(" << b << ")" << std::endl;

		if (b >= c)
			std::cout << "b(" << b << ") is equal or greater than c(" << c << ")" << std::endl;
		else
			std::cout << "b(" << b << ") is NOT equal or greater than c(" << c << ")" << std::endl;

		if (c >= c)
			std::cout << "c(" << c << ") is equal or greater than c(" << c << ")" << std::endl;
		else
			std::cout << "c(" << c << ") is NOT equal or greater than c(" << c << ")" << std::endl;

		if (c == c)
			std::cout << "c(" << c << ") is equal to c(" << c << ")" << std::endl;
		else
			std::cout << "c(" << c << ") is NOT equal to c(" << c << "). Wich is weird." << std::endl;

		if (c == b)
			std::cout << "c(" << c << ") is equal to b(" << b << ")" << std::endl;
		else
			std::cout << "c(" << c << ") is NOT equal to b(" << b << ")" << std::endl;

		if (c != c)
			std::cout << "c(" << c << ") is NOT equal to c(" << c << ")." << std::endl;
		else
			std::cout << "c(" << c << ") is equal to c(" << c << ")" << std::endl;

		if (c != b)
			std::cout << "c(" << c << ") is NOT equal to b(" << b << ")" << std::endl;
		else
			std::cout << "c(" << c << ") is equal to b(" << b << ")" << std::endl;
	}
	return ;
}

void do_evaluator(void)
{
	// insert whatsoever else you want to test here.
	return ;
}

int	main(int argc, char *argv[])
{
	std::string args;
	if (argc > 2)
	{
		std::cerr << "Unknwon argument;\nUsage: ./fixed <argument>" << std::endl;
		return (1);
	}
	if (argc < 2)
		args = "subject";
	else
		args = argv[1];
	if (!args.compare("subject"))
	{
		do_subject();
		return 0;
	}
	else if (!args.compare("custom"))
	{
		do_custom_tests();
		return 0;
	}
	else if (!args.compare("random"))
	{
		do_random();
		return 0;
	}
	else if (!args.compare("evaluator"))
	{
		do_evaluator();
		return 0;
	}
	std::cerr << "Unknwon argument;\nUsage: ./fixed <argument>" << std::endl;
	return (1);
}
