/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		enum Forms
		{
			ShrubberyCreation,
			RobotomyRequest,
			PresidentialPardon,
			FormsCount
		};

	public:
		Intern();
		~Intern();
		Intern(const Intern& Intern);
		Intern&	operator=(const Intern& Intern);
	/* Methods */
	
	AForm*				makeForm(const std::string form_name, const std::string target);
	
	/* Exceptions */
	class	DoesNotExistException: public std::exception
	{
		public:
			const char*	what() const throw()
			{
				return ("Form does not exist!!");
			}
	};
};
