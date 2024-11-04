/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputValidator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:58:18 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/11/04 18:28:47 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputValidator.hpp"

InputValidator::InputValidator() {}

InputValidator::~InputValidator() {}

InputValidator::InputValidator(std::string src) : _input(src) {}

InputValidator::InputValidator(const InputValidator& src)
{
	*this = src;
}

InputValidator& InputValidator::operator=(const InputValidator& src)
{
	if (this != &src)
		return (*this);
	return (*this);
}

const char* InputValidator::InvalidInputException::what() const throw()
{
	return "Invalid input: Parameter does not meet the required format for conversion!";
};

bool InputValidator::_isChar() const
{
	return (_input.length() == 1 && isascii(_input[0]));
}

bool InputValidator::_isNum() const
{
	int index = 0;
	bool quote = false;
	
	if (_input[0] == '-' || _input[0] == '+')
	{
		if (_input.length() == 1)
			return (false);
		index = 1;
	}
	for (size_t i = index; i < _input.length(); ++i)
	{
		if (!isdigit(_input[i]))
		{
			if (i == _input.length() - 1 && _input[i] == 'f' && isdigit(_input[i - 1]))
				continue ;
			else if (_input[i] == '.' && quote == false && i != _input.length() - 1\
				 && _input[i + 1] != 'f')
			{
				quote = true;
				continue ;
			}
			else
				return (false);
		}
	}
	return (true);
}

bool InputValidator::_isSpecial() const
{
	if (_input == "nan" || _input == "nanf" || _input == "+inf" || _input == "+inff" || _input == "-inf" || _input == "-inff")
		return (true);
	return (false);
}

void InputValidator::isValidInput() const
{
	if (_isSpecial() || _isChar() || _isNum())
		return ;

	throw InvalidInputException();
}
