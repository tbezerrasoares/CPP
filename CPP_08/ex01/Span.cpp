/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by tbezerra          #+#    #+#             */
/*   Updated: 2025/10/01 11:17:01 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// ============================================================================
// Orthodox Canonical Form
// ============================================================================

// Construtor padrão
Span::Span() : _maxSize(0)
{
}

// Construtor parametrizado
Span::Span(unsigned int N) : _maxSize(N)
{
	_numbers.reserve(N); // Otimização: reserva espaço na memória
}

// Construtor de cópia
Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

// Operador de atribuição
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

// Destrutor
Span::~Span()
{
}

// ============================================================================
// Métodos principais
// ============================================================================

// Adiciona um número ao span
void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	
	_numbers.push_back(number);
}

// Calcula o menor span (diferença) entre dois números
unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();

	// Cria uma cópia ordenada para facilitar o cálculo
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = UINT_MAX;
	
	// Percorre elementos adjacentes na lista ordenada
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int currentSpan = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (currentSpan < minSpan)
			minSpan = currentSpan;
	}
	
	return minSpan;
}

// Calcula o maior span (diferença) entre dois números
unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();

	// Encontra o menor e maior elemento
	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
	
	return static_cast<unsigned int>(*maxIt - *minIt);
}

// ============================================================================
// Métodos auxiliares
// ============================================================================

unsigned int Span::size() const
{
	return _numbers.size();
}

unsigned int Span::maxSize() const
{
	return _maxSize;
}

bool Span::isFull() const
{
	return _numbers.size() >= _maxSize;
}

bool Span::isEmpty() const
{
	return _numbers.empty();
}