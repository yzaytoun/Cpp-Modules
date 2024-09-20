/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/20 19:05:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	har;

	std::cout << "\n\033[1;31mPassing empty string\033[0m" << std::endl;
	har.complain("");
	std::cout << "\n\033[1;32mPassing info\033[0m" << std::endl;
	har.complain("info");
	std::cout << "\n\033[1;34mPassing debug\033[0m" << std::endl;
	har.complain("debug");
	std::cout << "\n\033[1;31mPassing error\033[0m" << std::endl;
	har.complain("error");
	std::cout << "\n\033[1;33mPassing Warning\033[0m" << std::endl;
	har.complain("warning");
	std::cout << "\n\033[1;31mPassing strange input\033[0m" << std::endl;
	har.complain("asdasdasdaga asfasfasf");
	return 0;
}
