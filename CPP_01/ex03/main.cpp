/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:58:08 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/23 09:35:00 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
//#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}

/* int main() {
	Weapon club = Weapon("crude spiked club");

	HumanA bob("Bob", club);
	bob.attack(); // Bob attacks with their crude spiked club

	club.setType("some other type of club");
	bob.attack(); // Bob attacks with their some other type of club

	Weapon club2 = Weapon("shiny sword");

	HumanB jim("Jim");
	jim.setWeapon(club2);
	jim.attack(); // Jim attacks with their shiny sword

	club2.setType("broken dagger");
	jim.attack(); // Jim attacks with their broken dagger

	return 0;
} */