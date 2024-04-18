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

PmergeMe::PmergeMe(char **argv)
{
	std::cout << "Before: ";
	for (size_t i = 0; argv[i]; i++)
	{
		this->_vector.push_back(atoi(argv[i]));
		this->_deque.push_back(atoi(argv[i]));
		std::cout << " " << atoi(argv[i]) << " ";
	}
	std::cout << std::endl;
	this->sortCont();
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

void PmergeMe::sortCont()
{
	if (vectorSort())
		std::cout << "This set is already sorted" << std::endl;
	else
	{
		clock_t	stime;
		clock_t	ftime;
		init(this->_vector.size());
		stime = clock();
		this->sortVector();
		ftime = clock();
		printRes(stime, ftime);
	}
}

void PmergeMe::init(int size)
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
	this->_vectorCont.push_back(1);
	this->_dequeCont.push_back(1);
	sortmerge.erase(sortmerge.begin());
	sortmerge.erase(sortmerge.begin());
	c = 1;
	int numbers = sortmerge[1] - sortmerge[0];
	int i = (sortmerge[1] - sortmerge[0]) + 1;
	int reached = (sortmerge[1] - sortmerge[0]) + 1;
	sortmerge.erase(sortmerge.begin());
	while (sortmerge.empty() == 0)
	{
		while (numbers--)
		{
			this->_vectorCont.push_back(i);
			this->_dequeCont.push_back(i--);
		}
		numbers = sortmerge[1] - sortmerge[0];
		i = (sortmerge[1] - sortmerge[0]) + reached;
		reached += numbers;
		sortmerge.erase(sortmerge.begin());
		if (sortmerge.size() == 1)
			break ;
	}
}

void PmergeMe::printRes(clock_t stime, clock_t ftime)
{
		float	vec_time, deq_time;
		vec_time = ((float)(ftime - stime)) / 1000000;
		stime = clock();
		this->sortDeq();
		ftime = clock();
		deq_time = ((float)(ftime - stime)) / 1000000;
		this->printVector();
		this->printDeq();
		std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : " 
		<< std::fixed << vec_time << " us" << std::endl;
		std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque  : " 
		<< std::fixed <<  deq_time << " us" << std::endl;
}

void PmergeMe::printVector()
{
	std::cout << "After : ";
	for(unsigned long i = 0; i < _vector.size(); i++)
	{
		std::cout << " " << _vector.at(i) << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeq()
{
	std::cout << "After : ";
	for(unsigned long i = 0; i < _deque.size(); i++)
	{
		std::cout << " " << _deque.at(i) << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortDeq()
{
	std::deque<int>	res;

	res = this->tran_cont(this->_deque);
	this->arr_cont(this->_deque, res);
	this->ret(this->_deque, res, this->_dequeCont);
}

template <typename T>
T PmergeMe::tran_cont(T &container)
{
	int		c = 0;
	int		c1 = container.size();
	int		sizeOri = container.size();
	T		temp;

	while (c1 != 0 && c1 != 1)
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
		c1 -= 2;
	}
	if ((sizeOri % 2 != 0))
	{
		temp.push_back(container[c]);
		container.erase(container.begin() + c);
	}
	return (temp);
}

template <typename T>
void PmergeMe::ret(T &container, T &temp, T &sequence)
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
void PmergeMe::arr_cont(T &container, T &temp)
{
	int	c = 0;
	int	end = container.size() - 1;

	while (end > c)
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

void PmergeMe::sortVector()
{
	std::vector<int>	temp;

	temp = this->tran_cont(this->_vector);
	this->arr_cont(this->_vector, temp);
	this->ret(this->_vector, temp, this->_vectorCont);
}

bool PmergeMe::vectorSort()
{
	std::vector<int>::iterator it;

	it = this->_vector.begin();
	while (it != this->_vector.end() - 1)
	{
		if (*it < *(it + 1))
			it++;
		else
			return (false);
	}
	return (true);
}
