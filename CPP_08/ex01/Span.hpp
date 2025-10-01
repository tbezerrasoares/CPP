/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by tbezerra          #+#    #+#             */
/*   Updated: 2025/10/01 11:17:00 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	// Orthodox Canonical Form
	Span();									// Construtor padrão
	Span(unsigned int N);					// Construtor parametrizado
	Span(const Span &other);				// Construtor de cópia
	Span &operator=(const Span &other);		// Operador de atribuição
	~Span();								// Destrutor

	// Métodos principais
	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	// Método para adicionar range de números usando iteradores
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);

	// Métodos auxiliares
	unsigned int size() const;
	unsigned int maxSize() const;
	bool isFull() const;
	bool isEmpty() const;

	// Classes de exceção
	class SpanFullException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Span is full - cannot add more numbers";
		}
	};

	class NotEnoughElementsException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Not enough elements to calculate span (need at least 2)";
		}
	};

	class RangeTooBigException : public std::exception
	{
	public:
		virtual const char *what() const throw()
		{
			return "Range is too big for the remaining capacity";
		}
	};
};

// Implementação do template method (deve estar no header)
template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	// Calcula a distância do range
	size_t distance = std::distance(begin, end);
	
	// Verifica se há espaço suficiente
	if (_numbers.size() + distance > _maxSize)
		throw RangeTooBigException();
	
	// Adiciona todos os elementos do range
	_numbers.insert(_numbers.end(), begin, end);
}

#endif