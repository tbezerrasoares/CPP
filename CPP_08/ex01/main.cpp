/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by tbezerra          #+#    #+#             */
/*   Updated: 2025/10/01 11:17:03 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

void testBasicFunctionality()
{
	std::cout << "\n=== TESTE 1: Funcionalidade Básica ===" << std::endl;
	
	try {
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "✅ Números adicionados com sucesso" << std::endl;
		std::cout << "Tamanho atual: " << sp.size() << "/" << sp.maxSize() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "❌ Erro: " << e.what() << std::endl;
	}
}

void testExceptions()
{
	std::cout << "\n=== TESTE 2: Teste de Exceções ===" << std::endl;
	
	// Teste 1: Span cheio
	try {
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		std::cout << "✅ Span preenchido normalmente" << std::endl;
		sp.addNumber(3); // Deve lançar exceção
	}
	catch (std::exception &e) {
		std::cout << "✅ Exceção capturada corretamente: " << e.what() << std::endl;
	}
	
	// Teste 2: Span com elementos insuficientes
	try {
		Span sp(5);
		sp.addNumber(42);
		std::cout << "Tentando calcular span com apenas 1 elemento..." << std::endl;
		sp.shortestSpan(); // Deve lançar exceção
	}
	catch (std::exception &e) {
		std::cout << "✅ Exceção capturada corretamente: " << e.what() << std::endl;
	}

	// Teste 3: Span vazio
	try {
		Span sp(5);
		std::cout << "Tentando calcular span em container vazio..." << std::endl;
		sp.longestSpan(); // Deve lançar exceção
	}
	catch (std::exception &e) {
		std::cout << "✅ Exceção capturada corretamente: " << e.what() << std::endl;
	}
}

void testRangeInsertion()
{
	std::cout << "\n=== TESTE 3: Inserção de Range ===" << std::endl;
	
	try {
		// Teste com std::vector
		std::vector<int> vec;
		for (int i = 1; i <= 10; ++i)
			vec.push_back(i * 10);
		
		Span sp(15);
		sp.addRange(vec.begin(), vec.end());
		
		std::cout << "✅ Range de vector adicionado com sucesso" << std::endl;
		std::cout << "Tamanho: " << sp.size() << "/" << sp.maxSize() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "❌ Erro: " << e.what() << std::endl;
	}
	
	// Teste com range muito grande
	try {
		std::vector<int> bigVec;
		for (int i = 0; i < 100; ++i)
			bigVec.push_back(i);
		
		Span sp(50);
		std::cout << "Tentando adicionar range maior que a capacidade..." << std::endl;
		sp.addRange(bigVec.begin(), bigVec.end()); // Deve lançar exceção
	}
	catch (std::exception &e) {
		std::cout << "✅ Exceção capturada corretamente: " << e.what() << std::endl;
	}
}

void testLargeDataset()
{
	std::cout << "\n=== TESTE 4: Dataset Grande (Performance) ===" << std::endl;
	
	try {
		const unsigned int SIZE = 20000;
		Span sp(SIZE);
		
		// Gera números aleatórios
		std::srand(std::time(NULL));
		std::vector<int> randomNumbers;
		for (unsigned int i = 0; i < SIZE; ++i) {
			randomNumbers.push_back(std::rand() % 100000);
		}
		
		// Adiciona usando range
		sp.addRange(randomNumbers.begin(), randomNumbers.end());
		
		std::cout << "✅ " << SIZE << " números adicionados com sucesso" << std::endl;
		std::cout << "Calculando spans..." << std::endl;
		
		unsigned int shortest = sp.shortestSpan();
		unsigned int longest = sp.longestSpan();
		
		std::cout << "✅ Shortest span: " << shortest << std::endl;
		std::cout << "✅ Longest span: " << longest << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "❌ Erro: " << e.what() << std::endl;
	}
}

void testCopyAndAssignment()
{
	std::cout << "\n=== TESTE 5: Cópia e Atribuição ===" << std::endl;
	
	try {
		// Teste construtor de cópia
		Span original(5);
		original.addNumber(1);
		original.addNumber(100);
		original.addNumber(50);
		
		Span copy(original);
		std::cout << "✅ Construtor de cópia funciona" << std::endl;
		std::cout << "Original shortest span: " << original.shortestSpan() << std::endl;
		std::cout << "Copy shortest span: " << copy.shortestSpan() << std::endl;
		
		// Teste operador de atribuição
		Span assigned(10);
		assigned = original;
		std::cout << "✅ Operador de atribuição funciona" << std::endl;
		std::cout << "Assigned longest span: " << assigned.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "❌ Erro: " << e.what() << std::endl;
	}
}

void testEdgeCases()
{
	std::cout << "\n=== TESTE 6: Casos Extremos ===" << std::endl;
	
	try {
		// Teste com números negativos
		Span sp(5);
		sp.addNumber(-100);
		sp.addNumber(-50);
		sp.addNumber(0);
		sp.addNumber(25);
		sp.addNumber(100);
		
		std::cout << "✅ Números negativos e positivos" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		// Teste com números iguais
		Span sp2(3);
		sp2.addNumber(42);
		sp2.addNumber(42);
		sp2.addNumber(42);
		
		std::cout << "✅ Números iguais" << std::endl;
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "❌ Erro: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "🚀 TESTANDO CLASSE SPAN 🚀" << std::endl;
	
	testBasicFunctionality();
	testExceptions();
	testRangeInsertion();
	testLargeDataset();
	testCopyAndAssignment();
	testEdgeCases();
	
	std::cout << "\n🎉 Todos os testes concluídos!" << std::endl;
	
	return 0;
}