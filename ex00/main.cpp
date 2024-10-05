/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:35:04 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/05 18:25:27 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

#define WIDTH 60

void	print_border( void );

void	print_left(int space);

void	print_rigth(int space);

int	calculate_space(int header_len);

int	calculate_right_space(int header_len);

void	print_header(std::string header);

void	print_comment(std::string comment);

void	print_help(char *prog_name);

int	main(int argc, char **argv)
{
	std::string test;
	
	for (int i = 1; i < argc; i++)
	{
		test = argv[i];
		if (test == "h" || test == "help")
		{
			print_help(argv[0]);
			return (0);
		}
		if (test == "correct" || test == "all" || test == "cor*")
		{
			print_header("Testing correct use of easyfind function");
            std::vector<int> v;

            v.push_back(1);
            v.push_back(2);
            v.push_back(3);
            try
            {
                easyfind(v, 3);
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
            }
		}
	}
	if (argc == 1)
	{
		print_help(argv[0]);
	}
	return (0);
}

void	print_border( void )
{
	for (int i = 0; i < WIDTH; i++)
		std::cout << "*";
	std::cout << std::endl;
}

void	print_left(int space)
{
	std::cout << "*";
	for (int i = 0; i < space; i++)
		std::cout << " ";
}

void	print_rigth(int space)
{
	for (int i = 0; i < space; i++)
		std::cout << " ";
	std::cout << "*" << std::endl; 
}

int	calculate_space(int header_len)
{
	int	space;

	space = (WIDTH - header_len - 2) / 2;
	return (space);
}

int	calculate_right_space(int header_len)
{
	int	space;

	space = (WIDTH - header_len - 2) / 2;
	space += (WIDTH - header_len - 2) % 2;
	return (space);
}

void	print_header(std::string header)
{
	int space;

	space = calculate_space(header.size());
	print_border();
	print_left(space);
	std::cout << header;
	space = calculate_right_space(header.size());
	print_rigth(space);
	print_border();
}

void	print_comment(std::string comment)
{
	int space;

	space = calculate_space(comment.size());
	std::cout << std::endl;
	print_left(space);
	std::cout << comment;
	space = calculate_right_space(comment.size());
	print_rigth(space);
	std::cout << std::endl;
}

void	print_help(char *prog_name)
{
	print_header("Options and usage");
	std::cout << "Options:" << std::endl;
	std::cout << std::endl;
	std::cout << "correct - Testing correct use of easyfind function" << std::endl;
	std::cout << "all - Run all tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Usage example:" << std::endl;
	std::cout << std::endl;
	std::cout << prog_name << " correct" << std::endl;
	std::cout << std::endl;
}