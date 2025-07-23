/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:20:53 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/26 15:52:42 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <unistd.h>
#include <fstream>

void	print_data(Data* data)
{
	switch (data->type)
	{
	case BINARY:
		std::cout << "Binary" << "\tcontent: "<< data->content << std::endl;
		break;
	case STRING:
		std::cout << "STRING" << "\tcontent: "<< (char*)data->content << std::endl;
		break;
	
	default:
		break;
	}
}

Data*	new_data(DataType type, void* content)
{
	Data*	data = new Data;

	data->type = type;
	data->content = content;
	return data;
}

int main(void)
{
	Data*				data_1 = new_data(BINARY, NULL);
	Data*				data_2 = new_data(STRING, (char*)"NULL");
	uintptr_t			raw;

	std::cout << "------- data_1 --------- " << std::endl;
	print_data(data_1);
	raw = Serializer::serialize(data_1);
	std::cout << "Raw: "<< raw << std::endl;
	data_1 = Serializer::deserialize(raw);
	print_data(data_1);
	
	std::cout << "------- data_2 --------- " << std::endl;
	print_data(data_2);
	raw = Serializer::serialize(data_2);
	std::cout << "Raw: "<< raw << std::endl;
	data_2 = Serializer::deserialize(raw);
	print_data(data_2);
	
	return (EXIT_SUCCESS);
}
