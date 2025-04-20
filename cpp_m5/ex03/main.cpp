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
	Intern someRandomIntern;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* sf = someRandomIntern.makeForm("shrubbery", "Bender");
	AForm* pf = someRandomIntern.makeForm("presidential pardon", "Bender");
	
	try
	{
		std::cout << "-----------------------------" << std::endl;
		AForm* df = someRandomIntern.makeForm("Does not exist", "Bender");
		b.signForm(*df);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	b.signForm(*rrf);
	b.signForm(*sf);
	b.signForm(*pf);
	std::cout << "-----------------------------" << std::endl;
	b.executeForm(*rrf);
	b.executeForm(*sf);
	b.executeForm(*pf);
	std::cout << "-----------------------------" << std::endl;
	
	delete rrf;
	delete sf;
	delete pf;
	return 0;
}
