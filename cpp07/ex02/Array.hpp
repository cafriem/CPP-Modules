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

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>
#include <iostream>
template <typename T>

class Array
{
	private:
		unsigned int	_c;
		T				*_data;

	public:
		Array<T>():_c(0)
		{
			std::cout << "Array Constructor Called" << std::endl;
			_data = new T[_c];
		}
		Array<T>(unsigned int c): _c(c)
		{
			std::cout << "Array Constructor Called" << std::endl;
			_data = new T[_c];
		}
		Array<T>(const Array<T> &a):_c(a.size())
		{
			std::cout << "Array Copy Constructor Called" << std::endl;
			_data = new T[_c];
			for(std::size_t i = 0; i < _c; i++)
			{
				_data[i] = a._data[i];
			}
		}
		Array<T> &operator=(const Array<T> &rhs)
		{
			std::cout << "Array Copy Assignment Operator = " << std::endl;
			if (this != &rhs)
			{
				if(_data != NULL)
					delete [] _data;
				_c = rhs._c;
				_data = new T[_c];
				for(unsigned int i = 1; i < _c; i++)
					_data[i] = rhs._data[i];
			}
			return (*this);
		}
		T &operator[](std::size_t i) 
		{
			if (_data == NULL ||  i >= _c)
				throw std::runtime_error("Out of Bounds");
			return (_data[i]);
		}
		T const &operator[](std::size_t i) const 
		{
			if (_data == NULL || i >= _c)
				throw std::runtime_error("Out of Bounds");
			return (_data[i]);
		}
		unsigned int size() const
		{
			return (_c);
		}   
		~Array<T>() 
		{
			std::cout << "Array Destructor Called" << std::endl;
			if(_data != NULL)
				delete[] _data;
		}
};

#endif