/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:20:49 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/11/06 13:56:11 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	//Base* ptr = NULL;
    Base* ptr = generate();
	Base d;
    
	identify(ptr);
	identify(*ptr);
	identify(&d);
	identify(d);

    delete ptr;
    return 0;
}