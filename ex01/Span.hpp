/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:37:16 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/12 12:54:48 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

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
        class FullException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
    private:
        unsigned int N;
        std::vector<int> numbers;
};

#endif