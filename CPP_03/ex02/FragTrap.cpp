/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:53:42 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/07 13:59:19 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Construtor padrão
FragTrap::FragTrap() : ClapTrap("Frag") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called for " << _name << std::endl;
}

// Construtor com nome
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called for " << _name << std::endl;
}

// Construtor de cópia
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

// Operador de atribuição
FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "FragTrap assignment operator called" << std::endl;
	return *this;
}

// Destrutor
FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << _name << std::endl;
}

// Novo método
void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests high fives! ✋" << std::endl;
}
