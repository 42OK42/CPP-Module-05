/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:29:15 by okrahl            #+#    #+#             */
/*   Updated: 2024/11/04 15:48:36 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		Form taxForm("Tax Form", 3, 5);

		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;

		Bureaucrat alice("Alice", 4);
		alice.signForm(taxForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}