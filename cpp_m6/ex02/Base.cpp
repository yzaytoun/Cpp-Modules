/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base*   generate(void)
{
	Base*   base = NULL;

	switch (rand() % 3 + 1)
	{
	case 1:
		base = new A();
		break;
	case 2:
		base = new B();
		break;
	case 3:
		base = new C();
		break;
	
	default:
		break;
	}
	return (base);
}

void    identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object type: C" << std::endl;
	
}

void    identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Object type: A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Object type: B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Object type: C" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
}
