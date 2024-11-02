/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyRealType.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:10:49 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/11/02 19:55:18 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime> 

#define RESET       "\033[0m"
#define BOLD_GREEN       "\033[1m\033[32m"
#define BOLD_RED         "\033[1m\033[31m"
#define BOLD_YELLOW      "\033[1m\033[33m"

Base* generate(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));

    int randomChoice = rand() % 3;

	switch (randomChoice)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
        std::cout << "Detected object type with pointer:" << BOLD_GREEN << "[A]." << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Detected object type with pointer:" << BOLD_GREEN << "[B]." << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Detected object type with pointer:" << BOLD_GREEN << "[C]." << RESET << std::endl;
	else
        std::cout << "Detected object type with pointer:" << BOLD_RED << "[Unknow]." << RESET << std::endl;		
}

void identify(Base& p)
{
	try 
	{
        dynamic_cast<A&>(p);
        std::cout << "Detected object type with reference:" << BOLD_YELLOW << "[A]" << RESET << std::endl;
    } 
    catch (const std::exception &e) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "Detected object type with reference:" << BOLD_YELLOW << "[B]" << RESET << std::endl;
        } 
        catch (const std::exception &e) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "Detected object type with reference:" << BOLD_YELLOW << "[C]" << RESET << std::endl;
            } 
            catch (const std::exception &e) {
                std::cout << "Detected object type with reference:" << BOLD_RED << "[Unknow]" << RESET << std::endl;
            }
        }
    }	
}
