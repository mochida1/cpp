/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:50:53 by hmochida          #+#    #+#             */
/*   Updated: 2023/07/09 17:00:29 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wathever.hpp"
#include <cassert>
#include "Fixed.hpp"

void test_swap(void)
{
	std::cout << "\n\t### Starting swap() tests\n" << std::endl;


	int a = 1;
	int b = 42;
	assert(a == 1);
	assert(b == 42);
	std::cout << "<< a:[" << a << "] b:[" << b << "]" << std::endl;
	swap(a, b);
	assert(a == 42);
	assert(b == 1);
	std::cout << ">> a:[" << a << "] b:[" << b << "]" << std::endl;

	Fixed fix_a(42.468f);
	Fixed fix_b(3.21f);
	std::cout << "<< fix_a:[" << fix_a << "] fix_b:[" << fix_b << "]" << std::endl;
	swap(fix_a, fix_b);
	std::cout << ">> fix_a:[" << fix_a << "] fix_b:[" << fix_b << "]" << std::endl;

	std::cout << "\n@@@@@@@@@@@@@@@@@@@@@@@\n" << std::endl;
}

void test_min(void)
{
	std::cout << "\n\t### Starting min() tests\n" << std::endl;


	int a = 45;
	int b = 21;
	assert(a == 45);
	assert(b == 21);
	int c = min(a , b);
	assert(c == 21);
	std::cout << "<< a:[" << a << "] b:[" << b << "]" << std::endl;
	std::cout << ">> min (a, b): [" << min(a, b) << "]" << std::endl;
	a = 13;
	b = 9999;
	c = min(a , b);
	assert(c == 13);
	std::cout << "<< a:[" << a << "] b:[" << b << "]" << std::endl;
	std::cout << ">> min (a, b): [" << min(a, b) << "]" << std::endl;

	Fixed fix_a(42.468f);
	Fixed fix_b(3.21f);
	std::cout << "<< fix_a:[" << fix_a << "] fix_b:[" << fix_b << "]" << std::endl;
	Fixed fix_c = min(fix_a, fix_b);
	std::cout << ">> min (fix_a, fix_b): [" << min(fix_a, fix_b) << "]" << std::endl;

	fix_a = -31.656f;
	fix_b = 1.41f;
	std::cout << "<< fix_a:[" << fix_a << "] fix_b:[" << fix_b << "]" << std::endl;
	fix_c = min(fix_a, fix_b);
	std::cout << ">> min (fix_a, fix_b): [" << min(fix_a, fix_b) << "]" << std::endl;

	fix_a = 11.51f;
	fix_b = 11.51f;
	std::cout << "<< fix_a:[" << fix_a << "] fix_b:[" << fix_b << "]" << std::endl;
	std::cout << "<< &fix_a:[" << &fix_a << "] &fix_b:[" << &fix_b << "]" << std::endl;
	std::cout << ">> &min (fix_a, fix_b): [" << &min(fix_a, fix_b) << "]" << std::endl;
	assert (&fix_b == &min(fix_a, fix_b));

	std::cout << "\n@@@@@@@@@@@@@@@@@@@@@@@\n" << std::endl;

}

void test_max(void)
{
	std::cout << "\n\t### Starting max() tests\n" << std::endl;


	int a = 45;
	int b = 21;
	assert(a == 45);
	assert(b == 21);
	int c = max(a , b);
	assert(c == 45);
	std::cout << "<< a:[" << a << "] b:[" << b << "]" << std::endl;
	std::cout << ">> max (a, b): [" << max(a, b) << "]" << std::endl;
	a = 13;
	b = 9999;
	c = max(a , b);
	assert(c == 9999);
	std::cout << "<< a:[" << a << "] b:[" << b << "]" << std::endl;
	std::cout << ">> max (a, b): [" << max(a, b) << "]" << std::endl;

	Fixed fix_a(42.468f);
	Fixed fix_b(3.21f);
	std::cout << "<< fix_a:[" << fix_a << "] fix_b:[" << fix_b << "]" << std::endl;
	Fixed fix_c = max(fix_a, fix_b);
	std::cout << ">> max (fix_a, fix_b): [" << max(fix_a, fix_b) << "]" << std::endl;
	assert (fix_c == fix_a);

	fix_a = -31.656f;
	fix_b = 1.41f;
	std::cout << "<< fix_a:[" << fix_a << "] fix_b:[" << fix_b << "]" << std::endl;
	fix_c = max(fix_a, fix_b);
	std::cout << ">> max (fix_a, fix_b): [" << max(fix_a, fix_b) << "]" << std::endl;
	assert (c == b);

	fix_a = 11.51f;
	fix_b = 11.51f;
	assert (fix_a == fix_b);
	std::cout << "<< fix_a:[" << fix_a << "] fix_b:[" << fix_b << "]" << std::endl;
	std::cout << "<< &fix_a:[" << &fix_a << "] &fix_b:[" << &fix_b << "]" << std::endl;
	std::cout << ">> &max (fix_a, fix_b): [" << &max(fix_a, fix_b) << "]" << std::endl;
	assert (&fix_b == &max(fix_a, fix_b));

	std::cout << "\n@@@@@@@@@@@@@@@@@@@@@@@\n" << std::endl;
}

void test_subject(void)
{
	std::cout << "\n\t### Starting SUBJECT tests\n" << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "\n@@@@@@@@@@@@@@@@@@@@@@@\n" << std::endl;
}

int main (void)
{
	test_swap();
	test_min();
	test_max();
	test_subject();

	return 0;
}
