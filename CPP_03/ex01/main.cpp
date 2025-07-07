/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:29:02 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/07 13:32:15 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	std::cout << "=== TESTE 1: Construtor padrão ===" << std::endl;
	ScavTrap defaultBot;
	std::cout << std::endl;

	std::cout << "=== TESTE 2: Construtor com nome ===" << std::endl;
	ScavTrap bot("Serena");
	std::cout << std::endl;

	std::cout << "=== TESTE 3: Testando ataques ===" << std::endl;
	bot.attack("Bandit");
	bot.attack("Enemy Robot");
	bot.attack("Wild Creature");
	std::cout << std::endl;

	std::cout << "=== TESTE 4: Testando dano ===" << std::endl;
	bot.takeDamage(40);
	bot.takeDamage(30);
	std::cout << std::endl;

	std::cout << "=== TESTE 5: Testando reparação ===" << std::endl;
	bot.beRepaired(20);
	bot.beRepaired(15);
	std::cout << std::endl;

	std::cout << "=== TESTE 6: Função especial Guard Gate ===" << std::endl;
	bot.guardGate();
	defaultBot.guardGate();
	std::cout << std::endl;

	std::cout << "=== TESTE 7: Construtor de cópia ===" << std::endl;
	ScavTrap copyBot(bot);
	copyBot.attack("Test Target");
	std::cout << std::endl;

	std::cout << "=== TESTE 8: Operador de atribuição ===" << std::endl;
	ScavTrap assignBot("Original");
	assignBot = bot;
	assignBot.attack("Assigned Target");
	assignBot.guardGate();
	std::cout << std::endl;

	std::cout << "=== TESTE 9: Testando limites de energia ===" << std::endl;
	ScavTrap energyTest("EnergyBot");
	// ScavTrap tem 50 pontos de energia, vamos gastar todos
	for (int i = 0; i < 52; i++) {
		std::cout << "Ataque " << (i + 1) << ": ";
		energyTest.attack("Target");
	}
	std::cout << std::endl;

	std::cout << "=== TESTE 10: Testando HP zero ===" << std::endl;
	ScavTrap hpTest("HPBot");
	hpTest.takeDamage(100); // Reduz HP para 0
	hpTest.attack("Should not work");
	hpTest.beRepaired(10); // Não deve funcionar com HP 0
	std::cout << std::endl;

	std::cout << "=== TESTE 11: Comparação com ClapTrap ===" << std::endl;
	ClapTrap clap("BasicBot");
	ScavTrap scav("SuperBot");
	std::cout << "ClapTrap attack: ";
	clap.attack("Enemy");
	std::cout << "ScavTrap attack: ";
	scav.attack("Enemy");
	std::cout << std::endl;

	std::cout << "=== Destruição dos objetos ===" << std::endl;
	return 0;
}
