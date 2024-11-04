/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:41:21 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/04 15:46:42 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw() {
				return "Form grade is too high!";
			}
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw() {
				return "Form grade is too low!";
			}
		};

		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& bureaucrat);

	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif