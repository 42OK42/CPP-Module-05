/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:30:03 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/06 17:02:42 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* createPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	struct FormType
	{
		const char* className;
		AForm* (*create)(const std::string&);
	};

	FormType forms[] =
	{
		{"ShrubberyCreationForm", createShrubberyForm},
		{"RobotomyRequestForm", createRobotomyForm},
		{"PresidentialPardonForm", createPardonForm}
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == forms[i].className)
		{
			AForm* form = forms[i].create(target);
			std::cout << "Intern creates " << forms[i].className << std::endl;
			return form;
		}
	}

	std::cout << "Error: Form name \"" << formName << "\" does not exist." << std::endl;
	return NULL;
}