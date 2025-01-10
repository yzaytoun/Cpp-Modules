/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:42:50 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(0)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) : _name(bureaucrat.getName()), _grade(bureaucrat.getGrade())
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

/*	Operators */

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
	{
		_name = bureaucrat.getName();
		_grade = bureaucrat.getGrade();
	}
	return (*this);
	std::cout << "Bureaucrat assignment operator called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out ,const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName()
		<< ", bureacurate grade "
		<< bureaucrat.getGrade();
	return (out);
}

/*	Methods	*/

Bureaucrat::Grade	Bureaucrat::IsValidGrade(int grade) const
{
	if (grade >= 1 && grade <= 150)
		return (VALID);
	else if (grade < 1)
		return (TOO_HIGH);
	return (TOO_LOW);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(int amount)
{
	switch (this->IsValidGrade(amount + _grade))
	{
		case VALID: 	_grade += amount;	break;
		case TOO_HIGH: 	throw 0; 	break;
		case TOO_LOW: 	throw 1; 	break;
	}
}

void	Bureaucrat::decrementGrade(int amount)
{
	switch (this->IsValidGrade(amount - _grade))
	{
		case VALID: 	_grade -= amount;	break;
		case TOO_HIGH:	throw 0; 	break;
		case TOO_LOW: 	throw 1; 	break;
	}
}


/* Exceptions */
const char *	Bureaucrat::GradeTooHighException::what(int grade) throw()
{
	std::ostringstream	os;

	os << "Grade" << grade << "es too high" << std::endl;
	return (os.str().c_str());
}

const char *	Bureaucrat::GradeTooLowException::what(int grade) throw()
{
	std::ostringstream	os;

	os << "Grade" << grade << "es too low" << std::endl;
	return (os.str().c_str());
}
