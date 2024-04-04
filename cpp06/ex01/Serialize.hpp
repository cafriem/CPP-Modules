/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 11:05:51 by cafriem           #+#    #+#             */
/*   Updated: 2024/01/08 03:46:40 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include <iostream>
#include <cstdlib>
#include <string>

struct Data
{
	std::string	data;
	int			c;
};

class Serialize
{
	private:
		Serialize();
		Serialize(Serialize const &object);
		Serialize &operator=(Serialize const &rhs);

	public:
		~Serialize();
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif