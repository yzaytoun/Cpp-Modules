/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/20 17:36:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	har;

	std::cout << "Passing empty string" << std::endl;
	har.complain("");
	std::cout << "Passing info" << std::endl;
	har.complain("info");
	std::cout << "Passing debug" << std::endl;
	har.complain("debug");
	std::cout << "Passing error" << std::endl;
	har.complain("error");
	std::cout << "Passing Warning" << std::endl;
	har.complain("warning");
	std::cout << "Passing strange input" << std::endl;
	har.complain("asdasdasdaga asfasfasf");
	return 0;
}
