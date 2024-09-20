/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/20 21:32:33 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static void	ToLower(std::string& str)
{
	int	i = -1;
	int	len = str.length();

	while (++i < len)
		str[i] = std::tolower(str.at(i));
}

static int	get_messagetype(std::string level)
{
	std::string	func_names[5] = {"debug", "info", "warning", "error", "default"};
	int			i = -1;

	ToLower(level);
	while (++i < 4 && func_names[i].compare(level))
		;
	return (i);
}

int main(int ac, char **av)
{
	Harl	har;
	
	if (ac == 2)
	{
		switch (get_messagetype(av[1]))
		{
			case DEBUG:
				har.complain("debug");
			case INFO:
				har.complain("info");
			case WARNING:
				har.complain("warning");
			case ERROR:
				har.complain("error");
			default:
				har.complain("default");
		}
	}
	return (0);
}
