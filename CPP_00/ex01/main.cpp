/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:34:34 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/21 10:28:06 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int ft_atoi_index(std::string str)
{
	int i = 0;
	
	if (str[0] == '\0')
		return (0);
	if (str[i] >= '1' && str[i] <= '8' && str[1] == '\0')
		return (str[i] - '0');
	std::cout << "Invalid index" << std::endl;
	return (-1);
}

int main()
{
	Phonebook pb;
	std::string command;

	std::cout << "Welcome to the Phonebook!" << std::endl;
	std::cout << "Avaible commands: ADD, SEARCH, EXIT" << std::endl;
	while (std::getline(std::cin, command) && command.compare("EXIT"))	
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "Exiting Phonebook..." << std::endl;
			return (0);
		}
		else if (command == "ADD")
			pb.add_contact();
		else if (command == "SEARCH")
		{
			pb.search_contact();
			std::cout << std::endl;
			std::cout << "Enter the index of the contact you want to see: ";
			std::getline(std::cin, command);
			while (ft_atoi_index(command) == -1)
			{
				std::cout << "Select a valid index: ";
				std::getline(std::cin, command);
			}
			if (ft_atoi_index(command))
				pb.display_contact(ft_atoi_index(command));
		}
		std::cout << "Avaible commands: ADD, SEARCH, EXIT" << std::endl;
	}
}
