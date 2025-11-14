/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbousset <hbousset@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:03:20 by hbousset          #+#    #+#             */
/*   Updated: 2025/11/14 23:43:59 by hbousset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

	outfile << "        *" << std::endl;
	outfile << "       ***" << std::endl;
	outfile << "      *****" << std::endl;
	outfile << "     *******" << std::endl;
	outfile << "    *********" << std::endl;
	outfile << "   ***********" << std::endl;
	outfile << "  *************" << std::endl;
	outfile << " ***************" << std::endl;
	outfile << "        |||" << std::endl;
	outfile << "        |||" << std::endl;

	outfile.close();
	std::cout << "Shrubbery has been created in " << filename << std::endl;
}
