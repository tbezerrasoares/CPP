/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:42:30 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 16:42:42 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T const & min(T const & a, T const & b) {
	return (a < b ? a : b);
}

template<typename T>
T const & max(T const & a, T const & b) {
	return (a > b ? a : b);
}

#endif
