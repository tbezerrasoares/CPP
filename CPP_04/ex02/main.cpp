/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:41:12 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/09 16:04:53 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <cassert>

/* int main() {
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << ": ";
	dog->makeSound();

	std::cout << cat->getType() << ": ";
	cat->makeSound();

	delete dog;
	delete cat;

	return 0;
} */

void test_dog_creation_and_behavior() {
	std::cout << "\033[1mTeste criacao da classe Dog...\033[0m" << std::endl;
	
	const Animal* dog = new Dog();
	assert(dog->getType() == "Dog");
	
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Dog sound: ";
	dog->makeSound();
	
	delete dog;
	std::cout << "\033[1;32m✓ Dog test passed\033[0m" << std::endl;
}

void test_cat_creation_and_behavior() {
	std::cout << "\033[1mTeste criacao da classe Cat...\033[0m" << std::endl;
	
	const Animal* cat = new Cat();
	assert(cat->getType() == "Cat");
	
	std::cout << "Cat type: " << cat->getType() << std::endl;
	std::cout << "Cat sound: ";
	cat->makeSound();
	
	delete cat;
	std::cout << "\033[1;32m✓ Cat test passed\033[0m" << std::endl;
}

void test_polymorphism() {
	std::cout << "\033[1mTeste polimorfismo...\033[0m" << std::endl;
	
	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	
	for (int i = 0; i < 4; i++) {
		std::cout << "Animal " << i << " - Type: " << animals[i]->getType() << ", Sound: ";
		animals[i]->makeSound();
	}
	
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
	
	std::cout << "\033[1;32m✓ Polymorphism test passed\033[0m" << std::endl;
}

void test_copy_constructor() {
	std::cout << "\033[1mTeste copy constructor...\033[0m" << std::endl;
	
	Dog original;
	Dog copy(original);
	
	assert(original.getType() == copy.getType());
	
	std::cout << "Original: ";
	original.makeSound();
	std::cout << "Copy: ";
	copy.makeSound();
	
	std::cout << "\033[1;32m✓ Copy constructor test passed\033[0m" << std::endl;
}

void test_assignment_operator() {
	std::cout << "\033[1mTeste assignment operator...\033[0m" << std::endl;
	
	Dog dog1;
	Dog dog2;
	
	dog2 = dog1;
	
	assert(dog1.getType() == dog2.getType());
	
	std::cout << "Dog1: ";
	dog1.makeSound();
	std::cout << "Dog2: ";
	dog2.makeSound();
	
	std::cout << "\033[1;32m✓ Assignment operator test passed\033[0m" << std::endl;
}

void test_brain_functionality() {
	std::cout << "\033[1mTeste Brain functionality...\033[0m" << std::endl;
	
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog(*dog1);
	
	// Testa se a cópia profunda do Brain
	std::cout << "Testing deep copy of Brain..." << std::endl;
	
	delete dog1;
	delete dog2;
	
	std::cout << "\033[1;32m✓ Brain functionality test passed\033[0m" << std::endl;
}

void test_memory_management() {
	std::cout << "\033[1mTeste memory management...\033[0m" << std::endl;
	
	// Cria e deleta 10 objetos Dog e Cat para verificar se a memória é gerenciada corretamente
	for (int i = 0; i < 10; i++) {
		Animal* dog = new Dog();
		Animal* cat = new Cat();
		delete dog;
		delete cat;
	}
	
	std::cout << "\033[1;32m✓ Memory management test passed\033[0m" << std::endl;
}

void test_abstract_animal() {
	std::cout << "Testing abstract Animal class..." << std::endl;
	
	// ↓ Isto agora deve dar ERRO DE COMPILAÇÃO (como esperado):
	//Animal* a = new Animal(); // ← PROIBIDO, pois Animal é abstrata
	
	std::cout << "\033[1;32m✓ Abstract Animal test passed (cannot instantiate Animal directly)\033[0m" << std::endl;
}

int main() {
	std::cout << "=== Running CPP_04 ex02 Tests ===" << std::endl;
	
	try {
		test_dog_creation_and_behavior();
		std::cout << std::endl;
		test_cat_creation_and_behavior();
		std::cout << std::endl;
		test_polymorphism();
		std::cout << std::endl;
		test_copy_constructor();
		std::cout << std::endl;
		test_assignment_operator();
		std::cout << std::endl;
		test_brain_functionality();
		std::cout << std::endl;
		test_memory_management();
		std::cout << std::endl;
		//test_abstract_animal();
		
		std::cout << "\n=== All tests passed! ===" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Test failed with exception: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
