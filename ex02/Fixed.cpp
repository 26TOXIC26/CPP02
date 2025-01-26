/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:51:40 by amousaid          #+#    #+#             */
/*   Updated: 2025/01/25 17:44:28 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed::Fixed(const int value)
{
	this->_value = value * (1 << _fractional_bits);
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << _fractional_bits));
}

Fixed::~Fixed()
{}

Fixed &Fixed::operator=(const Fixed &obj)
{
	this->_value = obj.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}

Fixed Fixed::operator+(const Fixed &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed Fixed::operator-(const Fixed &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed Fixed::operator*(const Fixed &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

bool Fixed::operator>(const Fixed &obj) const
{
	if (this->toFloat() > obj.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &obj) const
{
	if (this->toFloat() < obj.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &obj) const
{
	if (this->toFloat() >= obj.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &obj) const
{
	if (this->toFloat() <= obj.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &obj) const
{
	if (this->toFloat() == obj.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &obj) const
{
	if (this->toFloat() != obj.toFloat())
		return (true);
	return (false);
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

int Fixed::toInt(void) const
{
	return (this->_value >> _fractional_bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fractional_bits));
}

int		Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
