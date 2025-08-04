/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:52:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.tpp"


int main()
{
	MutantStack<int> mstack;
	MutantStack<int, std::vector<int> > mvec_stack;

	std::cout << "---------- Normal Stack -------------" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top -> " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size -> " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "---------- Vector Stack -------------" << std::endl;
	mvec_stack.push(3);
	mvec_stack.push(5);
	mvec_stack.push(737);
	MutantStack<int, std::vector<int> >::iterator it_1 = mvec_stack.begin();
	MutantStack<int, std::vector<int> >::iterator ite_1 = mvec_stack.end();
	while (it_1 != ite_1)
	{
		std::cout << *it_1 << std::endl;
		++it_1;
	}
	MutantStack<int, std::vector<int> >::iterator it_2 = mvec_stack.end();
	std::cout << "Before -> " << *it_2 << std::endl;
	::advance(it_2, -2);
	std::cout << "after -> " << *it_2 << std::endl;
	return 0;
}
