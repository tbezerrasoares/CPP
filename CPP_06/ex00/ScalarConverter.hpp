/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:41:50 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/30 13:42:53 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
	ScalarConverter();                               // Construtor privado
	ScalarConverter(const ScalarConverter&);         // Construtor de cópia
	ScalarConverter& operator=(const ScalarConverter&); // Operador de atribuição
	~ScalarConverter();                              // Destrutor

public:
	static void convert(const std::string& literal);
};

#endif
