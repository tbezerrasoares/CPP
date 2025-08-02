/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:44:21 by tbezerra          #+#    #+#             */
/*   Updated: 2025/07/30 13:44:45 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);
	return 0;
}
