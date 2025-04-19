/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 18:48:35 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(MIN_GRADE)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned short grade) : _name(name), _grade(grade)
{
	this->validateGrade(grade);
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
		_grade = bureaucrat.getGrade();
	return (*this);
	std::cout << "Bureaucrat assignment operator called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out ,const Bureaucrat& bureaucrat)
{
	out << "\n-------------------\n"
		<< bureaucrat.getName()
		<< ", bureacurate grade "
		<< bureaucrat.getGrade()
		<< "\n-------------------\n";
	return (out);
}

/*	Methods	*/

Bureaucrat::Grade	Bureaucrat::IsValidGrade(int grade) const
{
	if (grade > MIN_GRADE)
		return (TOO_LOW);
	else if (grade < MAX_GRADE)
		return (TOO_HIGH);
	return (VALID);
}

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::validateGrade(unsigned short grade) const
{
	switch (this->IsValidGrade(grade))
	{
		case TOO_HIGH: 	throw Bureaucrat::GradeTooHighException();
		case TOO_LOW: 	throw Bureaucrat::GradeTooLowException();
		case VALID:		break;
	}
}

void	Bureaucrat::incrementGrade(int amount)
{
	validateGrade(_grade - amount);
	_grade -= amount;
}

void	Bureaucrat::decrementGrade(int amount)
{
	validateGrade(_grade + amount);
	_grade += amount;
}

void	Bureaucrat::signForm(AForm& form)
{
	if (!form.isSigned())
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr
				<< this->getName() << " couldn't sign " << form.getName()
				<< " because "
				<< e.what()
				<< std::endl;
		}
	}
	else
	{
		std::cerr
			<< this->getName() << " couldn't sign " << form.getName()
			<< " because "
			<< "form is already signed"
			<< std::endl;
	}
}

void	Bureaucrat::executeForm(AForm& form)
{
	if (form.isSigned())
	{
		try
		{
			form.execute(*this);
			std::cout << this->getName() << " executed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr
				<< this->getName() << " couldn't execute " << form.getName()
				<< " because "
				<< e.what()
				<< std::endl;
		}
	}
	else
	{
		std::cerr
			<< this->getName() << " couldn't execute " << form.getName()
			<< " because "
			<< "form is not signed"
			<< std::endl;
	}
}
