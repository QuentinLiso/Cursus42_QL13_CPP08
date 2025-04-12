/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qliso <qliso@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:32:50 by qliso             #+#    #+#             */
/*   Updated: 2025/04/11 15:55:22 by qliso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <exception>
# include <limits>
# include <utility>
# include <algorithm>
# include <limits>

class	Span
{
	private:
		unsigned int const	_size;
		std::vector<int>	_span;
		
		Span(void);
		
	public:
		class SingleElementException : public std::exception
		{
			private :
				std::string	_msg;
			public :
				SingleElementException(std::string const & msg);
				virtual ~SingleElementException(void) throw();
				virtual const char* what() const throw();
		};
		class RangeOverflowException : public std::exception
		{
			private :
				std::string _msg;
			public :
				RangeOverflowException(std::string const & msg);
				virtual ~RangeOverflowException(void) throw();
				virtual const char* what() const throw();
		};


		Span(unsigned int n);
		Span(Span const &c);
		Span& operator=(Span const &rhs);
		virtual ~Span(void);


		unsigned int const& getSize(void) const;
		std::vector<int> const& getSpan(void) const;

		void	addNumber(int n);
		void	addRange(int i, int j);
		void	addRange(std::vector<int> const &v);
		void	addRandom(unsigned int n, unsigned int range);
		void	displayInfo(void) const;
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
};

std::ostream&	operator<<(std::ostream &o, std::vector<int> const & rhs);
#endif