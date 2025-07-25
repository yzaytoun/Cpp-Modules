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

#pragma once
#include "Array.hpp"

template<typename T>
Array<T>::Array() : _size(1)
{
	_elements = new T[_size];
}

template<typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
	_elements = new T[_size];
}

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
Array<T>&	Array<T>::operator=(const Array& arr)
{
	if (this != &arr)
	{
		if (this->_elements)
			delete[] _elements;
		_elements = new T[arr.size()];
		_size = arr.size();
		for(std::size_t i = 0; i < arr.size(); ++i)
			(*this)[i] = arr[i];
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator[](unsigned int idx)
{
	if (idx >= _size)
		throw std::out_of_range("incorrect index!!");
	return (_elements[idx]);
}

template<typename T>
T	Array<T>::operator[](unsigned int idx) const
{
	if (idx >= _size)
		throw std::out_of_range("incorrect index!!");
	return (_elements[idx]);
}

template<typename T>
void*	Array<T>::operator new[](size_t sz)
{
	if (!sz)
		++sz;
	void*	ptr = ::operator new(sz);
	if (!ptr)
		throw std::bad_alloc();
	return (ptr);
}

template<typename T>
void	Array<T>::operator delete[](void* ptr)
{
	if (ptr)
		::operator delete[] (ptr);
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template<typename T>
void	Array<T>::iter(void (*func)(const T&))
{
	for(size_t i = 0; i < _size; i++)
		func(_elements[i]);
}

template<typename T>
void	print(const T& x)
{
	std::cout << x << " ";
}
