/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:11:32 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/15 16:35:32 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"


int Phonebook::_index = 0;

Phonebook::Phonebook() {
	#ifdef DEBUG
		std::cout << "Phonebook constructor called" << std::endl;
	#endif
}

Phonebook::~Phonebook() {
	#ifdef DEBUG
		std::cout << "Phonebook destructor called" << std::endl;
	#endif
}

void Phonebook::add_contact(void){
	this->contacts[this->_index % 8].add_contact(this->_index);
	Phonebook::_index++;
}

/* static void ft_print_s(std::string str)
{
	if (str.length() < 10)
	{
		std::cout << 10;
		for (int i = 10 - str.length(); i; i--)
			std::cout << " ";
	}
	else
		std::cout << str.substr(0, 9) << ".";
} */

void Phonebook::search_contact(void){
	int i = 0;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < 8 && i < this->_index)
	{
		std::cout << std::setw(10) << (this->contacts[i].getIndex() + 1) << "|"
			<< std::setw(10) << (contacts[i].getFirstName().length() > 10 ? 
				contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
			<< std::setw(10) << (contacts[i].getLastName().length() > 10 ? 
				contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
			<< std::setw(10) << (contacts[i].getNickname().length() > 10 ? 
		contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname()) << std::endl;
/* 		ft_print_s(this->contacts[i].getFirstName());
		std::cout << "|";
		ft_print_s(this->contacts[i].getLastName());
		std::cout << "|";
		ft_print_s(this->contacts[i].getNickname());
		std::cout << "|" << std::endl; */
		i++;
	}
	std::cout << "---------------------------------------------" << std::endl;
}

void Phonebook::display_contact(int i) const {
	if (i > this->_index)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	i--;
	std::cout << "Index: " << this->contacts[i].getIndex() + 1 << std::endl;
	std::cout << "First name: " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contacts[i].getDarkestSecret() << std::endl;
}

void Phonebook::get_index(void) const {
	std::cout << "Index: " << this->_index << std::endl;
}