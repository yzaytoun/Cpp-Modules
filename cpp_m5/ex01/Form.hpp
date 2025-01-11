/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 19:50:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

typedef	const unsigned short	t_grade;

class Bureaucrat;

class Form
{
	enum Grade
	{
		TOO_HIGH = -1,
		TOO_LOW,
		VALID
	};

	private:
		std::string		_name;
		bool			_is_signed;
		unsigned short	_grade_tosign;
		unsigned short	_grade_toexecute;
		
		void		validateGrade(unsigned short grade) const;
		Form::Grade	IsValidGrade(unsigned short grade) const;
		bool		canSign(t_grade grade) const;
		bool		canExecute(t_grade grade) const;
	public:
		Form(const std::string name, t_grade grade_tosign, t_grade grade_toexecute);
		~Form();
		Form(const Form& form);
		Form&		operator=(const Form& Form);
	
		std::string			getName(void) const;
		bool				isSigned(void) const;
		unsigned short		getGradeToSign(void) const;
		unsigned short		getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat& b);
	
	/* Exceptions */
	class	GradeTooHighException: public std::exception
	{
		public:
			const char*	what() const throw()
			{
				return ("Grade is too high");
			}
	};

	class	GradeTooLowException : public std::exception
	{
		public:
			const char*	what() const throw()
			{
				return ("Grade is too low");
			}
	};
};

std::ostream&	operator<<(std::ostream& out ,const Form& Form);
