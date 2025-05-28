/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:53:21 by tbezerra          #+#    #+#             */
/*   Updated: 2025/05/28 16:25:27 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Construtor padrão
ScavTrap::ScavTrap() : ClapTrap("Scav") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called for " << _name << std::endl;
}

// Construtor com nome
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << _name << std::endl;
}

// Construtor de cópia
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

// Operador de atribuição
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment operator called" << std::endl;
	return *this;
}

// Destrutor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << _name << std::endl;
}

// Método sobrescrito
void ScavTrap::attack(const std::string& target) {
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target
				<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << " can't attack due to low energy or HP." << std::endl;
	}
}

// Novo método exclusivo
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}