/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:22:38 by qliso             #+#    #+#             */
/*   Updated: 2025/04/07 18:28:29 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <deque>
#include "easyFind.hpp"

void    test_list( void )
{
    std::list<int>  lst1;

    lst1.push_back(1);
    lst1.push_back(17);
    lst1.push_back(42);
    lst1.push_back(3);
    lst1.push_front(3);
    try
    {
        int i = easyFind(lst1, 3);
        std::cout << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void    test_deque( void )
{
    std::deque<int>  lst1;

    lst1.push_back(1);
    lst1.push_back(17);
    lst1.push_back(42);
    lst1.push_back(3);
    try
    {
        int i = easyFind(lst1, 3);
        std::cout << i << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
}

int main ( void )
{
    test_list();
    
    return ( 0 );
}