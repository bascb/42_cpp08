/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:37:16 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/05 23:02:36 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
    public:
        Span( unsigned int set_N );
        Span( const Span& );
        Span& operator=( const Span& );
        ~Span( void );
    private:
        unsigned int N;
};

#endif