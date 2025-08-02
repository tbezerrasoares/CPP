/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:41:59 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/30 19:02:05 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cctype>

void ScalarConverter::convert(const std::string& literal) {
	// Caso 1: é um único char (não número)
	if (literal.length() == 1 && !std::isdigit(literal[0])) {
		char c = literal[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);

		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}

	// Caso 2: pseudo-literais
	if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
		literal == "nanf" || literal == "+inff" || literal == "-inff") {
		bool isFloat = literal[literal.length() - 1] == 'f';

		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << (isFloat ? literal : literal + "f") << std::endl;
		std::cout << "double: " << (isFloat ? literal.substr(0, literal.length() - 1) : literal) << std::endl;
		return;
	}

	// Caso 3: tentar como int
	{
		std::istringstream iss(literal);
		int i;
		if ((iss >> i) && iss.eof()) {
			char c = static_cast<char>(i);
			float f = static_cast<float>(i);
			double d = static_cast<double>(i);

			if (i >= 32 && i <= 126)
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;

			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			return;
		}
	}

	// Caso 4: tentar como float (termina com 'f')
	if (literal[literal.length() - 1] == 'f') {
		std::string trimmed = literal.substr(0, literal.length() - 1);
		double d = std::atof(trimmed.c_str());
		float f = static_cast<float>(d);
		int i = static_cast<int>(f);
		char c = static_cast<char>(f);

		if (std::isnan(f) || std::isinf(f))
			std::cout << "char: impossible" << std::endl;
		else if (i >= 32 && i <= 126)
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;

		if (std::isnan(f) || std::isinf(f))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;

		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}

	// Caso 5: tentar como double
	{
		std::istringstream iss(literal);
		double d;
		if ((iss >> d) && iss.eof()) {
			float f = static_cast<float>(d);
			int i = static_cast<int>(d);
			char c = static_cast<char>(d);

			if (std::isnan(d) || std::isinf(d))
				std::cout << "char: impossible" << std::endl;
			else if (i >= 32 && i <= 126)
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;

			if (std::isnan(d) || std::isinf(d))
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << i << std::endl;

			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
			return;
		}
	}

	// Se nenh    uma conversão funcionou
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}


