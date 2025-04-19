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

Intern::Intern() : _name("intern")
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const std::string name, unsigned short grade) : _name(name)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& intern) : _name(intern.getName())
{
	std::cout << "Intern Copy constructor called" << std::endl;
}

const std::string	Intern::getName(void) const
{
	return (_name);
}

AForm*	Intern::makeForm(const std::string form_name, const std::string target)
{
	AForm*	forms[3] = {
		ShrubberyCreationForm,
		RobotomyRequestForm,
		PresidentialPardonForm
	};

	return (forms[idx]);
}

/*	Operators */

Intern&	Intern::operator=(const Intern& intern)
{
	if (this != &intern)
		_grade = intern.getGrade();
	return (*this);
	std::cout << "Intern assignment operator called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out ,const Intern& intern)
{
	out << "\n-------------------\n"
		<< Intern.getName()
		<< ", bureacurate grade "
		<< Intern.getGrade()
		<< "\n-------------------\n";
	return (out);
}
