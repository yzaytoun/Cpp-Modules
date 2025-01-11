/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:15:25 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 20:10:44 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, t_grade grade_tosign, t_grade grade_toexecute, std::string target)
	: _name(name), _target(target), _is_signed(false), _grade_tosign(grade_tosign)
	,_grade_toexecute(grade_toexecute)
{
	this->validateGrade(grade_toexecute);
	this->validateGrade(grade_tosign);
	std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm& form)
	: _name(form.getName()), _target(form.getTarget()),_is_signed(form.isSigned()),
	_grade_tosign(form.getGradeToSign()), _grade_toexecute(form.getGradeToExecute())
{
	std::cout << "Form Copy constructor called" << std::endl;
}

/*	Operators */

AForm&	AForm::operator=(const AForm& form)
{
	if (this != &form)
	{
		_name = form.getName();
		_grade_toexecute = form.getGradeToExecute();
		_grade_tosign = form.getGradeToSign();
	}
	return (*this);
	std::cout << "AForm assignment operator called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out ,const AForm& form)
{
	out << "\n-------------------\n"
		<< "Form: "
		<< form.getName()
		<< " | Grade to execute: "
		<< form.getGradeToExecute()
		<< " | Grade to sign: "
		<< form.getGradeToSign()
		<< " | "
		<< "\n-------------------\n";
	return (out);
}

/*	Methods	*/

AForm::Grade	AForm::IsValidGrade(unsigned short grade) const
{
	if (grade > 150)
		return (TOO_LOW);
	else if (grade < 1)
		return (TOO_HIGH);
	return (VALID);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

std::string	AForm::getTarget(void) const
{
	return (_target);
}

unsigned short	AForm::getGradeToExecute(void) const
{
	return (_grade_toexecute);
}

unsigned short	AForm::getGradeToSign(void) const
{
	return (_grade_tosign);
}

bool	AForm::isSigned(void) const
{
	return (_is_signed);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (canSign(b.getGrade()))
		_is_signed = true;
	else
		throw AForm::GradeTooLowException();
}

bool	AForm::canSign(t_grade grade) const
{
	if (grade <= _grade_tosign && !_is_signed)
		return (true);
	return (false);
}

void	AForm::formAction(void) const {}

// TODO -> Throw error unsigned

void	AForm::execute(Bureaucrat const & executor) const
{
	if (canExecute(executor.getGrade()) && _is_signed)
		this->formAction();
	else
		throw AForm::GradeTooLowException();
}

bool	AForm::canExecute(t_grade grade) const
{
	if (grade <= _grade_toexecute)
		return (true);
	return (false);
}

void	AForm::validateGrade(unsigned short grade) const
{
	switch (this->IsValidGrade(grade))
	{
		case TOO_HIGH: 	throw AForm::GradeTooHighException();
		case TOO_LOW: 	throw AForm::GradeTooLowException();
		case VALID:		break;
	}
}
