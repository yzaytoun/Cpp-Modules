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
#include <exception>

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

	Array<T>&		operator=(const Array& arr);
	T&				operator[](unsigned int idx);
	T				operator[](unsigned int idx) const;

	void*			operator new[](size_t sz);
	void			operator delete[](void* ptr);
	unsigned int	size() const;
	void			iter(void (*func)(const T&));
};
