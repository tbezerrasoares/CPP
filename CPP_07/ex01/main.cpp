/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 18:26:12 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/07 14:49:55 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#include <iostream>
#include <string>
#include "iter.hpp"

// Função que imprime o elemento (leitura)
template<typename T>
void printElement(const T& elem) {
	std::cout << elem << " ";
}

// Função que incrementa valor (modifica o array)
void increment(int& n) {
	++n;
}

// Função que converte string para maiúsculas
void toUpper(std::string& s) {
	for (size_t i = 0; i < s.length(); ++i)
		s[i] = std::toupper(s[i]);
}

// Struct personalizada
struct Point {
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void translate() {
		x += 1;
		y += 1;
	}

	void print() const {
		std::cout << "(" << x << ", " << y << ") ";
	}
};

// Função para imprimir Point (por const ref)
void printPoint(const Point& p) {
	p.print();
}

// Função para modificar Point (por ref)
void movePoint(Point& p) {
	p.translate();
}

int main() {
	std::cout << "==== Teste com int ====" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, printElement<int>);
	std::cout << std::endl;
	iter(arr, 5, increment);
	iter(arr, 5, printElement<int>);
	std::cout << "\n" << std::endl;

	std::cout << "==== Teste com char ====" << std::endl;
	char letters[] = {'a', 'b', 'c', 'd'};
	iter(letters, 4, printElement<char>);
	std::cout << "\n" << std::endl;

	std::cout << "==== Teste com string ====" << std::endl;
	std::string words[] = {"hello", "world", "cpp"};
	iter(words, 3, printElement<std::string>);
	std::cout << std::endl;
	iter(words, 3, toUpper);
	iter(words, 3, printElement<std::string>);
	std::cout << "\n" << std::endl;

	std::cout << "==== Teste com struct Point ====" << std::endl;
	Point points[] = {Point(1, 1), Point(2, 2), Point(3, 3)};
	iter(points, 3, printPoint);
	std::cout << std::endl;
	iter(points, 3, movePoint);
	iter(points, 3, printPoint);
	std::cout << "\n" << std::endl;

	std::cout << "==== Teste com array const ====" << std::endl;
	const int cArr[] = {100, 200, 300};
	iter(cArr, 3, printElement<int>);
	std::cout << "\n" << std::endl;

	std::cout << "==== Teste com array de tamanho 0 ====" << std::endl;
	int emptyArr[0];
	iter(emptyArr, 0, printElement<int>);
	std::cout << "Nenhum elemento. Ok." << std::endl;

	return 0;
}

