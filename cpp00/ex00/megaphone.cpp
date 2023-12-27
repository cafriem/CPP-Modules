/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:02:21 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/27 11:23:07 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int c = 1; c < argc; c++)
	{
		std::string str = std::string(argv[c]);
		for (unsigned long l = 0; l < str.size(); l++)
			std::cout << (char)std::toupper(str[l]);
	}
	std::cout << std::endl;
	return(0);
}
