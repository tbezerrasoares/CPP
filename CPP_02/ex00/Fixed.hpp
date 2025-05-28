/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:19:04 by tbezerra          #+#    #+#             */
/*   Updated: 2025/05/21 14:02:46 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _rawBits;
	static const int _fractionalBits = 8;

public:
	Fixed();								// Construtor padrão
	Fixed(const Fixed& other);				// Construtor de cópia
	Fixed& operator=(const Fixed& other);	// Operador de atribuição
	~Fixed();								// Destrutor

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
