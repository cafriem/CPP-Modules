/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 01:16:38 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main ()
{
	FragTrap player1 = FragTrap("joe");
	std::cout << "----------------------------------->> dead test\n";
	for (size_t i = 0; i < 8; i++)
	{
		player1.takeDamage(10);
	}
		player1.attack("jeff");
	std::cout << "----------------------------------->> repaire test\n";
	player1.beRepaired(100);
	player1.beRepaired(1000);
	std::cout << "----------------------------------->> energy test\n";
	for (size_t i = 0; i < 20; i++)
	{
		player1.attack("jeff");
		player1.highFivesGuys();
	}
}


