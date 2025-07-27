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

template<typename T>
bool	easyfind(T const& container, int const& x)
{
	typename T::const_iterator	itr;
	bool	found = false;
	
	if (!dynamic_cast<std::map<T,T> >(container))
	{
		itr = std::find(container.begin(), container.end(), x);
		if (itr != container.end())
			found = true;
	}
	return (found);
}
