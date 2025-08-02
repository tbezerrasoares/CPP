/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:24:21 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/26 17:25:59 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Factory functions
static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// Constructor / Canonical
Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

// Main factory logic
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	typedef AForm* (*FormCreator)(const std::string&);

	struct FormType {
		std::string name;
		FormCreator creator;
	};

	FormType forms[3] = {
		{ "shrubbery creation", createShrubbery },
		{ "robotomy request", createRobotomy },
		{ "presidential pardon", createPresidential }
	};

	for (int i = 0; i < 3; ++i) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}

	std::cerr << "Intern couldn't find the form: " << formName << std::endl;
	return NULL;
}
