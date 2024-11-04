/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:24:11 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/11/04 18:22:05 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <exception>
#include <cstdlib>

#define MIN_CHAR std::numeric_limits<char>::min()
#define MAX_CHAR std::numeric_limits<char>::max()
#define MIN_INT std::numeric_limits<int>::min()
#define MAX_INT std::numeric_limits<int>::max()
#define MIN_FLOAT std::numeric_limits<float>::min()
#define MAX_FLOAT std::numeric_limits<float>::max()
#define MIN_DOUBLE std::numeric_limits<double>::min()
#define MAX_DOUBLE std::numeric_limits<double>::max()

enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
};

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	ScalarConverter& operator=(const ScalarConverter& src);

public:
	~ScalarConverter();

	static void convert(std::string lit);
};

e_type findType(std::string lit);
void convertSpecial(std::string lit);
void convertChar(std::string lit);
void convertInt(std::string lit);
void convertFloat(std::string lit);
void convertDouble(std::string lit);

#endif // SCALARCONVERTER_HPP