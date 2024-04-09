/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:39:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/04/08 08:31:11 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << "String Test" << std::endl;
	std::string test1[] = {"1st", "2nd", "3rd", "4th"};
	iter(test1, 4, print<std::string>);

	std::cout << "\n\n" << "int Test" << std::endl;
	int test2[] = {1, 2, 3, 4};
	iter(test2, 4, print<int>);
}
