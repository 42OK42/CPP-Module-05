/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:29:15 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/04 16:53:36 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat alice("Alice", 160); // Bureaucrat with too low a grade to sign

		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Alice");

		std::cout << "Testing ShrubberyCreationForm:" << std::endl;
		bob.signForm(shrubbery);
		bob.executeForm(shrubbery);

		std::cout << "\nTesting RobotomyRequestForm:" << std::endl;
		bob.signForm(robotomy);
		bob.executeForm(robotomy);

		std::cout << "\nTesting PresidentialPardonForm:" << std::endl;
		bob.signForm(pardon);
		bob.executeForm(pardon);

		std::cout << "\nTesting with Bureaucrat with insufficient grade:" << std::endl;
		alice.signForm(shrubbery);
		alice.executeForm(shrubbery);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}