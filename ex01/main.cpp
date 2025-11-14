/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:38 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/15 00:24:52 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat Meryem("Meryem", 3);
		Form formA("Tax", 5, 10);

		std::cout << Meryem << std::endl;
		std::cout << formA << std::endl;
		Meryem.signForm(formA);
		std::cout << formA << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
