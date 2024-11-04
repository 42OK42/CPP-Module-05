/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:16:40 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/04 16:52:02 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	checkExecutionRequirements(executor);
	std::cout << "* Drilling noises *" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2) {
		std::cout << target << " has been robotomized successfully." << std::endl;
	}
	else
	{
		std::cout << "The robotomy failed on " << target << "." << std::endl;
	}
}