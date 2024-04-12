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

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <iterator>
#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>()
		{
			std::cout << "MutantStack Constructor Called" << std::endl;
		}

		MutantStack(const MutantStack &a) 
		{
			std::cout << "MutantStack Copy Constructor Called" << std::endl;
			*this = a;
		}

		MutantStack& operator=(const MutantStack& rhs)
		{
			std::cout << "MutantStack Copy Assignment Operator = " << std::endl;
			if (this != &rhs)
			{
				std::stack<T>::operator=(rhs);
			}
			return (*this);
		}

		~MutantStack()
		{
			std::cout << "MutantStack Destructor Called" << std::endl;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() 
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}
};
#endif