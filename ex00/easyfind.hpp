/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:47:57 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/05 18:29:17 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator easyfind(T &container, int to_find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), to_find);
    if (it != container.end())
    {
        std::cout << "Value found in container: " << std::endl;
    }
    else
		throw std::runtime_error("Error: Element not found");
    return it;
}

#endif