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

#ifndef A_HPP
# define A_HPP

#include "Base.hpp"

class A : public Base
{
	public:
		A();
		A(A const &object);
		A &operator=(A const &rhs);
		~A();
};

#endif