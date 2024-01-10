/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/09 14:17:42 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap player1 = ClapTrap("joe");
	player1.attack("jeff");
	player1.takeDamage(3);
	player1.takeDamage(3);
	player1.attack("jeff");
	player1.attack("jeff");
	player1.attack("jeff");
	player1.attack("jeff");
	player1.attack("jeff");
	player1.attack("jeff");
	player1.attack("jeff");
	player1.attack("jeff");
	player1.attack("jeff");
	player1.attack("jeff");
	player1.beRepaired(10);
	player1.beRepaired(10);
	player1.takeDamage(10);
	player1.beRepaired(10);
	player1.takeDamage(10);

}


