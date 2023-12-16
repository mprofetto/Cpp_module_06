/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:11:11 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/16 16:20:36 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	nbr_is_valid(std::string nbr)
{
	std::string::iterator	it;

	it = nbr.begin();
	while (*it == ' ' && it != nbr.end())
		++it;
	if (it == nbr.end() || (isdigit(*it) == 0 && !(*it == '+' || *it == '-')))
		return (false);
	++it;
	while (isdigit(*it) != 0 && it != nbr.end())
		++it;
	if (it == nbr.end())
		return (true);
	if (*it == 'f')
	{
		++it;
		if (it != nbr.end())
			return (false);
		else
			return (true);
	}
	if (*it != '.')
		return (false);
	++it;
	while (isdigit(*it) != 0 && it != nbr.end())
		++it;
	if (it == nbr.end())
		return (true);
	if (*it == 'f')
		++it;
	if (it == nbr.end())
		return (true);
	return (false);
}

bool	nbr_is_zero(std::string nbr)
{
	std::string::iterator	it;

	it = nbr.begin();
	while (*it == ' ' && it != nbr.end())
		++it;
	if (it == nbr.end() || (isdigit(*it) == 0 && !(*it == '+' || *it == '-')))
		return (false);
	++it;
	while (*it == '0' && it != nbr.end())
		++it;
	if (it == nbr.end())
		return (true);
	if (*it == 'f')
	{
		++it;
		if (it != nbr.end())
			return (false);
	}
	if (*it != '.')
		return (false);
	++it;
	while (*it == '0' && it != nbr.end())
		++it;
	if (it == nbr.end())
		return (true);
	if (*it == 'f')
		++it;
	if (it == nbr.end())
		return (true);
	return (false);
}

bool	is_displayable(int	nbr)
{
	if (nbr < 32 || nbr > 126)
		return (0);
	return (1);
}

bool	int_convertion_failed(long int nbr, std::string str)
{
	if (nbr == 0 && nbr_is_zero(str) == 0)
		return (true);
	return (false);
}

bool	double_convertion_failed(double nbr, std::string str)
{
	if (nbr == 0 && nbr_is_zero(str) == 0)
		return (true);
	return (false);
}

bool	is_char(long int nbr)
{
	if (nbr > CHAR_MAX || nbr < 0)
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
	if ((nbr > FLT_MAX && nbr != INFINITY) || (nbr < -FLT_MAX && nbr != -INFINITY))
		return (false);
	return (true);
}

bool	nbr_is_special(std::string str)
{
	if (str.compare("nan") == 0 || str.compare("nanf") == 0
		|| str.compare("inf") == 0 || str.compare("-inf") == 0
		|| str.compare("inff") == 0 || str.compare("-inff") == 0)
		return (true);
	return (false);
}


void	display_char(long int nbr, std::string str)
{
	char	c;


	if (is_char(nbr) == 0 || int_convertion_failed(nbr, str) == true || nbr_is_special(str) == true)
		std::cout << "char: impossible\n";
	else if (is_displayable(nbr) == 0)
		std::cout << "char: Non displayable\n";
	else
	{
		c = static_cast<char>(nbr);
		std::cout << "char: \'" << c << "\'" << std::endl;
	}
}

void	display_int(long int nbr, std::string str)
{
	int	i;

	if (is_integer(nbr) == 0 || int_convertion_failed(nbr, str) == true || nbr_is_special(str) == true)
		std::cout << "int: impossible\n";
	else
	{
		i = static_cast<int>(nbr);
		std::cout << "int: " << i << std::endl;
	}
}

void	display_float(double nbr, std::string str)
{
	float	f;

	if ((is_float(nbr) == 0 || double_convertion_failed(nbr, str) == true) && nbr_is_special(str) == false)
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

void	display_double(double nbr, std::string str)
{
	if (double_convertion_failed(nbr, str) == true && nbr_is_special(str) == false)
		std::cout << "double: impossible\n";
	else
	{
		std::cout << "double: " << nbr;
		if (nbr - static_cast<long int>(nbr) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
}


bool	get_special_nbr(std::string str, long int *int_nbr, double *double_nbr)
{
	if (str.compare("nan") == 0 || str.compare("nanf") == 0)
	{
		*int_nbr = NAN;
		*double_nbr = NAN;
	}
	else if (str.compare("inf") == 0 || str.compare("inff") == 0)
	{
		*int_nbr = INFINITY;
		*double_nbr = INFINITY;
	}
	else if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
	{
		*int_nbr = -INFINITY;
		*double_nbr = -INFINITY;
	}
	else
		return (false);
	return (true);
}

void	ScalarConverter::convert(std::string str)
{
	long int	int_nbr;
	double		double_nbr;

	if (nbr_is_special(str) == true)
		get_special_nbr(str, &int_nbr, &double_nbr);
	else if (nbr_is_valid(str) == true)
	{
		int_nbr = strtol(str.c_str(), NULL, 10);
		double_nbr = strtod(str.c_str(), NULL);
	}
	else
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
		return;
	}
	display_char(int_nbr, str);
	display_int(int_nbr, str);
	display_float(double_nbr, str);
	display_double(double_nbr, str);
}
