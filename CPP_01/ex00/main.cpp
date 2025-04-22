/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:46:09 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/21 11:56:19 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie one("um");
	Zombie two("dois");
	Zombie *three = newZombie("tres");

	two.announce();
	randomChump("quatro");
	one.announce();
	three->announce();
	delete three;
}