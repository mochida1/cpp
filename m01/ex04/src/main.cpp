/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:43:55 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 19:13:59 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include "Unsed.class.hpp"
#include "Parser.class.hpp"
#include <stdlib.h>

/* TESTS IF FILE EXISTS */
// int main(int argc, char *argv[])
// {
// 	Parser parsa(argc, argv);
// 	if (parsa.fileExists(argv[1]) == false)
// 	{
// 		std::cerr << "File " << argv[1] << " does not exists." << std::endl;
// 		exit (1);
// 		return (1);
// 	}
// 	else
// 	{
// 		std::cout << "ok!" << std::endl;
// 		exit (1);
// 	}
// }

/* Checks file extension */
// int main(int argc, char *argv[])
// {
// 	Parser parsa(argc, argv);
// 	std::string ext;

// 	ext = ".txt";
// 	if (parsa.checkFileExtension(1, ext) == false)
// 	{
// 		std::cerr << "File " << argv[1] << " extension does not match : " << ext << std::endl;
// 		exit (1);
// 		return (1);
// 	}
// 	else
// 	{
// 		std::cout << "ok!" << std::endl;
// 		exit (1);
// 	}
// }

/* Checks for  empty arguments */
// int main(int argc, char *argv[])
// {
	// Parser parsa(argc, argv);
	// std::string ext;

	// ext = ".txt";
	// if (parsa.checkEmptyArguments() == false)
	// {
	// 	std::cerr << "Found empty arguments" << std::endl;
	// 	exit (1);
	// 	return (1);
	// }
// 	else
// 	{
// 		std::cout << "ok!" << std::endl;
// 		exit (1);
// 	}
// }

void parse(int argc, char **argv)
{
	Parser parsa(argc, argv);

	if (parsa.checkArgc(3, 3) == false)
	{
		std::cerr << "invalid number" << std::endl;
		exit (1);
	}
	if (parsa.checkEmptyArguments() == false)
	{
		std::cerr << "Empty arguments found" << std::endl;
		exit (1);
	}
	if (parsa.fileExists(argv[1]) == false)
	{
		std::cerr << "File does not exist" << std::endl;
		exit (1);
	}
}

int main(int argc, char *argv[])
{
	parse(argc, argv);
	std::cout << argv[1] << "\t" << argv[2] << "\t" << argv[3] << std::endl;
	Unsed sedme((std::string) (argv[1]), (std::string) (argv[2]), (std::string) (argv[3]));

	std::cout << "infilename is: " << sedme.getInFileName() << std::endl;
	std::cout << "outfilename is : " << sedme.getOutFileName() << std::endl;

	sedme.openInFile();
	sedme.closeInFile();
	sedme.doTrFileContent();
	sedme.writeToOutFile();
}
