/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:01:38 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/04 14:07:35 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h> // para uintptr_t

class Serializer {
private:
	Serializer();									// Construtor privado
	Serializer(const Serializer&);					// Construtor de cópia
	Serializer& operator=(const Serializer&);		// Operador de atribuição
	~Serializer();									// Destrutor

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
