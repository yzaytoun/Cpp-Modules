/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

# define DEF_SIZE	1

template<typename T>
void	print(const T& x)
{
	std::cout << x << " ";
}

template<class T>
class Array
{
private:
	unsigned int	_size;
	T*				_elements;
public:
	Array();
	Array(unsigned int size);
	~Array();
	Array(const Array& arr);
	Array&	operator=(const Array& arr);
	T		operator[](const int& idx){
		
	}

	unsigned int	size() const;
};
