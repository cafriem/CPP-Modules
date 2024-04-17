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
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		std::vector<int>	_vec_sequence;
		std::deque<int>		_deq_sequence;

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe(void);
	
		void	_sort_containers(void);
		bool	_already_sorted(void);
		void	_create_sequence(int size);
		void	printRes(clock_t stime, clock_t ftime);
		void	printVector();
		void	printDeq();
		void	_sort_vector();
		void	_sort_deque();


		template <typename T>
		T	_transfer(T &container);
		template <typename T>
		void	_rearrange(T &container, T &temp);
		template <typename T>
		void	_return(T &container, T &temp, T &sequence);

		PmergeMe(char **argv);
	
};

#endif
