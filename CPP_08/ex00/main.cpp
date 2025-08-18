/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:03:55 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/12 16:03:48 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>
#include "easyfind.hpp"

// Função auxiliar para testar qualquer container
template <typename T>
void testContainer(const std::string &name, T &container, int valueToFind)
{
	std::cout << "\n===== Testando em: " << name << " =====" << std::endl;
	try {
		typename T::iterator it = easyfind(container, valueToFind);
		std::cout << "✅ Encontrado: " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "❌ " << e.what() << std::endl;
	}
}

int main()
{
	// 1. Teste com std::vector (valor existente)
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	testContainer("std::vector (valor existente)", vec, 20);

	// 2. Teste com std::vector (valor inexistente)
	testContainer("std::vector (valor inexistente)", vec, 99);

	// 3. Teste com std::list
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	testContainer("std::list (valor existente)", lst, 5);
	testContainer("std::list (valor inexistente)", lst, 999);

	// 4. Teste com std::deque
	std::deque<int> deq;
	for (int i = 1; i <= 5; ++i)
		deq.push_back(i * 10);
	testContainer("std::deque (valor existente)", deq, 50);
	testContainer("std::deque (valor inexistente)", deq, -1);

	// 5. Teste com container vazio
	std::vector<int> emptyVec;
	testContainer("std::vector vazio", emptyVec, 1);

	// 6. Teste com elementos duplicados (deve retornar a primeira ocorrência)
	std::vector<int> dupVec;
	dupVec.push_back(42);
	dupVec.push_back(100);
	dupVec.push_back(42);
	testContainer("std::vector com duplicados", dupVec, 42);

	// 7. Teste valor na primeira posição
	std::vector<int> firstVec;
	firstVec.push_back(7);
	firstVec.push_back(8);
	firstVec.push_back(9);
	testContainer("std::vector (valor na primeira posição)", firstVec, 7);

	// 8. Teste valor na última posição
	std::vector<int> lastVec;
	lastVec.push_back(1);
	lastVec.push_back(2);
	lastVec.push_back(3);
	lastVec.push_back(4);
	lastVec.push_back(5);
	testContainer("std::vector (valor na última posição)", lastVec, 5);

	// 9. Teste com números negativos
	std::list<int> negList;
	negList.push_back(-10);
	negList.push_back(-20);
	negList.push_back(-30);
	negList.push_back(0);
	negList.push_back(10);
	testContainer("std::list (números negativos)", negList, -20);
	testContainer("std::list (número inexistente)", negList, 99);

	return 0;
}
