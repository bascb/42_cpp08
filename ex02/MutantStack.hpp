/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:41:24 by bcastelo          #+#    #+#             */
/*   Updated: 2024/11/09 13:08:53 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
    public:
        MutantStack( void );
        MutantStack( typename C = std::deque<T> );
        ~MutantStack( void );
};

#include "MutantStack.tpp"

#endif