/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:23 by mkhan             #+#    #+#             */
/*   Updated: 2024/03/31 17:43:25 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	std::cout << "Span Constructor Called" << std::endl;
}

Span::Span(unsigned int c): _c(c)
{
	std::cout << "Span Constructor Called" << std::endl;
}

Span::Span(Span const &a)
{
	std::cout << "Span Copy Constructor Called" << std::endl;
	*this = a;
}

Span & Span::operator=(Span const &rhs)
{
	std::cout << "Span Copy Assignment Operator = " << std::endl;
	if (this != &rhs)
	{
		this->_c = rhs._c;
		this->_vectortor = rhs._vectortor;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span Destructor Called" << std::endl;
}

void	Span::addNumber(int num)
{
	if (this->_vectortor.size() == this->_c)
		throw Span::ContainerMaxException();
	if (num < 0)
		throw std::runtime_error("Negative Number");
	this->_vectortor.push_back(num);
}

void	Span::addMoreNum(unsigned int size)
{
	for (size_t i = 0; i < size; i++)
	{
		this->_vectortor.insert(this->_vectortor.begin(), rand() % 100);
	}
	
}

int	Span::longestSpan()
{
	int lngSpan;
	
	if (this->_vectortor.size() < 1)
		throw Span::ContainerEmptyException();
	std::sort(this->_vectortor.begin(), this->_vectortor.end());
	lngSpan = this->_vectortor[this->_vectortor.size() - 1] - this->_vectortor[0];
	return(lngSpan);
}

int	Span::shortestSpan()
{
	int minSpan;

	if (this->_vectortor.size() < 1)
		throw Span::ContainerEmptyException();
	std::sort(this->_vectortor.begin(), this->_vectortor.end());
	minSpan = this->_vectortor[1] - this->_vectortor[0];
	for (size_t i = 1; i < this->_vectortor.size() - 1; i++)
	{
		if (this->_vectortor[i + 1] - this->_vectortor[i] < minSpan)
			minSpan = this->_vectortor[i + 1] - this->_vectortor[i];
	}
	return (minSpan);
}

const char	*Span::ContainerMaxException::what() const throw()
{
	return("Container(Vector) Is Full");
}

const char	*Span::ContainerEmptyException::what() const throw()
{
	return("Container(Vector) Is Empty");
}