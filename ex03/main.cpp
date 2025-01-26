/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:51:29 by amousaid          #+#    #+#             */
/*   Updated: 2025/01/26 16:57:28 by amousaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

int main( void ) {
	Point a(2, 4);
	Point b(2, 1);
	Point c(6, 2.5);
	Point point(2, 2);

	if (bsp(a, b, c, point))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;
	return 0;
}

