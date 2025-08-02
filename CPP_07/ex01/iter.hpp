/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:25:09 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 18:27:54 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // std::size_t

// Versão para funções que recebem const referência
template<typename T>
void iter(T* array, std::size_t length, void (*func)(T const &)) {
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

// Versão para funções que recebem referência modificável
template<typename T>
void iter(T* array, std::size_t length, void (*func)(T &)) {
	for (std::size_t i = 0; i < length; ++i)
		func(array[i]);
}

#endif

