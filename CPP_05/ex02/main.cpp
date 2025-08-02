/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 17:27:35 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/26 17:27:02 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void printSeparator(const std::string& title) {
	std::cout << "\n" << std::string(50, '=') << std::endl;
	std::cout << "  " << title << std::endl;
	std::cout << std::string(50, '=') << std::endl;
}

void testFormCreation() {
	printSeparator("TESTE: CRIAÇÃO DE FORMULÁRIOS");

	try {
		std::cout << "Criando formulários:" << std::endl;
		ShrubberyCreationForm shrub("jardim");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Ford");

		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

	} catch (std::exception& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
}

void testFormSigning() {
	printSeparator("TESTE: ASSINATURA DE FORMULÁRIOS");

	try {
		Bureaucrat highRank("Boss", 1);
		Bureaucrat midRank("Manager", 50);
		Bureaucrat lowRank("Intern", 150);

		ShrubberyCreationForm shrub("escritorio");
		RobotomyRequestForm robot("C3PO");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << "Estado inicial dos formulários:" << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		std::cout << "\nTentando assinar com diferentes ranks:" << std::endl;

		// Shrub (145/137) - lowRank não consegue assinar
		std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
		try {
			lowRank.signForm(shrub);
		} catch (std::exception& e) {
			std::cout << "Erro: " << e.what() << std::endl;
	}

		midRank.signForm(shrub); // Deve conseguir
		std::cout << shrub << std::endl;

		// Robot (72/45) - midRank consegue assinar
		std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
		midRank.signForm(robot);
		std::cout << robot << std::endl;

		// Pardon (25/5) - só highRank consegue assinar
		std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
		try {
			midRank.signForm(pardon);
		} catch (std::exception& e) {
			std::cout << "Erro: " << e.what() << std::endl;
		}

		highRank.signForm(pardon); // Deve conseguir
		std::cout << pardon << std::endl;

	} catch (std::exception& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
}

void testFormExecution() {
	printSeparator("TESTE: EXECUÇÃO DE FORMULÁRIOS");

	try {
		Bureaucrat executor("Executor", 1);
		Bureaucrat weakExecutor("Weak", 150);

		ShrubberyCreationForm shrub("casa");
		RobotomyRequestForm robot("R2D2");
		PresidentialPardonForm pardon("Marvin");

		// Assinar todos os formulários primeiro
		executor.signForm(shrub);
		executor.signForm(robot);
		executor.signForm(pardon);

		std::cout << "Formulários assinados, testando execução:" << std::endl;

		// Teste execução com rank alto
		std::cout << "\n--- Executando com rank alto ---" << std::endl;
		executor.executeForm(shrub);
		executor.executeForm(robot);
		executor.executeForm(pardon);

		// Teste execução com rank baixo
		std::cout << "\n--- Tentando executar com rank baixo ---" << std::endl;
		RobotomyRequestForm robot2("BB8");
		executor.signForm(robot2);

		try {
			weakExecutor.executeForm(robot2);
		} catch (std::exception& e) {
			std::cout << "Erro capturado: " << e.what() << std::endl;
		}

		// Teste execução de formulário não assinado
		std::cout << "\n--- Tentando executar formulário não assinado ---" << std::endl;
		ShrubberyCreationForm notSigned("nao_assinado");
		try {
			executor.executeForm(notSigned);
		} catch (std::exception& e) {
			std::cout << "Erro capturado: " << e.what() << std::endl;
		}

	} catch (std::exception& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
}

void testMultipleRobotomy() {
	printSeparator("TESTE: MÚLTIPLAS ROBOTOMIAS");

	try {
		Bureaucrat doctor("Dr. Zoidberg", 1);
		RobotomyRequestForm robot("Wall-E");

		doctor.signForm(robot);

		std::cout << "Executando robotomia múltiplas vezes (50% chance cada):" << std::endl;
		for (int i = 1; i <= 5; i++) {
			std::cout << "\nTentativa " << i << ":" << std::endl;
			doctor.executeForm(robot);
		}

	} catch (std::exception& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
}

void testCopyAndAssignment() {
	printSeparator("TESTE: CÓPIA E ATRIBUIÇÃO");

	try {
		std::cout << "Testando cópia de Bureaucrat:" << std::endl;
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		Bureaucrat assigned("Temp", 100);

		std::cout << "Original: " << original << std::endl;
		std::cout << "Cópia: " << copy << std::endl;

		assigned = original;
		std::cout << "Atribuído: " << assigned << std::endl;

		std::cout << "\nTestando cópia de Formulário:" << std::endl;
		ShrubberyCreationForm originalForm("original");
		ShrubberyCreationForm copyForm(originalForm);

		std::cout << "Original: " << originalForm << std::endl;
		std::cout << "Cópia: " << copyForm << std::endl;

	} catch (std::exception& e) {
		std::cout << "Erro: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "=== TESTE COMPLETO CPP_05/EX02 ===" << std::endl;

	testFormCreation();
	testFormSigning();
	testFormExecution();
	testMultipleRobotomy();
	testCopyAndAssignment();

	printSeparator("TESTES CONCLUÍDOS");
	std::cout << "Verifique os arquivos *_shrubbery criados no diretório!" << std::endl;

	return 0;
}
