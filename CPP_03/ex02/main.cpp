/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:57:26 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/07 14:07:42 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "=== TESTE 1: Construtor padrão FragTrap ===" << std::endl;
	FragTrap defaultFrag;
	std::cout << std::endl;

	std::cout << "=== TESTE 2: Construtor com nome FragTrap ===" << std::endl;
	FragTrap frag("Fraggie");
	std::cout << std::endl;

	std::cout << "=== TESTE 3: Construtor padrão ScavTrap ===" << std::endl;
	ScavTrap defaultScav;
	std::cout << std::endl;

	std::cout << "=== TESTE 4: Construtor com nome ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");
	std::cout << std::endl;

	std::cout << "=== TESTE 5: Testando ataques FragTrap ===" << std::endl;
	frag.attack("Bandit");
	frag.attack("Enemy Robot");
	frag.attack("Wild Creature");
	std::cout << std::endl;

	std::cout << "=== TESTE 6: Testando ataques ScavTrap ===" << std::endl;
	scav.attack("Raider");
	scav.attack("Mutant");
	scav.attack("Hostile Bot");
	std::cout << std::endl;

	std::cout << "=== TESTE 7: Testando dano FragTrap ===" << std::endl;
	frag.takeDamage(40);
	frag.takeDamage(30);
	std::cout << std::endl;

	std::cout << "=== TESTE 8: Testando dano ScavTrap ===" << std::endl;
	scav.takeDamage(25);
	scav.takeDamage(35);
	std::cout << std::endl;

	std::cout << "=== TESTE 9: Testando reparação FragTrap ===" << std::endl;
	frag.beRepaired(20);
	frag.beRepaired(15);
	std::cout << std::endl;

	std::cout << "=== TESTE 10: Testando reparação ScavTrap ===" << std::endl;
	scav.beRepaired(25);
	scav.beRepaired(10);
	std::cout << std::endl;

	std::cout << "=== TESTE 11: Função especial highFivesGuys ===" << std::endl;
	frag.highFivesGuys();
	defaultFrag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== TESTE 12: Função especial guardGate ===" << std::endl;
	scav.guardGate();
	defaultScav.guardGate();
	std::cout << std::endl;

	std::cout << "=== TESTE 13: Construtor de cópia FragTrap ===" << std::endl;
	FragTrap copyFrag(frag);
	copyFrag.attack("Copy Target");
	copyFrag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== TESTE 14: Construtor de cópia ScavTrap ===" << std::endl;
	ScavTrap copyScav(scav);
	copyScav.attack("Copy Target");
	copyScav.guardGate();
	std::cout << std::endl;

	std::cout << "=== TESTE 15: Operador de atribuição FragTrap ===" << std::endl;
	FragTrap assignFrag("Original");
	assignFrag = frag;
	assignFrag.attack("Assigned Target");
	assignFrag.highFivesGuys();
	std::cout << std::endl;

	std::cout << "=== TESTE 16: Operador de atribuição ScavTrap ===" << std::endl;
	ScavTrap assignScav("Original");
	assignScav = scav;
	assignScav.attack("Assigned Target");
	assignScav.guardGate();
	std::cout << std::endl;

	std::cout << "=== TESTE 17: Testando limites de energia FragTrap ===" << std::endl;
	FragTrap energyTest("EnergyFrag");
	// FragTrap tem 100 pontos de energia, vamos testar alguns ataques
	for (int i = 0; i < 5; i++) {
		std::cout << "Ataque " << (i + 1) << ": ";
		energyTest.attack("Target");
	}
	std::cout << std::endl;

	std::cout << "=== TESTE 18: Testando limites de energia ScavTrap ===" << std::endl;
	ScavTrap energyScav("EnergyScav");
	// ScavTrap tem 50 pontos de energia, vamos testar alguns ataques
	for (int i = 0; i < 5; i++) {
		std::cout << "Ataque " << (i + 1) << ": ";
		energyScav.attack("Target");
	}
	std::cout << std::endl;

	std::cout << "=== TESTE 19: Testando HP zero FragTrap ===" << std::endl;
	FragTrap hpTest("HPFrag");
	hpTest.takeDamage(100); // Reduz HP para 0
	hpTest.attack("Should not work");
	hpTest.beRepaired(10); // Não deve funcionar com HP 0
	hpTest.highFivesGuys(); // Deve funcionar mesmo com HP 0
	std::cout << std::endl;

	std::cout << "=== TESTE 20: Testando HP zero ScavTrap ===" << std::endl;
	ScavTrap hpScav("HPScav");
	hpScav.takeDamage(100); // Reduz HP para 0
	hpScav.attack("Should not work");
	hpScav.beRepaired(10); // Não deve funcionar com HP 0
	hpScav.guardGate(); // Deve funcionar mesmo com HP 0
	std::cout << std::endl;

	std::cout << "=== TESTE 21: Comparação de stats entre classes ===" << std::endl;
	ClapTrap clap("BasicBot");
	ScavTrap scavComp("SuperBot");
	FragTrap fragComp("DestroyerBot");
	
	std::cout << "ClapTrap attack (0 damage): ";
	clap.attack("Enemy");
	std::cout << "ScavTrap attack (20 damage): ";
	scavComp.attack("Enemy");
	std::cout << "FragTrap attack (30 damage): ";
	fragComp.attack("Enemy");
	std::cout << std::endl;

	std::cout << "=== TESTE 22: Testando dano extremo ===" << std::endl;
	FragTrap damageTest("DamageFrag");
	damageTest.takeDamage(150); // Mais dano que HP total
	std::cout << std::endl;

	std::cout << "=== TESTE 23: Testando reparação com energia zero ===" << std::endl;
	FragTrap repairTest("RepairFrag");
	// Gastar toda energia primeiro
	for (int i = 0; i < 100; i++) {
		repairTest.attack("Target");
	}
	// Tentar reparar sem energia
	repairTest.beRepaired(50);
	std::cout << std::endl;

	std::cout << "=== TESTE 24: Funções especiais em sequência ===" << std::endl;
	frag.highFivesGuys();
	scav.guardGate();
	frag.highFivesGuys();
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "=== Destruição dos objetos ===" << std::endl;
	return 0;
}