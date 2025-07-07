/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:14:37 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/04 16:14:50 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {}

Cat& Cat::operator=(const Cat& other) {
	Animal::operator=(other);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
