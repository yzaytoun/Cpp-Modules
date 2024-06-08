/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:48:40 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/06/08 17:23:26 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	NewLine(void)
{
	std::cout << std::endl;
}

void	PrintString(const std::string str)
{
	int			x = 0;
	int			len;
	std::locale	loc;

	if (str.empty())
		return ;
	len = str.length();
	while (x < len)
	{
		std::cout << std::toupper(str[x], loc);
		++x;
	}
}

int main(int argc, char const *argv[])
{
	int	x = 1;

	if (argc > 1)
	{
		while (x < argc)
		{
			PrintString(argv[x]);
			if (x != argc - 1)
				PrintString(" ");
			++x;
		}
		NewLine();
	}
	else
	{
		PrintString("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		NewLine();
	}
	return (0);
}
