/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:26:12 by qliso             #+#    #+#             */
/*   Updated: 2025/04/11 16:59:36 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

template < typename T >
int easyFind(T& container, int n)
{
    typename T::iterator    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw(std::out_of_range("Value not found bro"));
    return (*it);
}
