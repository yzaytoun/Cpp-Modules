/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _size(DEF_SIZE), _elements(NULL)
{}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size), _elements(NULL)
{}

template<typename T>
Array<T>::~Array()
{
	if (_elements)
		delete[] _elements;
}

template<typename T>
Array<T>::Array(const Array<T>& arr)
{
	this = &arr;
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array<T>& arr)
{
	if (this != &arr)
	{
		if (this->_elements)
			delete[] _elements;
		//size?
		for(std::size_t i = 0, i < arr.size(), ++i)
			this[i] = arr[i];
	}
	return (*this);
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}
