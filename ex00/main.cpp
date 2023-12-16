/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:38:52 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/16 16:21:40 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc >= 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "No argument given" << std::endl;
	return (0);
}
