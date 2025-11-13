/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:38 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/13 17:52:28 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
	try
	{
		Bureaucrat a("Alice", 2);
		std::cout << a << std::endl;
		a.incGrade();
		std::cout << a << std::endl;
		a.incGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}
	return 0;
}
