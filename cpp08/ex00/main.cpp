/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:39:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/04/12 01:55:54 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> test1;
	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);
	test1.push_back(4);
	test1.push_back(5);

	int	testnum = 3;
	int	testnum2 = 25;
	try
	{
		std::cout << easyfind(test1, testnum) << std::endl;
		std::cout << easyfind(test1, testnum2) << std::endl;
	}
	catch (std::exception &a)
	{
		std::cerr << a.what() << std::endl;
	}
	return 0;
}
