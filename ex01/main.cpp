/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:26 by qliso             #+#    #+#             */
/*   Updated: 2025/04/08 01:36:55 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <ctime>
#include "Span.hpp"

int	main ( void )
{
	std::srand(std::time(NULL));
	Span	span(10000);
	std::cout << span.getSpan();
	span.addNumber(1);
	span.addNumber(215);
	span.addNumber(7);
	span.addRange(-5, 34);
	std::cout << span.getSpan();
	try
	{
		span.addRange(1, 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	span.addRandom(5000, 1234);
	std::cout << span.getSpan();
	return ( 0 );
}