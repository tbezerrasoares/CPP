/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:59:21 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/22 11:52:42 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string brain = "HI THIS IS BRAIN";

	std::string* stringPTR = &brain;	// Ponteiro
	std::string& stringREF = brain;		// Referência

	std::cout << "Address of brain        : " << &brain << std::endl;
	std::cout << "Address held by PTR     : " << stringPTR << std::endl;
	std::cout << "Address held by REF     : " << &stringREF << std::endl;

	std::cout << "Value of brain          : " << brain << std::endl;
	std::cout << "Value pointed by PTR    : " << *stringPTR << std::endl;
	std::cout << "Value referenced by REF : " << stringREF << std::endl;

    return 0;
}
