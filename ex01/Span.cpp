/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:43:23 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/20 13:01:36 by bcastelo         ###   ########.fr       */
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

void Span::addNumbers( std::vector<int> numbers_vector )
{
	if (numbers.size() + numbers_vector.size() > N)
		throw Span::FullException();
	numbers.insert(numbers.end(), numbers_vector.begin(), numbers_vector.end());
}

unsigned int Span::getN( void ) const
{
	return (N);
}

unsigned int Span::getSize( void ) const
{
	return (numbers.size());
}

bool Span::getIsSorted( void ) const
{
	return (is_sorted);
}

void Span::printValues( std::ostream &os ) const
{
	std::vector<int>::const_iterator it;
	int printed = 0;

	if (numbers.size() == 0)
		return ;
	os << "Vector values:" << std::endl;
	for (it = numbers.begin(); it != numbers.end(); ++it)
	{
		os << *it << " ";
		if (++printed % 40 == 0)
			os << std::endl;
	}
	os << std::endl;
}

int Span::shortestSpan( void )
{
	int shortest = INT_MAX;
	std::vector<int>::iterator it;

	if (numbers.size() < 2)
		throw Span::InsufficientNumbersException();
	this->sort();
	for (it = numbers.begin() + 1; it != numbers.end(); ++it)
		if (*it - *(it - 1) < shortest)
			shortest = *it - *(it - 1);
	return (shortest);
}

int Span::longestSpan( void )
{
	if (numbers.size() < 2)
		throw Span::InsufficientNumbersException();
	this->sort();
	return (*(numbers.end() - 1) - *(numbers.begin()));
}

void Span::sort( void )
{
	if (is_sorted == false)
	{
		std::sort(numbers.begin(), numbers.end());
		is_sorted = true;
	}
}

const char *Span::FullException::what(void) const throw()
{
	return ("Integers container full!");
}

const char *Span::InsufficientNumbersException::what(void) const throw()
{
	return ("Insufficient numbers!");
}

std::ostream &operator<<(std::ostream &os, const Span &item)
{	
	os << "*** Printing Span object content ***" << std::endl;
	os << "N: " << item.getN() << " Size: " << item.getSize() << " std::sort function was called? ";
	os << (item.getIsSorted() ? "yes" : "no");
	os << std::endl;
	item.printValues(os);
	os << "************************************" << std::endl;
	return (os);
}