/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:39:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/04/09 14:02:08 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	Array<int>	test1(5);

	test1[0] = 1;
	test1[1] = 2;
	test1[2] = 3;
	test1[3] = 4;
	test1[4] = 5;

	for (size_t i = 0; i < 4; i++)
		std::cout << test1[i] << std::endl;

	Array<long>	test2(5);

	test2[0] = 1;
	test2[1] = 2;
	test2[2] = 3;
	test2[3] = 4;
	test2[4] = 5;

	for (size_t i = 0; i < 4; i++)
		std::cout << test2[i] << std::endl;
}
