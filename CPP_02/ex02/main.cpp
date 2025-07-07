/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:12:56 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/03 17:25:41 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void testComparisonOperators()
{
	Fixed a(10.5f);
	Fixed b(20.5f);

	std::cout << "\nTesting comparison operators:" << std::endl;

	std::cout << "a: " << a << ", b: " << b << std::endl;

	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	Fixed c(10.5f);

	std::cout << "\nTesting equality with c:" << std::endl;
	std::cout << "a: " << a << ", c: " << c << std::endl;
	std::cout << "a == c: " << (a == c) << std::endl;
	std::cout << "a != c: " << (a != c) << std::endl;
}

int main( void )
{
	/* Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ); */

	Fixed a(14.2f);
	Fixed b(14.2f);

	std::cout << "this a:" << a << std::endl;
	std::cout << "this ++a:" << ++a << std::endl;
	std::cout << "this a:" << a << std::endl;
	std::cout << "this a++:"<< a++ << std::endl;
	std::cout << "this a:" << a << std::endl;
	std::cout << "this a--:"<< a-- << std::endl;
	std::cout << "this a:" << a << std::endl;
	
	std::cout << "this b:" << b << std::endl;

	std::cout << "this max:" << Fixed::max( a, b ) << std::endl;
	
	testComparisonOperators();
	return 0;
}