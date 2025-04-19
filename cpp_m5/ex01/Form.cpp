/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                    	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:29:49 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 14:33:59 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form"), _is_signed(false), _grade_tosign(MIN_GRADE) ,_grade_toexecute(MIN_GRADE)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, t_grade grade_tosign, t_grade grade_toexecute)
	: _name(name), _is_signed(false), _grade_tosign(grade_tosign)
	,_grade_toexecute(grade_toexecute)
{
	this->validateGrade(grade_toexecute);
	this->validateGrade(grade_tosign);
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form& form)
	: _name(form.getName()), _is_signed(form.isSigned()),
	_grade_tosign(form.getGradeToSign()), _grade_toexecute(form.getGradeToExecute())
{
	std::cout << "Form Copy constructor called" << std::endl;
}

/*	Operators */

Form&	Form::operator=(const Form& Form)
{
	if (this != &Form)
		_is_signed = Form.isSigned();
	return (*this);
	std::cout << "Form assignment operator called" << std::endl;
}

std::ostream&	operator<<(std::ostream& out ,const Form& Form)
{
	out << "\n-------------------\n"
		<< "Form -> name: "
		<< Form.getName()
		<< " | Grade to execute: "
		<< Form.getGradeToExecute()
		<< " | Grade to sign: "
		<< Form.getGradeToSign()
		<< "\n-------------------\n";
	return (out);
}

/*	Methods	*/

Form::Grade	Form::IsValidGrade(unsigned short grade) const
{
	if (grade > MIN_GRADE)
		return (TOO_LOW);
	else if (grade < MAX_GRADE)
		return (TOO_HIGH);
	return (VALID);
}

const std::string	Form::getName(void) const
{
	return (_name);
}

unsigned short	Form::getGradeToExecute(void) const
{
	return (_grade_toexecute);
}

unsigned short	Form::getGradeToSign(void) const
{
	return (_grade_tosign);
}

bool	Form::isSigned(void) const
{
	return (_is_signed);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (canSign(b.getGrade()))
		_is_signed = true;
	else
		throw Form::GradeTooLowException();
}

bool	Form::canSign(t_grade grade) const
{
	if (grade <= _grade_tosign)
		return (true);
	return (false);
}

bool	Form::canExecute(t_grade grade) const
{
	if (grade <= _grade_toexecute && _is_signed)
		return (true);
	return (false);
}

void	Form::validateGrade(unsigned short grade) const
{
	switch (this->IsValidGrade(grade))
	{
		case TOO_HIGH: 	throw Form::GradeTooHighException();
		case TOO_LOW: 	throw Form::GradeTooLowException();
		case VALID:		break;
	}
}
