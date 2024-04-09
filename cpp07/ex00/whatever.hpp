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

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
	T max(T a, T b)
	{
		return (a > b ? a : b);
	}

template <typename T>
	T min(T a, T b)
	{
		return (a < b ? a : b);
	}

template <typename T>
	void swap(T &a, T &b)
	{
		T temp;
		temp = a;
		a = b;
		b = temp;
	}

#endif