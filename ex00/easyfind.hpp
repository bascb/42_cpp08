/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:47:57 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/05 22:06:30 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
int easyfind(T &container, int to_find)
{
	typename T::iterator iterator = std::find(container.begin(), container.end(), to_find);
	if (iterator == container.end())
    	return (-1);
    return (std::distance(container.begin(), iterator));
}

#endif