/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 17:00:02 by qliso             #+#    #+#             */
/*   Updated: 2025/05/02 12:14:29 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template < typename T >
MutantStack<T>::MutantStack(void) {}

template < typename T >
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {}

template < typename T >
MutantStack<T>& MutantStack<T>::operator=(MutantStack const &rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
	return (*this);
}

template < typename T >
MutantStack<T>::~MutantStack(void) {}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin(void) { return (this->c.begin()); }

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::end(void) { return (this->c.end()); }

template < typename T >
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const { return (this->c.begin()); }

template < typename T >
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const { return (this->c.end()); }

template < typename T >
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void) { return (this->c.rbegin()); }

template < typename T >
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void) { return (this->c.rend()); }

template < typename T >
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const { return (this->c.rbegin()); }

template < typename T >
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const { return (this->c.rend()); }

