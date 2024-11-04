/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:39:12 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/11/04 16:28:46 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "InputValidator.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
	{
		std::cout << "The program only accepts a single literal as an argument." << std::endl;
		return (1);
	}	
	
	InputValidator check(argv[1]);

	try
	{
		check.isValidInput();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
	
	return (0);
}