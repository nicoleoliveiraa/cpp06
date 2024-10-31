/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputValidator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:57:29 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/10/31 18:47:29 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <iostream>

class InputValidator {
private:
	std::string _input;
	InputValidator();
	bool _isChar() const;
	bool _isNum() const;
	bool _isSpecial() const;

public:
	InputValidator(std::string src);
	InputValidator(const InputValidator& src);
	InputValidator& operator=(const InputValidator& src);
	~InputValidator();

	void isValidInput() const;

	class InvalidInputException : public std::exception {
	public:
		const char* what() const throw();
	};
};

#endif // INPUTVALIDATOR_HPP