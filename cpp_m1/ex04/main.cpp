/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/19 16:08:47 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int ac, char **av)
{
	Sed	prog;

	if (ac == 4)
	{
		prog.OpenFile(av[1]);
		if (prog.IsValidFile())
		{
			prog.FindAndReplace(av[2], av[3]);
			prog.WriteToFile();
			prog.CloseFile();
		}
		else
			std::perror("Open file error");
	}
	return 0;
}
