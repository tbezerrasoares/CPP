/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:48:28 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/22 10:48:58 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		
		void announce(void) const;
		void setName(std::string name);
	
	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std:: string name);
Zombie* zombieHorde(int N, std::string name);

#endif