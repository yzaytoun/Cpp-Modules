/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:48:34 by yzaytoun          #+#    #+#             */
/*   Updated: 2024/09/21 18:57:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class Fixed
{
	private:
		int					_fixed_point;
		static const int	_fraction = 8;
	public:
		Fixed();
		Fixed(const Fixed& f);
		~Fixed();
		Fixed& 	operator = (const Fixed &f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
