/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:27:35 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/26 18:51:38 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	Intern someIntern;
	Bureaucrat chief("Chief", 1);

	// Testes válidos
	AForm* form1 = someIntern.makeForm("shrubbery creation", "Garden");
	AForm* form2 = someIntern.makeForm("robotomy request", "Bender");
	AForm* form3 = someIntern.makeForm("presidential pardon", "Arthur Dent");
	std::cout << std::endl;

	if (form1) {
		chief.signForm(*form1);
		chief.executeForm(*form1);
		delete form1;
	}
	std::cout << std::endl;

	if (form2) {
		chief.signForm(*form2);
		chief.executeForm(*form2);
		delete form2;
	}
	std::cout << std::endl;

	if (form3) {
		chief.signForm(*form3);
		chief.executeForm(*form3);
		delete form3;
	}
	std::cout << std::endl;

	// Teste inválido
	AForm* invalidForm = someIntern.makeForm("coffee request", "Intern");
	if (invalidForm)
		delete invalidForm;

	return 0;
}
