/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:05:56 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/22 13:50:24 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		std::cout << "Criando Bureaucrat com nome e grau válidos:" << std::endl;
		Bureaucrat a("Pedro", 5);
		std::cout << a << std::endl;
		std::cout << "Tentando incrementar o grau de Pedro:" << std::endl;
		a.incrementGrade(); // Deve funcionar
	} catch (std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try {
		std::cout << "Criando Bureaucrat com Aline grade(1):" << std::endl;
		Bureaucrat b("Alice", 1);
		std::cout << b << std::endl;
		std::cout << "Tentando incrementar o grau de Alice:" << std::endl;
		b.incrementGrade(); // Deve lançar exceção
	} catch (std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Criando Bureaucrat com Bob grade(150):" << std::endl;
		Bureaucrat c("Bob", 150);
		std::cout << c << std::endl;
		std::cout << "Tentando decrementar o grau de Bob:" << std::endl;
		c.decrementGrade(); // Deve lançar exceção
	} catch (std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << "Criando Bureaucrat com nome inválido e grau inválido (Grade 0):" << std::endl;
		Bureaucrat d("Charlie", 0); // Deve lançar exceção no construtor
	} catch (std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	return 0;
}
