/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:43:52 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/21 14:31:23 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde = zombieHorde(5, "Zombie");
	
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	
	delete[] horde;
	return (0);
}