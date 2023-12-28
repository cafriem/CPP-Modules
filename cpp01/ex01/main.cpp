/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:02:21 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/28 03:14:00 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "0 zombie test" << std::endl;
	Zombie *test1 = zombieHorde(0, "John");
	delete[] test1;
	std::cout << "-5 zombie test" << std::endl;
	Zombie *test2 = zombieHorde(-5, "John");
	delete[] test2;
	std::cout << "5 zombie test" << std::endl;
	Zombie *test3 = zombieHorde(5, "John");
	delete[] test3;
}
