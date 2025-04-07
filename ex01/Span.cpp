/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:32:52 by qliso             #+#    #+#             */
/*   Updated: 2025/04/08 01:42:00 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Canonical & constructors
Span::Span(void) : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(Span const &c) : _size(c._size), _span(std::vector<int>(c._span)) {}

Span&	Span::operator=(Span const &rhs)
{
	if (this != &rhs && this->_size == rhs._size)
		this->_span = rhs._span;
	else
		std::cerr << "Copy assignment cannot work on spans of different sizes" << std::endl;
	return (*this);
}

Span::~Span(void) {}

// Getters
unsigned int const & Span::getSize(void) const { return this->_size; }

std::vector<int> const & Span::getSpan(void) const { return this->_span; }


// Member functions
void	Span::addNumber(int n)
{
	if (this->_span.size() == this->_size)
		throw (std::exception());
	this->_span.push_back(n);
}

void	Span::addRange(int i, int j)
{
	int	start = std::min(i, j);
	int	end = std::max(i, j);
	unsigned int rangeSize = static_cast<unsigned int>(end - start + 1); 

	if (this->_size - this->_span.size() < rangeSize)
		throw(std::exception());	
	this->_span.reserve(this->_span.size() + rangeSize);
	for (int k = start; k <= end; k++)
		this->_span.push_back(k);
}

void	Span::addRange(std::vector<int> const &v)
{
	if (this->_size - this->_span.size() < v.size())
		throw(std::exception());
	this->_span.reserve(this->_span.size() + v.size());
	this->_span.insert(this->_span.end(), v.begin(), v.end());
}

void	Span::addRandom(unsigned int n, unsigned int range)
{
	if (this->_size - this->_span.size() < n)
		throw(std::exception());
	this->_span.reserve(this->_span.size() + n);
	for (unsigned int i = 0; i < n; i++)
	{
		this->_span.push_back((std::rand() % (2 * range + 1)) - range);	
	}	
}

// Non-member functions
std::ostream&	operator<<(std::ostream &o, std::vector<int> const & rhs)
{
	if (rhs.size() == 0)
	{
		o << "Span is empty" << std::endl;
		return (o);
	}
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	ite = rhs.end();

	for (it = rhs.begin(); it != ite; it++)
	{
		o << *it << " ";
	}
	o << std::endl;
	return (o);
}