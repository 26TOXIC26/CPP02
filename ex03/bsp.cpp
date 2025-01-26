/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 10:44:45 by amousaid          #+#    #+#             */
/*   Updated: 2025/01/26 17:00:58 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

float traingleArea(Point const a, Point const b, Point const c)
{
	float Area = std::abs(((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
						+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
						+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2);
	return Area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	float A = traingleArea(a, b, c);
	float A1 = traingleArea (a, b, point);
	float A2 = traingleArea (b, c, point);
	float A3 = traingleArea (c, a, point);
	if (A == (A1 + A2 + A3) && A1 > 0 && A2 > 0 && A3 > 0)
		return true;
	return false;
}

