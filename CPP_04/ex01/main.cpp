/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:42:24 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/08 16:57:09 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const int N = 4;
	Animal* animals[N];

	// Criando metade Dog, metade Cat
	for (int i = 0; i < N; ++i) {
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- Fazendo sons ---" << std::endl;
	for (int i = 0; i < N; ++i) {
	animals[i]->makeSound();
	}

	std::cout << "\n--- Limpando memória ---" << std::endl;
	for (int i = 0; i < N; ++i) {
		delete animals[i];
	}

	std::cout << "\n--- Testando Deep Copy ---" << std::endl;
	Dog basic;
	{
		Dog tmp = basic; // chamada ao copy constructor
	} // tmp destruído aqui

	return 0;
}
