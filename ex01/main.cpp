/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:28:32 by bcastelo          #+#    #+#             */
/*   Updated: 2025/01/19 16:57:00 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <numeric>
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
			print_comment("Going to add some numbers to test addNumber member function");
			try
			{
				std::cout << small;
				print_comment("Adding number 42");
				small.addNumber(42);
				std::cout << small;
				print_comment("Adding number 24");
				small.addNumber(24);
				std::cout << small;
				print_comment("Adding number 84");
				small.addNumber(84);
				std::cout << small;
				print_comment("Adding number 168");
				small.addNumber(168);
				std::cout << small;
				print_comment("Adding number 336");
				small.addNumber(336);
				std::cout << small;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
			print_comment("Destructors");
		}
		if (test == "range" || test == "all" || test == "ran*")
		{
			print_header("Testing range insertion member function");
			Span large(10000);
			std::vector<int> range(10000,100);
			std::vector<int> more(10,10);
			
			try
			{
				print_comment("Let's insert a large vector");
				std::cout << large;
				print_comment("Going to add a vector with 10000 numbers with value 100");
				large.addNumbers(range);
				std::ofstream fout("large.txt");
				if (fout.is_open())
				{
					fout << large;
					fout.close();
					print_comment("The class content was printed to file large.txt");
				}
				print_comment("Printing the result for shortest and largest span. They must be 0");
				std::cout << "Shortest span: " << large.shortestSpan() << std::endl;
				std::cout << "Largest span: " << large.longestSpan() << std::endl;
				print_comment("Trying to add a vector with 10 numbers");
				large.addNumbers(more);
				std::ofstream fout2("more.txt");
				if (fout2.is_open())
				{
					fout2 << large;
					fout2.close();
				}
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
			print_comment("Destructors");
		}
		if (test == "span" || test == "all" || test == "sp*")
		{
			print_header("Testing span functions with a large vector");
			Span large(10000);
			std::vector<int> range(10000);
			
			try
			{
				for (int i = 0; i < 10000; ++i)
					range[i] = i;
				print_comment("Let's insert a large vector");
				std::cout << large;
				print_comment("Going to add a vector with 10000 numbers with value 100");
				large.addNumbers(range);
				std::ofstream fout("large_span.txt");
				if (fout.is_open())
				{
					fout << large;
					fout.close();
					print_comment("The class content was printed to file large_span.txt");
				}
				print_comment("Printing the result for shortest and largest span. They must be:");
				print_comment("Shortest: 1 Largest: 9999");
				std::cout << "Shortest span: " << large.shortestSpan() << std::endl;
				std::cout << "Largest span: " << large.longestSpan() << std::endl;
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
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
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
	std::cout << "range - Testing range insertion member function" << std::endl;
	std::cout << "span - Testing span functions with a large vector" << std::endl;
	std::cout << "all - Run all tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Usage example:" << std::endl;
	std::cout << std::endl;
	std::cout << prog_name << " swap" << std::endl;
	std::cout << std::endl;
}