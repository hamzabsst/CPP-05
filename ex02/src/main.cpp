/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:38 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/15 00:18:35 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 130);
		ShrubberyCreationForm shrub("home");
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat alice("Alice", 40);
		RobotomyRequestForm robot("Bender");
		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm pardon("Criminal");
		intern.signForm(pardon);
		intern.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
