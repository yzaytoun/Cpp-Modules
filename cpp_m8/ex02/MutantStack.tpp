/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MutantStack.hpp"

/* Mutant Stack Iterator */
template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator() : _ptr(NULL) {}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(const _const_iterator& it) : _ptr(it)
{}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::~iterator() {}

template<typename T, typename Container>
MutantStack<T, Container>::iterator::iterator(const iterator& it) : _ptr(it._ptr) {}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator::_const_iterator	MutantStack<T, Container>::iterator::base() const
{
	return (_ptr);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator&   MutantStack<T, Container>::iterator::operator=(const iterator& it)
{
	if (this != &it)
	{
		this->_ptr = it._ptr;
	}
	return (*this);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator&   MutantStack<T, Container>::iterator::operator++(void)
{
	this->_ptr++;
	return (*this);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator   MutantStack<T, Container>::iterator::operator++(T)
{
	MutantStack<T, Container>::iterator	_tmp = *this;
	this->_ptr++;
	return (_tmp);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator&   MutantStack<T, Container>::iterator::operator--(void)
{
	this->_ptr--;
	return (*this);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator   MutantStack<T, Container>::iterator::operator--(T)
{
	MutantStack<T, Container>::iterator	_tmp = *this;
	this->_ptr--;
	return (_tmp);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator::reference	MutantStack<T, Container>::iterator::operator*(void) const
{
	return (*this->_ptr);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator::pointer	MutantStack<T, Container>::iterator::operator->(void) const
{
	return (this->_ptr);
}

template<typename T, typename Container>
bool		MutantStack<T, Container>::iterator::operator==(const iterator& it)
{
	return (this->base() == it.base());
}

template<typename T, typename Container>
bool		MutantStack<T, Container>::iterator::operator!=(const iterator& it)
{
	return (this->base() != it.base());
}

template<typename Itr>
void	__do_advance(Itr& it,typename std::iterator_traits<Itr>::difference_type n, std::bidirectional_iterator_tag)
{
	while (n > 0)
	{
		n--;
		++it;
	}
	while (n < 0)
	{
		n++;
		--it;
	}
}

template<typename Itr, typename Distance>
void	advance(Itr& it, Distance n)
{
	__do_advance(it,
		typename std::iterator_traits<Itr>::difference_type(std::__convert_to_integral(n)),
		typename std::iterator_traits<Itr>::iterator_category());
}

/* Mutant Stack */

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() {}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& stack)
{
	this = stack;
}

template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& stack)
{
    if (*this != &stack)
	{
        this->c = stack.c;
	}
    return (*this);
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator   MutantStack<T, Container>::begin() const
{
	return (MutantStack<T, Container>::iterator(this->c.begin()));
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator   MutantStack<T, Container>::end() const
{	
	return (MutantStack<T, Container>::iterator(this->c.end()));
}
