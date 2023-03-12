/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:43:55 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 17:00:49 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>
#include "Unsed.class.hpp"

/*      ./unsed <file> <string to replace> <stringt that replaces>     */
// int main (int argc, char *argv[])
// {
// 	(void) (argc);
// 	(void) (argv);
// 	std::fstream fs;
// 	std::fstream ofs;
// 	ofs.open("teste.txt", std::fstream::out);
// 	ofs << "testing" << std::endl;
// 	fs.open("teste.txt", std::fstream::in | std::fstream::out);
// 	return (0);
// }


int main(int argc, char *argv[])
{
	(void) (argc);
	std::cout << argv[1] << "\t" << argv[2] << "\t" << argv[3] << std::endl;
	Unsed sedme((std::string) (argv[1]), (std::string) (argv[2]), (std::string) (argv[3]));

	std::cout << "infilename is: " << sedme.getInFileName() << std::endl;
	std::cout << "outfilename is : " << sedme.getOutFileName() << std::endl;

	sedme.openInFile();
	std::cout << sedme.isInFileOpen() << std::endl;
	sedme.closeInFile();
	sedme.doTrFileContent();
	sedme.writeToOutFile();
}
