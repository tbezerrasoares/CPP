/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:35:35 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/23 13:59:34 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	ft_chech_args(int ac)
{
	if (ac != 4){
		std::cerr << "The arguments must be three" << std::endl;
		exit(1);
	}
}

void	ft_chech_file(std::ifstream &inf)
{
	if (inf.fail()){
		std::cerr << "The file doesn't exist or can't be readed :c" << std::endl;
		inf.close();
		exit(1);
	}
}
