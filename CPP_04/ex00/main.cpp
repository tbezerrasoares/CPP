/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:21:22 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/08 15:02:38 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// Função para testar polimorfismo correto com Animal
void testPolymorphism() {
	std::cout << "=== Teste de Polimorfismo Correto ===" << std::endl;

	Animal* animals[3];
	animals[0] = new Animal();
	animals[1] = new Dog();
	animals[2] = new Cat();

	for (int i = 0; i < 3; i++) {
		std::cout << "Animal " << i << " - Tipo: " << animals[i]->getType() << std::endl;
		std::cout << "Som: ";
		animals[i]->makeSound();
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++) {
		delete animals[i];
	}
}

// Função para testar problema sem virtual
void testWrongPolymorphism() {
	std::cout << "=== Teste de Polimorfismo Incorreto ===" << std::endl;

	WrongAnimal* wrongAnimals[2];
	wrongAnimals[0] = new WrongAnimal();
	wrongAnimals[1] = new WrongCat();

	for (int i = 0; i < 2; i++) {
		std::cout << "WrongAnimal " << i << " - Tipo: " << wrongAnimals[i]->getType() << std::endl;
		std::cout << "Som: ";
		wrongAnimals[i]->makeSound(); // Sempre chama WrongAnimal::makeSound()
		std::cout << std::endl;
	}

	for (int i = 0; i < 2; i++) {
		delete wrongAnimals[i];
}
}

// Função para testar construtores e destrutores
void testConstructorsDestructors() {
	std::cout << "=== Teste de Construtores/Destrutores ===" << std::endl;

	std::cout << "Criando Dog..." << std::endl;
	Animal* dog = new Dog();
	std::cout << "Deletando Dog..." << std::endl;
	delete dog;

	std::cout << "\nCriando Cat..." << std::endl;
	Animal* cat = new Cat();
	std::cout << "Deletando Cat..." << std::endl;
	delete cat;
}

// Função para testar cópia e atribuição
void testCopyAndAssignment() {
	std::cout << "=== Teste de Cópia e Atribuição ===" << std::endl;

	Dog original;
	std::cout << "Dog original - Tipo: " << original.getType() << std::endl;

	Dog copy(original);
	std::cout << "Dog copiado - Tipo: " << copy.getType() << std::endl;

	Cat cat;
	Cat assignedCat;
	assignedCat = cat;
	std::cout << "Cat atribuído - Tipo: " << assignedCat.getType() << std::endl;
}

int main() {
	testPolymorphism();
	std::cout << std::endl;

	testWrongPolymorphism();
	std::cout << std::endl;

	testConstructorsDestructors();
	std::cout << std::endl;

	testCopyAndAssignment();

	return 0;
}
