/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <exception>
#include <limits>
#include <deque>
#include <iterator>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& stack);
		MutantStack&	operator=(const MutantStack& stack);

		class iterator;
		iterator	begin() const;
		iterator	end() const;
};

template<typename T, typename Container>
class MutantStack<T, Container>::iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
	public:
		/* Traits */
		typedef Container										container_type;
		typedef typename Container::iterator				    _iterator;
		typedef typename Container::const_iterator				_const_iterator;
		typedef typename Container::value_type					value_type;
		typedef typename Container::const_reference				reference;
		typedef typename Container::const_pointer				pointer;
		typedef typename std::bidirectional_iterator_tag		iterator_category;
		
	private:
		_const_iterator	_ptr;
	public:
		iterator();
		iterator(const _const_iterator& c);
		~iterator();
		iterator(const iterator& it);

		/* Methods */
		_const_iterator		base() const;
		reference			operator*(void) const;
		pointer				operator->(void) const;
		
		/* Operators */
		iterator&	operator=(const iterator& it);
		iterator&	operator++(void);
		iterator	operator++(T);
		iterator&	operator--(void);
		iterator	operator--(T);
		bool		operator==(const iterator& it);
		bool		operator!=(const iterator& it);
};

template<typename Itr, typename Distance>
void	advance(Itr& it, Distance n);