/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:31:01 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/11/04 18:35:15 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	if (this != &src)
		return (*this);
	return (*this);
}

void ScalarConverter::convert(std::string lit)
{
	e_type litType = findType(lit);

	//std::cout << MIN_CHAR << std::endl;
	//std::cout << MAX_CHAR << std::endl;
	//std::cout << litType << std::endl;

	switch (litType)
	{
		case SPECIAL:
			convertSpecial(lit);
			break;
		case CHAR:
			convertChar(lit);
			break;
		case INT:
			convertInt(lit);
			break;
		case FLOAT:
			convertFloat(lit);
			break;
		case DOUBLE:
			convertDouble(lit);
			break;
		default:
			break;
	}
}
