/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:48:24 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/22 10:42:54 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "Invalid number of zombies" << std::endl;
		return (NULL);
	}
	Zombie* horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::ostringstream oss;
		oss << i;
		std::string index = oss.str();
		horde[i].setName(name + " " + index);
	}
	return (horde);
}
