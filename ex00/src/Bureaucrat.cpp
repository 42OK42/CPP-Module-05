/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:29:19 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/04 13:29:20 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
}

// Getters
const std::string& Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

// Increment and Decrement
void Bureaucrat::incrementGrade() {
	if (grade <= 1) throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decrementGrade() {
	if (grade >= 150) throw GradeTooLowException();
	++grade;
}

// Overload << operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}