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

#include "RPN.hpp"

int main(int ac, char *argv[])
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return (0);
	}
	try
	{
		RPN rev;
		rev.exec(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
