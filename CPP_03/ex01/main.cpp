/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:29:02 by tbezerra          #+#    #+#             */
/*   Updated: 2025/05/28 14:54:07 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap bot("Serena");

	bot.attack("target");
	bot.takeDamage(40);
	bot.beRepaired(20);
	bot.guardGate();

	return 0;
}
