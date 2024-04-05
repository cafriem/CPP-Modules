/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Start.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:23 by mkhan             #+#    #+#             */
/*   Updated: 2024/03/31 17:43:25 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Start.hpp"

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A Class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B Class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C Class" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A Class" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B Class" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C Class" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "The Class is not A, B or C" << std::endl;
			}
		}
	}
}

Base	*generate(void)
{
	srand(time(NULL));
	int numr = rand() % 3;
	if (numr == 0)
		return new A;
	else if (numr == 1)
		return new B;
	else
		return new C;
}
