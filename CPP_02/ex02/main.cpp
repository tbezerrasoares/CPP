/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:12:56 by tbezerra          #+#    #+#             */
/*   Updated: 2025/05/26 16:51:00 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
	return 0;
}