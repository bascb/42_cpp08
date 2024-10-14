/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:37:16 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/13 10:13:03 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span
{
    public:
        Span( unsigned int set_N );
        Span( const Span& );
        Span& operator=( const Span& );
        ~Span( void );
        void addNumber( int number );
        unsigned int getN( void ) const;
        unsigned int getSize( void ) const;
        int shortestSpan( void );
        class FullException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class InsufficientNumbersException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
    private:
        unsigned int N;
        bool is_sorted;
        std::vector<int> numbers;
};

#endif