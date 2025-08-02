/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:43:18 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/22 14:39:06 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	checkExecutability(executor);

	std::string filename = target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		return;

	file << "         🌲\n";
	file << "        🌳🌲\n";
	file << "       🌲🌳🌲\n";
	file << "      🌳🌲🌳🌲\n";
	file << "     🌲🌲🌳🌳🌲\n";
	file << "       ||||||\n";
	file << "       ||||||\n";
	file.close();
}
