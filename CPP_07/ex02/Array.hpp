/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:42:58 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 18:50:10 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstddef>

template<typename T>
class Array {
private:
	T* _data;
	std::size_t _size;

public:
	// Construtor padrão
	Array() : _data(NULL), _size(0) {}

	// Construtor com tamanho
	Array(unsigned int n) : _data(new T[n]()), _size(n) {}

	// Construtor de cópia
	Array(const Array& other) : _data(NULL), _size(0) {
		*this = other;
	}

	// Operador de atribuição
	Array& operator=(const Array& other) {
		if (this != &other) {
			// Libera memória atual
			delete[] _data;

			_size = other._size;
			_data = new T[_size];
			for (std::size_t i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
		return *this;
	}

	// Destrutor
	~Array() {
		delete[] _data;
	}

	// Operador de acesso por índice
	T& operator[](std::size_t index) {
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _data[index];
	}

	// Operador de acesso const
	const T& operator[](std::size_t index) const {
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _data[index];
	}

	// Retorna o tamanho do array
	std::size_t size() const {
		return _size;
	}
};

#endif
