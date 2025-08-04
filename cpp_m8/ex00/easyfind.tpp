/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <type_traits>

template<typename T>
bool	easyfind(T const& container, int const& x)
{
	bool	found = false;
	typename T::const_iterator	itr = std::find(container.begin(), container.end(), x);

	if (itr != container.end())
		found = true;
	return (found);
}

template<typename K, typename T>
bool	easyfind(std::map<K,T> const& container, int const& x)
{
	typename std::map<K,T>::const_iterator	itr = container.begin();
	bool	found = false;

	while (itr != container.end())
	{
		if (itr->second == x)
		{
			found = true;
			break;
		}
		++itr;
	}
	return (found);
}
