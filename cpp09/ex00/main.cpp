/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:39:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/11 17:39:03 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char ** argv)
{
	if(argc != 2)
	{
		std::cout << "Error: could not open file." <<std::endl;
		return (1);
	}
	BitcoinExchange read;
	try
	{
		read.readDataFile();
		std::string name = read.getFilename(argv[1]);
		std::string data = read.parseFilename(name);
		read.calculateValue(data);
	}
	catch(BitcoinExchange::FileIssues &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	return (0);
}
