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

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <map>
#include <deque>
#include <vector>
#include <time.h>
#include <cfloat>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <sys/stat.h>
#include <sys/types.h>


class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		std::vector<int>	_vectorCont;
		std::deque<int>		_dequeCont;

	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe(void);
	
		void	sortCont();
		bool	vectorSort();
		void	init(int size);
		void	sortDeq();
		void	printRes(clock_t stime, clock_t ftime);
		void	printVector();
		void	printDeq();
		void	sortVector();


		template <typename T>
		T	tran_cont(T &container);
		template <typename T>
		void	arr_cont(T &container, T &temp);
		template <typename T>
		void	ret(T &container, T &temp, T &sequence);

	
};

#endif
