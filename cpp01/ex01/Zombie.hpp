/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:05:51 by cafriem           #+#    #+#             */
/*   Updated: 2023/12/28 03:08:23 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	setname(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif