/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:41:24 by bcastelo          #+#    #+#             */
/*   Updated: 2024/12/14 10:33:51 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        MutantStack( void );
        MutantStack( const MutantStack& );
        MutantStack& operator=( const MutantStack& );
        ~MutantStack( void );
        iterator begin( void );
        const_iterator begin( void ) const;
        iterator end( void );
        const_iterator end( void ) const;
};

#include "MutantStack.tpp"

#endif