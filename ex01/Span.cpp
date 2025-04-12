/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:32:52 by qliso             #+#    #+#             */
/*   Updated: 2025/04/11 16:07:34 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Exceptions
Span::SingleElementException::SingleElementException(std::string const & msg) : _msg(msg) {}
Span::SingleElementException::~SingleElementException(void) throw() {}
const char*	Span::SingleElementException::what(void) const throw() { return this->_msg.c_str(); }

Span::RangeOverflowException::RangeOverflowException(std::string const & msg) : _msg(msg) {}
Span::RangeOverflowException::~RangeOverflowException(void) throw() {}
const char*	Span::RangeOverflowException::what(void) const throw() { return this->_msg.c_str(); }

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
		throw (Span::RangeOverflowException("Range overflow"));
	this->_span.push_back(n);
}

void	Span::addRange(int i, int j)
{
	int	start = std::min(i, j);
	int	end = std::max(i, j);
	unsigned int rangeSize = static_cast<unsigned int>(end - start + 1); 

	if (this->_size - this->_span.size() < rangeSize)
		throw(Span::RangeOverflowException("Range overflow"));	
	this->_span.reserve(this->_span.size() + rangeSize);
	for (int k = start; k <= end; k++)
		this->_span.push_back(k);
}

void	Span::addRange(std::vector<int> const &v)
{
	if (this->_size - this->_span.size() < v.size())
		throw(Span::RangeOverflowException("Range overflow"));
	this->_span.reserve(this->_span.size() + v.size());
	this->_span.insert(this->_span.end(), v.begin(), v.end());
}

void	Span::addRandom(unsigned int n, unsigned int range)
{
	if (this->_size - this->_span.size() < n)
		throw(Span::RangeOverflowException("Range overflow"));
	this->_span.reserve(this->_span.size() + n);
	for (unsigned int i = 0; i < n; i++)
	{
		this->_span.push_back((std::rand() % (2 * range + 1)) - range);	
	}	
}

void	Span::displayInfo(void) const
{
	std::vector<int>	sorted(this->_span);
	std::sort(sorted.begin(), sorted.end());
	
	std::cout << "Raw span : " << std::endl;
	std::cout << this->_span << std::endl;
	std::cout << "Sorted span : " << std::endl;
	std::cout << sorted << std::endl;
	std::cout << "Longest span : " << this->longestSpan() << std::endl;
	std::cout << "Shortest span : " << this->shortestSpan() << std::endl;
}

int	Span::shortestSpan(void) const
{
	if (this->_size < 2 || this->_span.size() < 2)
		throw (SingleElementException("Not enough elements to compute shortestSpan"));
	std::vector<int> sorted(this->_span);
	std::sort(sorted.begin(), sorted.end());

	int	shortest = std::numeric_limits<int>::max();
	int	diff;
	for (size_t i = 0; i < sorted.size(); i++)
	{
		diff = sorted[i + 1] - sorted[i];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

int	Span::longestSpan(void) const
{
	if (this->_size < 2 || this->_span.size() < 2)
		throw (SingleElementException("Not enough elements to compute longestSpan"));
	std::vector<int>::const_iterator	min = std::min_element(this->_span.begin(), this->_span.end());
	std::vector<int>::const_iterator	max = std::max_element(this->_span.begin(), this->_span.end());
	return (*max - *min);
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
	return (o);
}