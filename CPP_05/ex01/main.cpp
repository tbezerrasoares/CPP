/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:09:48 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/12 16:54:43 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		std::cout << "Create Bureaucrat e Form..." << std::endl;
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
		std::cout << std::endl;
		Form formA("TaxForm", 50, 20);

		std::cout << formA << std::endl;

		bob.signForm(formA); // Falha

		std::cout << std::endl;
		std::cout << "Trying to sign the form with a higher-level Bureaucrat..." << std::endl;
		Bureaucrat alice("Alice", 45);
		std::cout << alice << std::endl;
		alice.signForm(formA); // Sucesso

		std::cout << formA << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	return 0;
}
