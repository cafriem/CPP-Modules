/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:01:58 by cafriem           #+#    #+#             */
/*   Updated: 2024/04/17 03:40:47 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe Constructor Called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &object)
{
	std::cout << "PmergeMe Copy Constructor Called" << std::endl;
	*this = object;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	std::cout << "PmergeMe Copy Assignment == Operator" << std::endl;
	if (this != &rhs)
	{}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe Destructor called" << std::endl;
}

void PmergeMe::printVector()
{
	std::cout << "After : ";
	for(unsigned long i = 0; i < _vec.size(); i++)
	{
		std::cout << " " << _vec.at(i) << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeq()
{
	std::cout << "After : ";
	for(unsigned long i = 0; i < _deq.size(); i++)
	{
		std::cout << " " << _deq.at(i) << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::_create_sequence(int size)
{
	std::vector<int>	sortmerge;
	int					c = 1;

	sortmerge.push_back(0);
	sortmerge.push_back(1);
	while (sortmerge[c] - (sortmerge[c - 1]) < size)
	{
		sortmerge.push_back(sortmerge[c] + (2 * sortmerge[c - 1]));
		c++;
	}
	c = 1;
	this->_vec_sequence.push_back(1);
	this->_deq_sequence.push_back(1);
	sortmerge.erase(sortmerge.begin());
	sortmerge.erase(sortmerge.begin());
	int numbers = sortmerge[c] - sortmerge[c - 1];
	int i = numbers + 1;
	int reached = i;
	sortmerge.erase(sortmerge.begin());
	while (!sortmerge.empty())
	{
		while (numbers--)
		{
			this->_vec_sequence.push_back(i);
			this->_deq_sequence.push_back(i--);
		}
		numbers = sortmerge[c] - sortmerge[c - 1];
		i = numbers + reached;
		reached = i;
		sortmerge.erase(sortmerge.begin());
		if (sortmerge.size() == 1)
			break ;
	}
}

template <typename T>
void PmergeMe::_return(T &container, T &temp, T &sequence)
{
	int	c = 0;

	while(sequence.empty() == 0)
	{
		if (temp[*sequence.begin() - 1] < container[c] && container[c] != 0)
		{
			container.insert(container.begin() + c, temp[*sequence.begin() - 1]);
			sequence.erase(sequence.begin());
			c = 0;
			continue ;
		}
		else if (*sequence.begin() > (int)temp.size())
		{
			sequence.erase(sequence.begin());
			continue ;
		}
		else if (container.begin() + c + 1 == container.end())
		{
			container.insert(container.begin() + c + 1, temp[*sequence.begin() - 1]);
			sequence.erase(sequence.begin());
			c = 0;
			continue ;
		}
		c++;
	}
}

template <typename T>
void PmergeMe::_rearrange(T &container, T &temp)
{
	int	c = 0;
	int	end = container.size() - 1;
	
	while (c < end)
	{
		if (container[end] < container[end - 1])
		{
			std::swap(container[end], container[end - 1]);
			std::swap(temp[end], temp[end - 1]);
			c = 0;
			end = container.size() - 1;
			continue ;
		}
		else if (container[c] > container[c + 1])
		{
			std::swap(container[c], container[c + 1]);
			std::swap(temp[c], temp[c + 1]);
			c = 0;
			end = container.size() - 1;
			continue ;
		}
		c++;
		end--;
	}
}

template <typename T>
T PmergeMe::_transfer(T &container)
{
	int		c = 0;
	int		size = container.size();
	int		true_size = container.size();
	T		temp;

	while (size != 0 && size != 1)
	{
		if (container[c] <= container[c + 1])
		{
			temp.push_back(container[c + 1]);
			container.erase(container.begin() + (c + 1));
		}
		else 
		{
			temp.push_back(container[c]);
			container.erase(container.begin() + c);
		}
		c++;
		size -= 2;
	}
	if ((true_size % 2 != 0))
	{
		temp.push_back(container[c]);
		container.erase(container.begin() + c);
	}
	return (temp);
}

void PmergeMe::_sort_deque()
{
	std::deque<int>	temp;
	
	temp = this->_transfer(this->_deq);
	this->_rearrange(this->_deq, temp);
	this->_return(this->_deq, temp, this->_deq_sequence);
}

void PmergeMe::_sort_vector()
{
	std::vector<int>	temp;
	
	temp = this->_transfer(this->_vec);
	this->_rearrange(this->_vec, temp);
	this->_return(this->_vec, temp, this->_vec_sequence);
}

bool PmergeMe::_already_sorted()
{
	std::vector<int>::iterator it;

	it = this->_vec.begin();
	while (it != this->_vec.end() - 1)
	{
		if (*it < *(it + 1))
			it++;
		else
			return (false);
	}
	return (true);
}

void PmergeMe::printRes(clock_t stime, clock_t ftime)
{
		double	vec_time, deq_time;
		vec_time = ((double)(ftime - stime)) / 1000000;
		stime = clock();
		this->_sort_deque();
		ftime = clock();
		deq_time = ((double)(ftime - stime)) / 1000000;
		this->printVector();
		this->printDeq();
		std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vector : " 
		<< std::fixed << vec_time << " us" << std::endl;
		std::cout << "Time to process a range of " << this->_deq.size() << " elements with std::deque  : " 
		<< std::fixed <<  deq_time << " us" << std::endl;
}

void PmergeMe::_sort_containers()
{
	if (_already_sorted())
		std::cout << "This set is already sorted" << std::endl;
	else
	{
		clock_t	stime;
		clock_t	ftime;
		_create_sequence(this->_vec.size());
		stime = clock();
		this->_sort_vector();
		ftime = clock();
		printRes(stime, ftime);
	}
}

PmergeMe::PmergeMe(char **argv)
{
	std::cout << "Before: ";
	for (size_t i = 0; argv[i]; i++)
	{
		this->_vec.push_back(atoi(argv[i]));
		this->_deq.push_back(atoi(argv[i]));
		std::cout << " " << atoi(argv[i]) << " ";
	}
	std::cout << std::endl;	this->_sort_containers();
}
