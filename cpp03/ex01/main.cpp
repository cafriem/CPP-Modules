/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 01:05:14 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main ()
{
	ScavTrap player1 = ScavTrap("joe");
	std::cout << "----------------------------------->> dead test\n";
	for (size_t i = 0; i < 11; i++)
	{
		player1.takeDamage(10);
	}
		player1.attack("jeff");
	std::cout << "----------------------------------->> repaire test\n";
	player1.beRepaired(100);
	player1.beRepaired(1000);
	std::cout << "----------------------------------->> energy test\n";
	for (size_t i = 0; i < 13; i++)
	{
		player1.attack("jeff");
	}
}


