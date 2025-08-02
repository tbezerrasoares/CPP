/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:12:16 by tbezerra          #+#    #+#             */
/*   Updated: 2025/08/02 15:16:18 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Generate.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate() {
	std::srand(std::time(0));
	int r = std::rand() % 3;

	switch (r) {
		case 0: return new A;
		case 1: return new B;
		default: return new C;
	}
}
