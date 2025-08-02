/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:52:19 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 17:27:56 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

// Tipo personalizado para testes
struct Point {
	int x, y;

	// Construtor
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	// Operadores para comparar
	bool operator<(const Point& other) const {
		return (x*x + y*y) < (other.x*other.x + other.y*other.y); // distância da origem
	}

	bool operator>(const Point& other) const {
		return (x*x + y*y) > (other.x*other.x + other.y*other.y);
	}

	// Para imprimir
	friend std::ostream& operator<<(std::ostream& os, const Point& p) {
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}
};

int main() {
	std::cout << "===== Teste com int =====" << std::endl;
	int a = 10, b = 20;
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "SWAP(a, b)\n";
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "min = " << ::min(a, b) << ", max = " << ::max(a, b) << "\n\n";

	std::cout << "===== Teste com float =====" << std::endl;
	float fa = 3.14f, fb = 1.59f;
	std::cout << "fa = " << fa << ", fb = " << fb << "\n";
	std::cout << "SWAP\n";
	::swap(fa, fb);
	std::cout << "fa = " << fa << ", fb = " << fb << "\n";
	std::cout << "min = " << ::min(fa, fb) << ", max = " << ::max(fa, fb) << "\n\n";

	std::cout << "===== Teste com char =====" << std::endl;
	char ca = 'z', cb = 'a';
	std::cout << "ca = " << ca << ", cb = " << cb << "\n";
	std::cout << "SWAP\n";
	::swap(ca, cb);
	std::cout << "ca = " << ca << ", cb = " << cb << "\n";
	std::cout << "min = " << ::min(ca, cb) << ", max = " << ::max(ca, cb) << "\n\n";

	std::cout << "===== Teste com bool =====" << std::endl;
	bool ba = true, bb = false;
	std::cout << "ba = " << ba << ", bb = " << bb << "\n";
	std::cout << "SWAP\n";
	::swap(ba, bb);
	std::cout << "ba = " << ba << ", bb = " << bb << "\n";
	std::cout << "min = " << ::min(ba, bb) << ", max = " << ::max(ba, bb) << "\n\n";

	std::cout << "===== Teste com string =====" << std::endl;
	std::string s1 = "banana", s2 = "abacaxi";
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << "\n";
	std::cout << "SWAP\n";
	::swap(s1, s2);
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << "\n";
	std::cout << "min = " << ::min(s1, s2) << ", max = " << ::max(s1, s2) << "\n\n";

	std::cout << "===== Teste com igualdade =====" << std::endl;
	int e1 = 42, e2 = 42;
	std::cout << "min(42, 42) = " << ::min(e1, e2) << ", max(42, 42) = " << ::max(e1, e2) << "\n\n";

	std::cout << "===== Teste com struct Point =====" << std::endl;
	Point p1(3, 4); // distância = 5
	Point p2(6, 8); // distância = 10
	std::cout << "p1 = " << p1 << ", p2 = " << p2 << "\n";
	std::cout << "SWAP\n";
	::swap(p1, p2);
	std::cout << "p1 = " << p1 << ", p2 = " << p2 << "\n";
	std::cout << "min = " << ::min(p1, p2) << ", max = " << ::max(p1, p2) << "\n\n";

	std::cout << "===== Teste com const =====" << std::endl;
	const int cx = 15, cy = 7;
	std::cout << "min(const int) = " << ::min(cx, cy) << ", max(const int) = " << ::max(cx, cy) << "\n";

	return 0;
}

