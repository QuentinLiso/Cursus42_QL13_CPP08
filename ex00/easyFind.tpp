/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:26:12 by qliso             #+#    #+#             */
/*   Updated: 2025/04/07 20:26:54 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

template < typename T >
int easyFind(T& container, int n)
{
    int i = 0;
    typename T::const_iterator   it;
    typename T::const_iterator   ite = container.end();
    
    for (it = container.begin(); it != ite; ++it)
    {
        if (*it == n)
            return (i);
        i++;
    }
    throw(std::out_of_range("Value not found bro"));
    return (-1);
}
