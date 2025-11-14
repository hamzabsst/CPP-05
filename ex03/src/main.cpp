/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:38 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/15 00:48:45 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << "Form created: " << rrf->getName() << std::endl;
			std::cout << "Sign grade: " << rrf->getSignGrade() << ", Execute grade: " << rrf->getExecGrade() << std::endl;
			delete rrf;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Intern intern;
		AForm* ppf;
		ppf = intern.makeForm("presidential pardon", "Hamza");
		if (ppf)
		{
			std::cout << "Form created: " << ppf->getName() << std::endl;
			std::cout << "Sign grade: " << ppf->getSignGrade() << ", Execute grade: " << ppf->getExecGrade() << std::endl;
			delete ppf;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
