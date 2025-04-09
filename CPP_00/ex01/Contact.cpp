/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:20:22 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/09 17:28:56 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _index(0) {
	#ifdef DEBUG
		std::cout << "Contact constructor called" << std::endl;
	#endif
}

Contact::~Contact() {
	#ifdef DEBUG
		std::cout << "Contact destructor called" << std::endl;
	#endif
}

static void	getNonEmptyInput(std::string &input, const std::string &prompt) {
	std::string temp;
	
	std::cout << prompt;
	while (std::getline(std::cin, temp) && temp.empty()) {
		std::cout << "Input cannot be empty. Please try again: " << std::endl << prompt;
	}
	input = temp;
}

static bool isPhoneNumber(const std::string &phoneNumber) {
	int i;

	if ((!std::isdigit(phoneNumber[0]) && phoneNumber[0] != '+') || (phoneNumber[0] == '+' && !std::isdigit(phoneNumber[1])))
	{
		std::cout << "Please enter a valid number (no brackets, only '+' and digits allowed)" << std::endl;
		return (false);
	}
	for (i = 1; phoneNumber[i]; i++)
	{
		if (!std::isdigit(phoneNumber[i]))
		{
			std::cout << "Please enter a valid number (no brackets, only '+' and digits allowed)" << std::endl;
			return (false);
		}
	}
	if ((phoneNumber[0] == '+' && i < 4) || i < 3)
	{
		std::cout << "Please enter a valid number (min 3 digits)" << std::endl;
		return (false);
	}
	return (true);
}

void	Contact::add_contact(int i) {
	std::string phoneNumber;

	this->_index = i;
	getNonEmptyInput(_firstName, "Enter first name: ");
	getNonEmptyInput(_lastName, "Enter last name: ");
	getNonEmptyInput(_nickname, "Enter nickname: ");
	getNonEmptyInput(phoneNumber, "Enter phone number: ");
	while (!isPhoneNumber(phoneNumber))
		getNonEmptyInput(phoneNumber, "Enter phone number: ");
	this->_phoneNumber = phoneNumber;
	getNonEmptyInput(_darkestSecret, "Enter darkest secret: ");
}

int	Contact::getIndex() const {
	return this->_index;
}

std::string	Contact::getFirstName() const {
	return this->_firstName;
}

std::string	Contact::getLastName() const {
	return this->_lastName;
}

std::string	Contact::getNickname() const {
	return this->_nickname;
}

std::string	Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}
