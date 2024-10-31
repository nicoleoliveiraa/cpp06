/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:01:05 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/31 19:15:32 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

e_type findType(std::string lit)
{
	if (lit == "nan" || lit == "nanf" || lit == "+inf" || lit == "+inff" || lit == "-inf" || lit == "-inff")
		return SPECIAL;
	if (lit.length() == 1 && isascii(lit[0]))
		return CHAR;
	if (lit[lit.length() - 1] == 'f')
		return FLOAT;
	for (size_t i = 0; i < lit.length(); ++i)
	{
		if (lit[i] == '.')
			return DOUBLE;
	}
	return INT;
}

void convertSpecial(std::string lit)
{
	if (lit == "nan" || lit == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (lit == "+inf" || lit == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (lit == "-inf" || lit == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void convertChar(std::string lit)
{
	char c = lit[0];

	if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(c) << std::endl; 
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl; 
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl; 
}

void convertInt(std::string lit)
{
	long num = std::atol(lit.c_str());

	if (num >= 0 && num <= 127)
	{
		if (isprint(num))
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << "impossible" << std::endl;
		
	if (num < MIN_INT || num > MAX_INT)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		
	std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl; 
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl; 
}

void convertFloat(std::string lit)
{
	float num = std::atof(lit.c_str());
	bool tolerance = std::fabs(num - static_cast<int>(num)) < 0.0000000000001;
	
	if (num >= 0 && num <= 127)
	{
		if (isprint(num))
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << "impossible" << std::endl;

	if (num < MIN_INT || num > MAX_INT)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (num < MIN_FLOAT || num > MAX_FLOAT)
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << num << (tolerance ? ".0f" : "f") << std::endl;
		
	std::cout << "double: " << static_cast<double>(num) << (tolerance ? ".0" : "") << std::endl;
}

void convertDouble(std::string lit)
{
	double num = atof(lit.c_str());
	bool tolerance = std::fabs(num - static_cast<int>(num)) < 0.0000000000001;
	
	
	if (num >= 0 && num <= 127)
	{
		if (isprint(num))
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << "impossible" << std::endl;

	if (num < MIN_INT || num > MAX_INT)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	if (num < MIN_FLOAT || num > MAX_FLOAT)
		std::cout << "float: " << "impossible" << std::endl;
	else
		std::cout << "float: " << num << (tolerance ? ".0f" : "f") << std::endl;

	if (num < MIN_DOUBLE || num > MAX_DOUBLE)
		std::cout << "double: " << "impossible" << std::endl;
	else
		std::cout << "double: " << num << std::endl;
}
