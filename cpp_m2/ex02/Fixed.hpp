/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:48:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/11/15 18:30:01 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <sstream>
# include <cmath>

class Fixed
{
	private:
		int					_fixed_point;
		static const int	_fraction = 8;
	public:
		Fixed();
		Fixed(const Fixed& f);
		Fixed(int const integer);
		Fixed(float const integer);
		~Fixed();
	
		Fixed&			operator=(const Fixed& f);
		
		bool 			operator<(const Fixed& f1) const;
		bool 			operator>(const Fixed& f1) const;
		bool 			operator<=(const Fixed& f1) const;
		bool 			operator>=(const Fixed& f1) const;
		bool 			operator==(const Fixed& f1) const;
		bool 			operator!=(const Fixed& f1) const;
	
		Fixed 			operator+(const Fixed& f1) const;
		Fixed 			operator-(const Fixed& f1) const;
		Fixed 			operator/(const Fixed& f1) const;
		Fixed 			operator*(const Fixed& f1) const;

		const Fixed& 	operator++();
		const Fixed& 	operator--();
		const Fixed 	operator++(int i);
		const Fixed 	operator--(int i);

		static const Fixed&		min(const Fixed& f1, const Fixed& f2);
		static const Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&		max(const Fixed& f1, const Fixed& f2);
		static const Fixed&		max(Fixed& f1, Fixed& f2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &out, const Fixed &f);
void	print(std::string str, int endl);