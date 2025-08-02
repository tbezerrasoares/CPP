/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:02:42 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 14:13:30 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

#include "Serializer.hpp"
#include <iostream>
#include <vector>

void printTestResult(Data* original, Data* recovered, int index) {
	std::cout << "===== Test " << index << " =====" << std::endl;
	std::cout << "Original address : " << original << std::endl;
	std::cout << "Recovered address: " << recovered << std::endl;

	if (original == recovered)
		std::cout << "✅ Success: addresses match!" << std::endl;
	else
		std::cout << "❌ Failure: addresses do not match!" << std::endl;

	std::cout << "Recovered->number: " << recovered->number << std::endl;
	std::cout << "Recovered->name  : " << recovered->name << std::endl;
	std::cout << std::endl;
}

int main() {
	// Vetor de instâncias de Data
	std::vector<Data> dataList(3);

	// Preencher os dados
	dataList[0].number = 10;
	dataList[0].name = "Alice";

	dataList[1].number = 20;
	dataList[1].name = "Bob";

	dataList[2].number = 30;
	dataList[2].name = "Charlie";

	// Executar testes
	for (size_t i = 0; i < dataList.size(); ++i) {
		Data* original = &dataList[i];

		// Serializar e desserializar
		uintptr_t raw = Serializer::serialize(original);
		Data* recovered = Serializer::deserialize(raw);

		// Imprimir resultado
		printTestResult(original, recovered, static_cast<int>(i + 1));
	}

	// Teste adicional com objeto dinâmico
	std::cout << "===== Test 4 (alocado com new) =====" << std::endl;
	Data* dyn = new Data;
	dyn->number = 99;
	dyn->name = "Dynamic";

	uintptr_t raw = Serializer::serialize(dyn);
	Data* rec = Serializer::deserialize(raw);

	printTestResult(dyn, rec, 4);

	delete dyn;

	return 0;
}

