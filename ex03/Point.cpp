/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:44:27 by amousaid          #+#    #+#             */
/*   Updated: 2025/01/26 15:44:35 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point() : _x(0), _y(0)
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::Point(const Point &obg) : _x(obg.getX()), _y(obg.getY())
{}

Point::~Point()
{}

Point Point::operator=(const Point &obg)
{
	return (Point(obg.getX().toFloat(), obg.getY().toFloat()));
}

Fixed Point::getX() const
{
	return (this->_x);
}

Fixed Point::getY() const
{
	return (this->_y);
}
