/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/03 18:28:49 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <string>

std::string	replace(std::string Filename, std::string line, std::string s1, std::string s2)
{
	unsigned int	c = line.find(s1);
	while (c != std::string::npos)
	{
		std::string	begin = line.substr(0, c);
		std::string	end = line.substr(c + s1.length(), line.length());
		line = begin + s2 + end;
		begin.clear();
		end.clear();
	}
	return(line);
}

void	openfile(char **argv)
{
	std::string		Filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::string		line;
	std::string		rep_line;
	std::ifstream	infile(Filename);
	struct stat		status_file;
	stat(Filename.c_str(), &status_file);
	if(S_ISDIR(status_file.st_mode) == 0 && infile.is_open())
	{
		std::ofstream outfile(Filename + ".replace");
		while(std::getline(infile, line))
		{
			if (s1.compare(s2) == 0)
			{
				rep_line = replace(Filename, line, s1, s2);
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 4 && argv[2][0] != '\0')
		openfile(argv);
	else
		std::cout << "Arguements are wrong" << std::endl;
}
