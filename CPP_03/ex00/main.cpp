/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:44:02 by tbezerra          #+#    #+#             */
/*   Updated: 2025/05/28 14:24:03 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() 
{
	ClapTrap robot("Clappy");

	robot.attack("target1");
	robot.takeDamage(4);
	robot.beRepaired(3);
	robot.takeDamage(10);
	robot.attack("target2");
	robot.beRepaired(5);

	return 0;
}
