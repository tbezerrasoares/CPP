/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:44:02 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/03 18:02:50 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void testClapTrapMethods()
{
	std::cout << "\n=== Testing ClapTrap Methods ===" << std::endl;

	// Criando um objeto ClapTrap
	ClapTrap robot("TestBot");

	// Testando o método attack
	std::cout << "\nTesting attack:" << std::endl;
	robot.attack("Enemy1");
	robot.attack("Enemy2");

	// Testando o método takeDamage
	std::cout << "\nTesting takeDamage:" << std::endl;
	robot.takeDamage(5);
	robot.takeDamage(10);

	// Testando o método beRepaired
	std::cout << "\nTesting beRepaired:" << std::endl;
	robot.beRepaired(3);
	robot.beRepaired(7);

	// Testando interações combinadas
	std::cout << "\nTesting combined interactions:" << std::endl;
	robot.takeDamage(15);
	robot.beRepaired(10);
	robot.attack("Enemy3");

	std::cout << "=== End of Tests ===" << std::endl;
}

int main() 
{
	ClapTrap robot("Clappy");

	robot.attack("target1");
	robot.takeDamage(4);
	robot.beRepaired(3);
	robot.takeDamage(10);
	robot.attack("target2");
	robot.beRepaired(5);

	testClapTrapMethods();
	return 0;
}
