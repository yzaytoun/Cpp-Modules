/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 18:48:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& intern)
{
	(void)intern;
	std::cout << "Intern Copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& intern)
{
	(void) intern;
	return (*this);
	std::cout << "Intern assignment operator called" << std::endl;
}

Intern::Forms	getFormToken(const std::string form_name)
{
	std::string	forms[3] = {
		"shrubbery",
		"robotomy request",
		"presidential pardon"
	};
	Intern::Forms	token = Intern::FormsCount;

	for (int i = 0; i < Intern::FormsCount; i++)
	{
		if (forms[i].compare(form_name) == 0)
		{
			token = static_cast<Intern::Forms>(i);
			break;
		}
	}
	return (token);
}

/*
	@param form_name the name of the form {"shrubbery", "robotomy request", "presidential pardon"}
*/
AForm*	Intern::makeForm(const std::string form_name, const std::string target)
{
	AForm* new_form = NULL;

	switch (getFormToken(form_name))
	{
		case ShrubberyCreation: new_form = new ShrubberyCreationForm(target); break;
		case RobotomyRequest: new_form = new RobotomyRequestForm(target); break;
		case PresidentialPardon: new_form = new PresidentialPardonForm(target); break;
		default: throw DoesNotExistException();
	}
	return (new_form);
}
