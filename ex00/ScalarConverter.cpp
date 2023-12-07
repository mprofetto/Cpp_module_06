/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:11:11 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/07 10:06:02 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	nbr_is_valid(std::string nbr)
{
	std::string::iterator	it;

	it = nbr.begin();
	while (*it == ' ' && it != nbr.end())
		++it;
	if (it == nbr.end() || isdigit(*it) == 0)
		return (0);
	if (isdigit(*it) == 1 || *it == '+' || *it == '-')
		++it;
	while (isdigit(*it) == 1 && it != nbr.end())
		++it;
	if (it == nbr.end())
		return (1);
	if (*it == 'f')
	{
		++it;
		if (it != nbr.end())
			return (0);
		else
			return (1);
	}
	if (*it != '.')
		return (0);
	++it;
	while (isdigit(*it) == 1 && it != nbr.end())
		++it;
	if (it == nbr.end())
		return (1);
	if (*it == 'f')
		++it;
	if (it == nbr.end())
		return (1);
	return (0);
}

bool	nbr_is_zero(std::string nbr)
{
	std::string::iterator	it;

	it = nbr.begin();
	while (*it == ' ' && it != nbr.end())
		++it;
	if (it == nbr.end() || *it != '0')
		return (0);
	if (*it == '0' || *it == '+' || *it == '-')
		++it;
	while (*it == '0' && it != nbr.end())
		++it;
	if (it == nbr.end())
		return (1);
	if (*it == 'f')
	{
		++it;
		if (it != nbr.end())
			return (0);
	}
	if (*it != '.')
		return (0);
	++it;
	while (*it == '0' && it != nbr.end())
		++it;
	if (it == nbr.end())
		return (1);
	if (*it == 'f')
		++it;
	if (it == nbr.end())
		return (1);
	return (0);
}

bool	is_displayable(int	nbr)
{
	if (nbr < 32 || nbr > 126)
		return (0);
	return (1);
}

bool	is_char(long int nbr)
{
	if (nbr > CHAR_MAX || nbr < CHAR_MIN)
		return (0);
	return (1);
}

bool	is_integer(long int nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

bool	is_float(double nbr)
{
	if ((nbr > FLT_MAX && nbr != INFINITY) || (nbr < FLT_MIN && nbr != -INFINITY))
		return (0);
	return (1);
}

void	display_char(long int nbr)
{
	char	c;

	if (is_displayable(nbr) == 0)
		std::cout << "char: Non displayable\n";
	else if (is_char(nbr) == 0)
		std::cout << "char: impossible\n";
	else
	{
		c = static_cast<char>(nbr);
		std::cout << "char: \'" << c << "\'" << std::endl;
	}
}

void	display_int(long int nbr)
{
	int	i;

	if (is_integer(nbr) == 0)
		std::cout << "int: impossible\n";
	else
	{
		i = static_cast<int>(nbr);
		std::cout << "int: " << i << std::endl;
	}
}

void	display_float(double nbr)
{
	float	f;

	if (is_float(nbr) == 0)
		std::cout << "float: impossible\n";
	else
	{
		f = static_cast<float>(nbr);
		std::cout << "float: " << f;
		if (f - static_cast<int>(f) == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

void	display_double(double nbr)
{
	std::cout << "double: " << nbr;
	if (nbr - static_cast<long int>(nbr) == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert(std::string str)
{
	long int	int_nbr;
	double		double_nbr;

	if (nbr_is_valid(str) == 0)
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}
	int_nbr = strtol(str.c_str(), NULL, 10);
	if (int_nbr == 0 && nbr_is_zero(str) == 0)
		std::cout << "char: impossible\nint: impossible\n";
	else
	{
		display_char(int_nbr);
		display_int(int_nbr);
	}
	double_nbr = strtod(str.c_str(), NULL);
	if (double_nbr == 0 && nbr_is_zero(str) == 0)
		std::cout << "float: impossible\ndouble: impossible\n";
	else
	{
		display_float(double_nbr);
		display_double(double_nbr);
	}

}
