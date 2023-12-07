/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:38:52 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/07 11:11:05 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	unsigned long nbr = 42;
	uintptr_t	ptr = nbr;
	uintptr_t	ptr2;

	std::cout << "nbr: " << nbr << std::endl;
	std::cout << "nbr in uintptr_t: " << ptr << std::endl;

	Data	*my_data = Serializer::deserialize(ptr);
	ptr2 = Serializer::serialize(my_data);
	std::cout << "nbr in uintptr_t 2: " << ptr2 << std::endl;
	return (0);
}
