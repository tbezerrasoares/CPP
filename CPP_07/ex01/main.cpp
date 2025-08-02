/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:26:12 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 18:27:27 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Função que apenas imprime
template<typename T>
void printElement(T const & x) {
	std::cout << x << " ";
}

// Função que modifica (aumenta int por 1)
void increment(int & x) {
	x += 1;
}

int main() {
	std::cout << "=== Teste com int ===" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	::iter(arr, 5, printElement);
	std::cout << std::endl;

	::iter(arr, 5, increment);
	::iter(arr, 5, printElement);
	std::cout << std::endl;

	std::cout << "=== Teste com string ===" << std::endl;
	std::string strs[] = {"hello", "world", "!"};
	::iter(strs, 3, printElement);
	std::cout << std::endl;

	return 0;
}
