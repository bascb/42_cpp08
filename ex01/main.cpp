/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:28:32 by bcastelo          #+#    #+#             */
/*   Updated: 2024/10/13 10:20:55 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

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
        if (test == "constructors" || test == "all" || test == "cons*")
		{
			print_header("Testing class constructors");
			Span correct(100000);
			Span copied(correct);
			Span assigned(15);

			assigned = copied;
			print_comment("Print N values");
			std::cout << "N values - correct copied assigned " << correct.getN() << " " << copied.getN() << " " << assigned.getN() << " " << std::endl;
			print_comment("Add 500 numbers to correct, 50 to assigned and makes a new copy of correct");
			for (unsigned int i = 0; i < 500; i++)
				correct.addNumber(42);
			for (unsigned int i = 0; i < 50; i++)
				assigned.addNumber(42);
			std::cout << "numbers size - correct assigned " << correct.getSize() << " " << assigned.getSize() << " " << std::endl;
			Span new_copy(correct);
			assigned = correct;
			std::cout << "numbers size - correct copied assigned " << correct.getSize() << " " << new_copy.getSize() << " " << assigned.getSize() << " " << std::endl;
			print_comment("Destructors");
		}
		if (test == "add" || test == "all" || test == "a*")
		{
			print_header("Testing addNumber member function");
			Span small(3);

			print_comment("Adding numbers");
			try
			{
				std::cout << "Size before adding 42: " << small.getSize() << std::endl;
				small.addNumber(42);
				std::cout << "Size before adding 24: " << small.getSize() << std::endl;
				small.addNumber(24);
				std::cout << "Size before adding 84: " << small.getSize() << std::endl;
				small.addNumber(84);
				std::cout << "Size before adding 168: " << small.getSize() << std::endl;
				small.addNumber(168);
				std::cout << "Size before adding 336: " << small.getSize() << std::endl;
				small.addNumber(336);
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
			print_comment("Destructors");
		}
	}
	if (argc == 1 || test == "all")
	{
		print_header("Subject example");
        
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
    std::cout << "constructors - Testing class constructors" << std::endl;
	std::cout << "add - Testing addNumber member function" << std::endl;
	std::cout << "all - Run all tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Usage example:" << std::endl;
	std::cout << std::endl;
	std::cout << prog_name << " swap" << std::endl;
	std::cout << std::endl;
}