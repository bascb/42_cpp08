/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:49:25 by bcastelo          #+#    #+#             */
/*   Updated: 2024/11/23 13:18:42 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename C>
MutantStack<T, C>::MutantStack( void ) : std::stack<T, C>()
{
    std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T,typename C>
MutantStack<T, C>::MutantStack( C ) : std::stack<T, C>()
{
    std::cout << "MutantStack default constructor with container called" << std::endl;
}

template <typename T, typename C>
MutantStack<T, C>::MutantStack( const MutantStack& src ) : std::stack<T, C>(src)
{
    std::cout << "MutantStack default copy constructor called" << std::endl;
}

template <typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=( const MutantStack& src )
{
    std::cout << "MutantStack Copy assignment operator called" << std::endl;
    if (this != &src) {
        std::stack<T, C>::operator=(src);
    }
    return *this;
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack( void )
{
    std::cout << "MutantStack default destructor called" << std::endl;
}