/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:06:39 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/09 17:07:48 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class	Phonebook {
	public:
		Phonebook();
		~Phonebook();

		void	add_contact();
		void	search_contact();
		void	display_contact(int index) const;
		void	exit() const;
	private:
		Contact	_contacts[8];
		static int	_index;
};
#endif