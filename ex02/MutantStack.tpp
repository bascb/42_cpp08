/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:49:25 by bcastelo          #+#    #+#             */
/*   Updated: 2024/11/09 13:08:43 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, C = std::deque<T> >
MutantStack<T, C = std::deque<T> >::MutantStack( void )
{
    std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T,typename C = std::deque<T>  >
MutantStack<T, C = std::deque<T> >::MutantStack( typename C = std::deque<T> )
{
    std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T, C = std::deque<T> >
MutantStack<T, C = std::deque<T>>::~MutantStack( void )
{
    std::cout << "MutantStack default destructor called" << std::endl;
}