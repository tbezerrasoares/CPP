/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:13:15 by tbezerra          #+#    #+#             */
/*   Updated: 2025/05/28 11:13:47 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Forma canônica
Fixed::Fixed() : _rawBits(0)
{ 
	//std::cout << "Default constructor called\n"; 
}
Fixed::Fixed(const Fixed &other)
{
	_rawBits = other.getRawBits();
}
Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called\n";
	if (this != &other) this->_rawBits = other.getRawBits();
	return *this;
}
Fixed::~Fixed() 
{ 
	//std::cout << "Destructor called\n"; 
}

// Construtores adicionais
Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called\n";
	_rawBits = value << (1 *_fractionalBits);
}

Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called\n";
	_rawBits = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

// Conversão
float Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

// Get/Set
int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

// Operador <<
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

// Comparações
bool Fixed::operator>(const Fixed& other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed& other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed& other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return _rawBits != other._rawBits; }

// Aritméticos
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_rawBits + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_rawBits - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	int64_t tmp = static_cast<int64_t>(_rawBits) * other.getRawBits();
	result.setRawBits(tmp >> _fractionalBits);
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((_rawBits << _fractionalBits) / other.getRawBits());
	return (result);
}

// Incremento/Decremento
Fixed &Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

// Min/Max
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}
