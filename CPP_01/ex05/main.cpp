/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:33:41 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/23 16:34:58 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("ERROR");
	std::cout << std::endl;

	harl.complain("DEBUG");   // Chama o método Harl::debug()
	harl.complain("INFO");    // Chama o método Harl::info()
	harl.complain("WARNING"); // Chama o método Harl::warning()
	harl.complain("ERROR");   // Chama o método Harl::error()
	harl.complain("SILENCE"); // Teste de nível desconhecido

	return 0;
}
