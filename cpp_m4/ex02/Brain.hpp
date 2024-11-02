/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:57:28 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 17:37:57 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		~Brain();
		Brain(const Brain& brain);
	
	std::string	getIdea(int idx);
	void		setIdea(const int idx, const std::string idea);
};

