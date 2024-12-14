/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:49:25 by bcastelo          #+#    #+#             */
/*   Updated: 2024/12/14 10:29:11 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>()
{
    std::cout << "MutantStack default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& src ) : std::stack<T>(src)
{
    std::cout << "MutantStack default copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack& src )
{
    std::cout << "MutantStack Copy assignment operator called" << std::endl;
    if (this != &src) {
        std::stack<T>::operator=(src);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack( void )
{
    std::cout << "MutantStack default destructor called" << std::endl;
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin( void )
{
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin( void ) const
{
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end( void )
{
    return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end( void ) const
{
    return this->c.end();
}