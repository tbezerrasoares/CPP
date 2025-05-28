/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:13:21 by tbezerra          #+#    #+#             */
/*   Updated: 2025/05/28 11:13:55 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int _rawBits;
		static const int _fractionalBits = 8;
	
	public:
	// Forma canônica
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	// Construtores adicionais
	Fixed(const int value);
	Fixed(const float value);

	// Conversões
	float toFloat(void) const;
	int toInt(void) const;

	// Get/Set
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Comparação
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Aritméticos
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Incremento/Decremento
	Fixed& operator++();    // pré-incremento
	Fixed operator++(int);  // pós-incremento
	Fixed& operator--();    // pré-decremento
	Fixed operator--(int);  // pós-decremento

	// Funções min/max
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};
	
// Operador de saída
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
	
#endif