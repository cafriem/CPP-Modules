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

#ifndef SPAN_HPP
# define SPAN_HPP

#include <ctime>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>

class Span
{
	private:
		unsigned int		_c;
		std::vector<int>	_vectortor;
		class	ContainerEmptyException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class	ContainerMaxException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	public:
		Span();
		Span(unsigned int c);
		Span(Span const &a);
		Span & operator=(Span const &rhs);
		~Span();

		void	addNumber(int num);
		void	addMoreNum(unsigned int size);
		int		longestSpan();
		int		shortestSpan();
};

#endif