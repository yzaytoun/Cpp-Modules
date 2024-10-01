/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:48:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/29 13:52:14 by yzaytoun         ###   ########.fr       */
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
	
		Fixed& 			operator=(const Fixed &f);
		friend std::ostream&	operator<<(std::ostream &out, const Fixed &f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

void	print(std::string str, int endl);