/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:31:01 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:43:54 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <exception>

class Bureaucrat
{
	enum Grade
	{
		TOO_HIGH = -1,
		TOO_LOW,
		VALID
	};

	private:
		std::string	_name;
		int					_grade;
	public:
		Bureaucrat(std::string name);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& Bureaucrat);
		Bureaucrat&		operator=(const Bureaucrat& bureaucrat);
	
	Bureaucrat::Grade	IsValidGrade(int grade) const;
	std::string			getName(void) const;
	int					getGrade(void) const;
	void				incrementGrade(int amount);
	void				decrementGrade(int amount);
	
	/* Exceptions */
	class	GradeTooHighException: std::exception
	{
		public:
			const char *	what(int grade) throw();
	};

	class	GradeTooLowException : std::exception
	{
		public:
			const char*		what(int grade) throw();
	};
};
std::ostream&	operator<<(std::ostream& out ,const Bureaucrat& bureaucrat);