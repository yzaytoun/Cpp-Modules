/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:13:42 by yzaytoun          #+#    #+#             */
/*   Updated: 2025/01/11 19:59:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137, "target_shrubbery")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", 145, 137, target + "_shrubbery")
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void	ShrubberyCreationForm::formAction(void) const
{
	std::ofstream stream;
	
	stream.open(getTarget().c_str(), std::ios::binary | std::ios::out);
	if (stream.is_open())
	{
		for (size_t i = 0; i < 125; i++)
			stream << repeatChar(static_cast<char>(i), i) << std::endl;
		stream.close();
	}
	else
		throw std::runtime_error("Could not open target file");
}
