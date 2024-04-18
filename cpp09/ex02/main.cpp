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

#include "PmergeMe.hpp"

bool	check_digit(char **str)
{
	int	c = 1;
	int	c1;

	while(str[c])
	{
		c1 = 0;
		while(str[c][c1])
		{
			if (isdigit(str[c][c1]) == 0)
				return (false);
			c1++;
		}
		c++;
	}
	return(true);
}

int	main(int argc, char **argv)
{
	if (argc > 3 && argc < 3002)
	{
		if (check_digit(argv) == true)
		{
			PmergeMe sort(argv);
			return (0);
		}
		else 
			std::cout << "Error: Non digit character found." << std::endl;
	}
	else
		std::cout << "Error: Wrong Amount of Arguments." << std::endl;
	return(1);
}
