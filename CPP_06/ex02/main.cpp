/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:14:15 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 15:52:18 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Generate.hpp"
#include "Identify.hpp"

#include <iostream>

void separator(const std::string& title) {
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main() {
	// TESTE 1: Identificação de instâncias manuais
	separator("Teste 1: instâncias manuais");

	A a;
	B b;
	C c;

	Base* baseA = &a;
	Base* baseB = &b;
	Base* baseC = &c;

	std::cout << "[Base*] ";
	identify(baseA);
	std::cout << "[Base&] ";
	identify(*baseA);

	std::cout << "[Base*] ";
	identify(baseB);
	std::cout << "[Base&] ";
	identify(*baseB);

	std::cout << "[Base*] ";
	identify(baseC);
	std::cout << "[Base&] ";
	identify(*baseC);

	// TESTE 2: Identificação de objetos gerados aleatoriamente
	separator("Teste 2: objetos gerados com generate()");

	for (int i = 0; i < 5; ++i) {
		Base* obj = generate();

		std::cout << "[Base*] ";
		identify(obj);

		std::cout << "[Base&] ";
		identify(*obj);

		delete obj;
	}

	// TESTE 3: Ponteiro nulo
	separator("Teste 3: ponteiro nulo");

	Base* nullBase = NULL;
	std::cout << "[Base*] ";
	identify(nullBase);

	// TESTE 4: Referência para objeto real mas do tipo Base
	separator("Teste 4: objeto do tipo Base");

	Base* baseObj = new Base(); // mesmo sendo classe base pura
	std::cout << "[Base*] ";
	identify(baseObj);

	std::cout << "[Base&] ";
	identify(*baseObj); // Deve cair no "Unknown type"

	delete baseObj;

	return 0;
}

