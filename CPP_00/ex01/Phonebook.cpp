/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:11:32 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/09 17:37:20 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

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

