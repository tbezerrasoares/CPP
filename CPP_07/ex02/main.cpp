/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:44:57 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 18:48:27 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

// Struct personalizada para teste
struct Point {
	int x, y;

	Point(int x = 0, int y = 0) : x(x), y(y) {}

	// Método público para imprimir
	void print() const {
		std::cout << "(" << x << ", " << y << ")";
	}
};

int main() {
	std::cout << "==== Teste com inteiros ====" << std::endl;
	Array<int> a(5);
	for (std::size_t i = 0; i < a.size(); ++i)
		a[i] = static_cast<int>(i * 10);

	for (std::size_t i = 0; i < a.size(); ++i)
		std::cout << "a[" << i << "] = " << a[i] << std::endl;

	std::cout << "\n==== Teste com strings ====" << std::endl;
	Array<std::string> s(3);
	s[0] = "Olá";
	s[1] = "C++";
	s[2] = "Templates";

	for (std::size_t i = 0; i < s.size(); ++i)
		std::cout << "s[" << i << "] = " << s[i] << std::endl;

	std::cout << "\n==== Teste com structs (Point) ====" << std::endl;
	Array<Point> points(2);
	points[0] = Point(1, 2);
	points[1] = Point(3, 4);

	for (std::size_t i = 0; i < points.size(); ++i) {
		std::cout << "points[" << i << "] = ";
		points[i].print();
		std::cout << std::endl;
	}

	std::cout << "\n==== Teste de cópia profunda ====" << std::endl;
	Array<std::string> s_copy = s;
	s_copy[0] = "Tchau";
	std::cout << "s[0] = " << s[0] << ", s_copy[0] = " << s_copy[0] << std::endl;

	std::cout << "\n==== Teste de array vazio ====" << std::endl;
	Array<float> vazio;
	std::cout << "Tamanho: " << vazio.size() << std::endl;

	std::cout << "\n==== Teste de exceção por acesso inválido ====" << std::endl;
	try {
		std::cout << a[10] << std::endl; // Fora dos limites
	} catch (const std::exception& e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	return 0;
}

