/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:00:13 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/30 12:14:15 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void ft_check_args(int ac)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace <filename> <string_to_find> <string_to_replace>" << std::endl;
		exit(1);
	}
}

void ft_check_file(std::ifstream &infile)
{
	if (!infile.is_open())
	{
		std::cerr << "Error: Could not open the input file!" << std::endl;
		exit(1);
	}
}

int main(int ac, char **av)
{
	ft_check_args(ac);

	std::ifstream infile(av[1]);
	ft_check_file(infile);

	std::string filename = av[1];
	std::string sin = av[2];
	std::string sout = av[3];

	if (sin.empty())
	{
		std::cerr << "The string to be replaced must not be empty!" << std::endl;
		return (1);
	}

	// Cria o arquivo de saída com o sufixo ".replace"
	std::ofstream repfile((filename + ".replace").c_str());
	if (!repfile.is_open())
	{
		std::cerr << "Error: Could not create the output file!" << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(infile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(sin, pos)) != std::string::npos)
		{
			line.erase(pos, sin.length());
			line.insert(pos, sout);
			pos += sout.length(); // Move o índice para evitar substituições infinitas
		}
		repfile << line << std::endl; // Escreve a linha modificada no arquivo de saída
	}

	infile.close();
	repfile.close();
	return 0;
}

