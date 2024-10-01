/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:48:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/10/01 19:32:38 by yzaytoun         ###   ########.fr       */
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
	
		friend std::ostream&	operator<<(std::ostream &out, const Fixed &f);
		Fixed&					operator=(const Fixed& f);
		
		friend bool 			operator<(const Fixed& f1, const Fixed& f2);
		friend bool 			operator>(const Fixed& f1, const Fixed& f2);
		friend bool 			operator<=(const Fixed& f1, const Fixed& f2);
		friend bool 			operator>=(const Fixed& f1, const Fixed& f2);
		friend bool 			operator==(const Fixed& f1, const Fixed& f2);
		friend bool 			operator!=(const Fixed& f1, const Fixed& f2);
	
		friend Fixed 			operator+(const Fixed& f1, const Fixed& f2);
		friend Fixed 			operator-(const Fixed& f1, const Fixed& f2);
		friend Fixed 			operator/(const Fixed& f1, const Fixed& f2);
		friend Fixed 			operator*(const Fixed& f1, const Fixed& f2);

		friend const Fixed& 	operator++(Fixed& f);
		friend const Fixed& 	operator--(Fixed& f);
		friend const Fixed 		operator++(Fixed& f, int i);
		friend const Fixed 		operator--(Fixed& f, int i);

		static const Fixed&		min(const Fixed& f1, const Fixed& f2);
		static const Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&		max(const Fixed& f1, const Fixed& f2);
		static const Fixed&		max(Fixed& f1, Fixed& f2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

void	print(std::string str, int endl);