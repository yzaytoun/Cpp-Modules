/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 18:49:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"


int main( void )
{
	Bureaucrat	b("Burea", 20);
	Bureaucrat	pres("PRES", 1);

	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}

	std::cout << "Executing form without signing " << std::endl;
	b.executeForm(f1);
	std::cout << "Signing then executing" << std::endl;
	std::cout << "----------------------" << std::endl;
	b.signForm(f1);
	b.executeForm(f1);
	std::cout << "----------------------" << std::endl;
	b.signForm(f2);
	b.executeForm(f2);
	std::cout << "----------------------" << std::endl;
	b.signForm(f3);	
	b.executeForm(f3);
	pres.signForm(f3);	
	pres.executeForm(f3);
	std::cout << "----------------------" << std::endl;
	return 0;
}
