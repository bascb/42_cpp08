/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:43:23 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/13 10:46:27 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int set_N ) : N(set_N) , is_sorted(false)
{
    std::cout << "Span default constructor called for size N: " << N << std::endl;
}

Span::Span( const Span& src) : N(src.N) , is_sorted(src.is_sorted)
{
    std::cout << "Span default copy constructor called for size N: " << N << std::endl;
	numbers = src.numbers;
}

Span& Span::operator=( const Span& src )
{
	std::cout << "Span Copy assignment operator called" << std::endl;
	if (this != &src)
	{
        this->N = src.N;
		this->is_sorted = src.is_sorted;
		this->numbers = src.numbers;
	}
	return (*this);
}

Span::~Span( void )
{
	std::cout << "Span Destructor called for N: " << N << std::endl;
}

void Span::addNumber( int number )
{
	if (numbers.size() == N)
		throw Span::FullException();
	numbers.push_back(number);
	is_sorted = false;
}

unsigned int Span::getN( void ) const
{
	return (N);
}

unsigned int Span::getSize( void ) const
{
	return (numbers.size());
}

int Span::shortestSpan( void )
{
	int shortest = INT_MAX;
	std::vector<int>::iterator it;

	if (numbers.size() < 2)
		throw Span::InsufficientNumbersException();
	if (is_sorted == false)
	{
		std::sort(numbers.begin(), numbers.end());
		is_sorted = true;
	}
	for (it = numbers.begin() + 1; it != numbers.end(); ++it)
		if (*it - *(it - 1) < shortest)
			shortest = *it - *(it - 1);
	return (shortest);
}

const char *Span::FullException::what(void) const throw()
{
	return ("Integers container full!");
}

const char *Span::InsufficientNumbersException::what(void) const throw()
{
	return ("Insufficient numbers!");
}