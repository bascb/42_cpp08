/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:43:23 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/12 12:55:22 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int set_N ) : N(set_N)
{
    std::cout << "Span default constructor called for size N: " << N << std::endl;
}

Span::Span( const Span& src) : N(src.N)
{
    std::cout << "Span default copy constructor called for size N: " << N << std::endl;
}

Span& Span::operator=( const Span& src )
{
	std::cout << "Span Copy assignment operator called" << std::endl;
	if (this != &src)
	{
        this->N = src.N;
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
}

unsigned int Span::getN( void ) const
{
	return (N);
}

unsigned int Span::getSize( void ) const
{
	return (numbers.size());
}

const char *Span::FullException::what(void) const throw()
{
	return ("Integers container full!");
}