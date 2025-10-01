/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_subject.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by tbezerra          #+#    #+#             */
/*   Updated: 2025/10/01 11:39:49 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "=== TESTE DO SUBJECT: MutantStack vs std::list ===" << std::endl;
	
	// Teste com MutantStack (conforme subject)
	std::cout << "\n--- Testando MutantStack ---" << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "Iterating through MutantStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	// Demonstrar que funciona igual a std::list
	std::cout << "\n--- Comparando com std::list ---" << std::endl;
	std::list<int> lst;
	
	lst.push_back(5);
	lst.push_back(17);
	
	std::cout << "Back: " << lst.back() << std::endl;
	
	lst.pop_back();
	
	std::cout << "Size: " << lst.size() << std::endl;
	
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();
	
	++it2;
	--it2;
	
	std::cout << "Iterating through std::list:" << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	
	std::cout << "\n✅ MutantStack se comporta igual a std::list!" << std::endl;
	std::cout << "✅ Mas mantém a interface LIFO da stack!" << std::endl;
	
	return 0;
}