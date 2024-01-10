/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/10 01:12:23 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &a)
{
	std::cout << "FragTrap Copy Constructor Called" << std::endl;
	*this = a;
}

FragTrap & FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return(*this);
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor Called" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap is now in Gate keeper mode." << std::endl;
}
