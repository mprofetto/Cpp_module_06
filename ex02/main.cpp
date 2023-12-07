/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:38:52 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/07 12:44:44 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int		nbr;
	Base	*result;

	nbr = std::rand() % 3;
	switch (nbr)
	{
	case 0:
	{
		result = new(A);
		std::cout << "Base has generated a A object" << std::endl;
		return (result);
	}
	case 1:
	{
		result = new(B);
		std::cout << "Base has generated a B object" << std::endl;
		return (result);
	}
	case 2:
	{
		result = new(C);
		std::cout << "Base has generated a C object" << std::endl;
		return (result);
	}
	default:
		return (NULL);
	}
}

void	identify(Base *p)
{
	A	*A_ptr;
	B	*B_ptr;
	C	*C_ptr;

	A_ptr = dynamic_cast<A *>(p);
	if (A_ptr)
	{
		std::cout << "The object pointed to by p is a A object" << std::endl;
		return;
	}
	B_ptr = dynamic_cast<B *>(p);
	if (B_ptr)
	{
		std::cout << "The object pointed to by p is a B object" << std::endl;
		return;
	}
	C_ptr = dynamic_cast<C *>(p);
	if (C_ptr)
	{
		std::cout << "The object pointed to by p is a C object" << std::endl;
		return;
	}
}

void	identify(Base &p)
{
	A	A_ptr;
	B	B_ptr;
	C	C_ptr;

	try
	{
		A_ptr = dynamic_cast<A&>(p);
		std::cout << "The object pointed to by p is a A object" << std::endl;
		return;
	}
	catch(const std::exception& e)
	{
		try
		{
			B_ptr = dynamic_cast<B&>(p);
			std::cout << "The object pointed to by p is a B object" << std::endl;
			return;
		}
		catch(const std::exception& e)
		{
			try
			{
				C_ptr = dynamic_cast<C&>(p);
				std::cout << "The object pointed to by p is a C object" << std::endl;
				return;
			}
			catch(const std::exception& e)
			{
				std::cout << "The object pointed to by p is not a A,B or C object" << std::endl;
				return;
			}
		}
	}
}

int	main(void)
{
	srand((unsigned int)time(NULL));

	Base	*my_base = generate();

	identify(my_base);
	return (0);
}
