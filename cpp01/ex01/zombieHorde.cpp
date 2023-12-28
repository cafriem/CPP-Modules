/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:28:40 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/28 03:09:12 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N < 0)
		return(NULL);
	Zombie	*zom = new Zombie[N];
	for(int c = 0; c < N; c++)
	{
		zom[c].setname(name);
		zom[c].announce();
	}
	return(zom);
}
