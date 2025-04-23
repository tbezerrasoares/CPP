/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbezerra <tbezerra@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:00:13 by tbezerra          #+#    #+#             */
/*   Updated: 2025/04/23 14:31:06 by tbezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char **av)
{
	ft_chech_args(ac);

	std::ifstream	infile(av[1]);
	std::ofstream	repfile;
	ft_chech_file(infile);

	size_t		pos;
	std::string tmp = av[1];
	std::string sin = av[2];
	std::string sout = av[3];

	if (sin[0] == '\0')
	{
		std::cerr << "The string to be replaced must not be empty!" << std::endl;
		return (1);
	}
	tmp.append(".replace");
	repfile.open(tmp.c_str());

	while (std::getline(infile, tmp))
	{
		pos = tmp.find(sin, 0);
		if (pos == tmp.npos)
		{
			std::cerr << "The string to be replaced was not found!" << std::endl;
			break;
		}
		while (pos != tmp.npos)
		{
			tmp.erase(pos, sin.length());
			tmp.insert(pos, sout);
			pos = tmp.find(sin, 0);
		}
		repfile << tmp << std::endl;
	}
	infile.close();
	repfile.close();
}

