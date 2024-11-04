/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:29:15 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/04 17:41:56 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Intern someRandomIntern;

	// Test creation of a valid form
	AForm* robotomyForm = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
	if (robotomyForm)
	{
		std::cout << "Successfully created form: " << robotomyForm->getName() << std::endl;
		delete robotomyForm; 
	}

	// Test creation of another valid form
	AForm* shrubberyForm = someRandomIntern.makeForm("ShrubberyCreationForm", "home");
	if (shrubberyForm)
	{
		std::cout << "Successfully created form: " << shrubberyForm->getName() << std::endl;
		delete shrubberyForm;
	}

	// Test creation of another valid form
	AForm* pardonForm = someRandomIntern.makeForm("PresidentialPardonForm", "Alice");
	if (pardonForm)
	{
		std::cout << "Successfully created form: " << pardonForm->getName() << std::endl;
		delete pardonForm;
	}

	// Test creation of a form with an invalid name
	AForm* invalidForm = someRandomIntern.makeForm("InvalidForm", "Target");
	if (!invalidForm)
		std::cout << "Failed to create form with invalid name." << std::endl;
	return 0;
}