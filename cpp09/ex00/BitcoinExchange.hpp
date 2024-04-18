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

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
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

class BitcoinExchange
{
	private:
		std::string _filename;
		std::map<std::string, float> _values;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(BitcoinExchange const &obj);
		BitcoinExchange& operator=(BitcoinExchange const &rhs);
		~BitcoinExchange();

		std::string	fileParse(std::string const filename);
		std::string getFilename(char *filename);
		std::string	LowerBound(std::string &date);
		void		openfile();
		bool		checkLine(std::string str);
		bool		checkDate(std::string str);
		bool		dateFormat(std::string year, std::string month, std::string date);
		bool		checkValue(std::string str);
		void		calculate(std::string &rate);

	class FileIssues: public std::exception
	{
		private:
			std::string errorMessage;
		public:
			FileIssues(std::string error);
			const char *what() const throw() ;
			virtual ~FileIssues() throw();
	};
};

#endif
