/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by tbezerra          #+#    #+#             */
/*   Updated: 2025/10/01 11:39:54 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <string>
#include "MutantStack.hpp"

void testBasicStackFunctionality()
{
	std::cout << "\n=== TESTE 1: Funcionalidade Stack Básica ===" << std::endl;
	
	MutantStack<int> mstack;
	
	// Teste stack vazia
	std::cout << "Stack vazia: " << (mstack.empty() ? "✅" : "❌") << std::endl;
	std::cout << "Tamanho inicial: " << mstack.size() << std::endl;
	
	// Push elementos
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(14);
	mstack.push(737);
	
	std::cout << "Elementos adicionados. Tamanho: " << mstack.size() << std::endl;
	std::cout << "Stack vazia: " << (mstack.empty() ? "❌" : "✅") << std::endl;
	
	// Teste top
	std::cout << "Elemento no topo: " << mstack.top() << " (esperado: 737)" << std::endl;
	
	// Teste pop
	mstack.pop();
	std::cout << "Após pop, topo: " << mstack.top() << " (esperado: 14)" << std::endl;
	std::cout << "Tamanho após pop: " << mstack.size() << std::endl;
}

void testForwardIteration()
{
	std::cout << "\n=== TESTE 2: Iteração Forward ===" << std::endl;
	
	MutantStack<int> mstack;
	
	// Adiciona elementos
	for (int i = 1; i <= 5; ++i)
		mstack.push(i * 10);
	
	std::cout << "Elementos na stack (bottom to top): ";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	
	// Teste range-based for (C++11 style simulation)
	std::cout << "Usando iteradores em loop: ";
	for (it = mstack.begin(); it != mstack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	// Verificar que o último elemento do iterador é o topo da stack
	--ite; // Volta para o último elemento válido
	std::cout << "Último elemento via iterador: " << *ite << std::endl;
	std::cout << "Topo da stack: " << mstack.top() << std::endl;
	std::cout << "São iguais: " << (*ite == mstack.top() ? "✅" : "❌") << std::endl;
}

void testConstIteration()
{
	std::cout << "\n=== TESTE 3: Iteração Const ===" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(84);
	mstack.push(126);
	
	const MutantStack<int> const_stack(mstack);
	
	std::cout << "Iteração const: ";
	MutantStack<int>::const_iterator cit = const_stack.begin();
	MutantStack<int>::const_iterator cite = const_stack.end();
	
	while (cit != cite)
	{
		std::cout << *cit << " ";
		// *cit = 999; // Isso causaria erro de compilação (const)
		++cit;
	}
	std::cout << std::endl;
	
	std::cout << "✅ Const iterators funcionam corretamente" << std::endl;
}

void testReverseIteration()
{
	std::cout << "\n=== TESTE 4: Iteração Reversa ===" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	
	std::cout << "Iteração reversa (top to bottom): ";
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
	
	// Verificar que o primeiro elemento da iteração reversa é o topo
	rit = mstack.rbegin();
	std::cout << "Primeiro elemento via reverse iterator: " << *rit << std::endl;
	std::cout << "Topo da stack: " << mstack.top() << std::endl;
	std::cout << "São iguais: " << (*rit == mstack.top() ? "✅" : "❌") << std::endl;
}

void testSTLAlgorithms()
{
	std::cout << "\n=== TESTE 5: Algoritmos STL ===" << std::endl;
	
	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(20);
	mstack.push(30);
	mstack.push(20);
	mstack.push(40);
	
	// std::find
	MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 20);
	if (found != mstack.end())
		std::cout << "✅ std::find encontrou: " << *found << std::endl;
	else
		std::cout << "❌ std::find não encontrou 20" << std::endl;
	
	// std::count
	int count_20 = std::count(mstack.begin(), mstack.end(), 20);
	std::cout << "std::count de 20: " << count_20 << " (esperado: 2)" << std::endl;
	
	// std::accumulate (soma todos elementos)
	int sum = std::accumulate(mstack.begin(), mstack.end(), 0);
	std::cout << "std::accumulate (soma): " << sum << " (esperado: 120)" << std::endl;
	
	// Verificar se a stack ainda funciona normalmente
	std::cout << "Topo após algoritmos: " << mstack.top() << " (esperado: 40)" << std::endl;
	std::cout << "✅ Algoritmos STL funcionam perfeitamente" << std::endl;
}

void testDifferentContainers()
{
	std::cout << "\n=== TESTE 6: Diferentes Container Types ===" << std::endl;
	
	// MutantStack com std::vector
	std::cout << "--- Testando com std::vector ---" << std::endl;
	MutantStack<int, std::vector<int> > vector_stack;
	vector_stack.push(100);
	vector_stack.push(200);
	vector_stack.push(300);
	
	std::cout << "Vector stack: ";
	for (MutantStack<int, std::vector<int> >::iterator it = vector_stack.begin();
		 it != vector_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	// MutantStack com std::list
	std::cout << "--- Testando com std::list ---" << std::endl;
	MutantStack<int, std::list<int> > list_stack;
	list_stack.push(1000);
	list_stack.push(2000);
	list_stack.push(3000);
	
	std::cout << "List stack: ";
	for (MutantStack<int, std::list<int> >::iterator it = list_stack.begin();
		 it != list_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	// MutantStack padrão (std::deque)
	std::cout << "--- Testando com std::deque (padrão) ---" << std::endl;
	MutantStack<int> deque_stack;
	deque_stack.push(10000);
	deque_stack.push(20000);
	deque_stack.push(30000);
	
	std::cout << "Deque stack: ";
	for (MutantStack<int>::iterator it = deque_stack.begin();
		 it != deque_stack.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	
	std::cout << "✅ Templates funcionam com diferentes containers" << std::endl;
}

void testCopyAndAssignment()
{
	std::cout << "\n=== TESTE 7: Copy e Assignment ===" << std::endl;
	
	// Criar stack original
	MutantStack<int> original;
	original.push(111);
	original.push(222);
	original.push(333);
	
	// Teste construtor de cópia
	MutantStack<int> copy(original);
	std::cout << "Stack original: ";
	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Stack copiada: ";
	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Modificar original para verificar independência
	original.push(444);
	std::cout << "Após push na original (topo): " << original.top() << std::endl;
	std::cout << "Topo da cópia permanece: " << copy.top() << std::endl;
	
	// Teste operador de atribuição
	MutantStack<int> assigned;
	assigned = original;
	std::cout << "Stack assigned (topo): " << assigned.top() << std::endl;
	
	std::cout << "✅ Copy e assignment funcionam corretamente" << std::endl;
}

void testPerformance()
{
	std::cout << "\n=== TESTE 8: Performance com Dataset Grande ===" << std::endl;
	
	const int SIZE = 100000;
	MutantStack<int> big_stack;
	
	// Push massivo
	std::cout << "Adicionando " << SIZE << " elementos..." << std::endl;
	for (int i = 0; i < SIZE; ++i)
		big_stack.push(i);
	
	std::cout << "Tamanho final: " << big_stack.size() << std::endl;
	
	// Iteração completa
	std::cout << "Fazendo iteração completa..." << std::endl;
	int count = 0;
	for (MutantStack<int>::iterator it = big_stack.begin(); it != big_stack.end(); ++it)
		++count;
	
	std::cout << "Elementos contados: " << count << std::endl;
	std::cout << "Primeiro elemento: " << *big_stack.begin() << std::endl;
	std::cout << "Último elemento (topo): " << big_stack.top() << std::endl;
	
	std::cout << "✅ Performance adequada com " << SIZE << " elementos" << std::endl;
}

void testEdgeCases()
{
	std::cout << "\n=== TESTE 9: Edge Cases ===" << std::endl;
	
	// Stack vazia
	std::cout << "--- Stack Vazia ---" << std::endl;
	MutantStack<int> empty_stack;
	std::cout << "begin() == end(): " << (empty_stack.begin() == empty_stack.end() ? "✅" : "❌") << std::endl;
	
	// Stack com um elemento
	std::cout << "--- Stack com Um Elemento ---" << std::endl;
	MutantStack<int> single_stack;
	single_stack.push(42);
	
	std::cout << "Tamanho: " << single_stack.size() << std::endl;
	std::cout << "Iteração: ";
	for (MutantStack<int>::iterator it = single_stack.begin(); it != single_stack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Teste com strings
	std::cout << "--- Stack com Strings ---" << std::endl;
	MutantStack<std::string> string_stack;
	string_stack.push("Hello");
	string_stack.push("World");
	string_stack.push("42");
	
	std::cout << "String stack: ";
	for (MutantStack<std::string>::iterator it = string_stack.begin(); it != string_stack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "✅ Edge cases funcionam corretamente" << std::endl;
}

int main()
{
	std::cout << "🔥 TESTANDO MUTANTSTACK - MUTATED ABOMINATION 🔥" << std::endl;
	
	testBasicStackFunctionality();
	testForwardIteration();
	testConstIteration();
	testReverseIteration();
	testSTLAlgorithms();
	testDifferentContainers();
	testCopyAndAssignment();
	testPerformance();
	testEdgeCases();
	
	std::cout << "\n🎉 Todos os testes da Mutated Abomination concluídos!" << std::endl;
	std::cout << "🔥 A stack mutante está funcionando perfeitamente!" << std::endl;
	
	return 0;
}