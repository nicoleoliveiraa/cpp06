/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:37:36 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/11/06 13:41:55 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data = {"Joao", 15};
	
	std::cout << "Data infos before serialize:\nName: " << data.name << ".\nAge: " << data.age << "." << std::endl;
	std::cout << "Data address before serialize:\nName: " << &data << "." << std::endl;
	
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	if (ptr == &data) 
	{
        std::cout << "Serializer works!" << std::endl;
		std::cout << "Data infos after deserialize:\nName: " << ptr->name << ".\nAge: " << ptr->age << "." << std::endl;
		std::cout << "Data address after deserialize:\nName: " << &data << "." << std::endl;
	}
	else 
		std::cout << "Serializer failed." << std::endl;
	return (0);
}