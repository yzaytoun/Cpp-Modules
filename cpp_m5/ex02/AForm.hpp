/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:15:31 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 20:10:51 by yzaytoun         ###   ########.fr       */
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

class AForm
{
	enum Grade
	{
		TOO_HIGH = -1,
		TOO_LOW,
		VALID
	};

	private:
		std::string		_name;
		std::string		_target;
		bool			_is_signed;
		unsigned short	_grade_tosign;
		unsigned short	_grade_toexecute;
		
		void			validateGrade(unsigned short grade) const;
		AForm::Grade	IsValidGrade(unsigned short grade) const;
		bool			canSign(t_grade grade) const;
		bool			canExecute(t_grade grade) const;
	public:
		AForm(const std::string name, t_grade grade_tosign, t_grade grade_toexecute, std::string target);
		virtual ~AForm();
		AForm(const AForm& form);
		AForm&		operator=(const AForm& form);
	
		std::string			getName(void) const;
		std::string			getTarget(void) const;
		bool				isSigned(void) const;
		unsigned short		getGradeToSign(void) const;
		unsigned short		getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat& b);
		void				execute(Bureaucrat const & executor) const;
		virtual void		formAction(void) const;
	
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

std::ostream&	operator<<(std::ostream& out ,const AForm& form);
