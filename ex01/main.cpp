/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:26 by qliso             #+#    #+#             */
/*   Updated: 2025/04/11 16:05:29 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <ctime>
#include "Span.hpp"


void	test1(void)
{
	std::cout << "**** TEST 1 : ****" << std::endl;
	Span	span(500);
	std::cout << span.getSpan();
	span.addNumber(1);
	span.addNumber(215);
	span.addNumber(7);
	span.addRange(-5, 34);
	std::cout << span.getSpan();
	std::cout << span.longestSpan() << std::endl;
	try
	{
		span.addRange(1, 1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << span.getSpan() << std::endl;	
}

void	test2(void)
{
	std::cout << "**** TEST 2 : ****" << std::endl;
	Span	span(100);
	span.addRandom(10, 1000);
	span.displayInfo();
}

void	test3(void)
{
	std::cout << "****TEST 3 : ****" << std::endl;
	Span span(1);
	try
	{
		span.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		span.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		span.addNumber(3);
		span.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main ( void )
{
	std::srand(std::time(NULL));
	test1();
	test2();
	test3();
	return ( 0 );
}