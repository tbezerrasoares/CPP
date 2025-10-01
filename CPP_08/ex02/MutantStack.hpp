/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by tbezerra          #+#    #+#             */
/*   Updated: 2025/10/01 11:39:55 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <iterator>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	// Definição de tipos de iteradores baseados no container subjacente
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	// Orthodox Canonical Form
	MutantStack() : std::stack<T, Container>() {}
	
	MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
	
	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other)
			std::stack<T, Container>::operator=(other);
		return *this;
	}
	
	~MutantStack() {}

	// Métodos de iteração forward
	iterator begin()
	{
		return this->c.begin();
	}
	
	iterator end()
	{
		return this->c.end();
	}
	
	const_iterator begin() const
	{
		return this->c.begin();
	}
	
	const_iterator end() const
	{
		return this->c.end();
	}

	// Métodos de iteração reversa (opcional mas útil)
	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}
	
	reverse_iterator rend()
	{
		return this->c.rend();
	}
	
	const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	}
	
	const_reverse_iterator rend() const
	{
		return this->c.rend();
	}

	// Métodos auxiliares para debugging/testing
	size_t size() const
	{
		return std::stack<T, Container>::size();
	}
	
	bool empty() const
	{
		return std::stack<T, Container>::empty();
	}
};

#endif