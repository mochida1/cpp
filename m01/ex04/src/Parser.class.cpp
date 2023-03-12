/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:23:50 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 18:27:05 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.class.hpp"

Parser::Parser(void) {
	return ;
}
Parser::Parser(int argc, char **argv) : _argc(argc), _argv(argv){
	return ;
}

Parser::~Parser(void) {
	return ;
}

bool		Parser::setArgc(int argc) {
	this->_argc = argc;
	if (this->_argc == argc)
		return (true);
	return (false);
}

int	Parser::getArgc(void) {
	return (this->_argc);
}

bool		Parser::checkArgc(int argc_min, int argc_max) {
	if (this->_argc - 1 < argc_min)
		return (false);
	if (this->_argc - 1 > argc_max)
		return (false);
	return (true);
}

bool		Parser::setArgv(char **argv) {
	this->_argv = argv;
	if (this->_argv == argv)
		return (true);
	return (false);
}

char	**Parser::getArgv(void) {
	return (this->_argv);
}

bool		Parser::setFileExtension(std::string file_extension) {
	this->_file_extension = file_extension;
	if (this->_file_extension.compare(file_extension))
		return (false);
	return (true);
}

std::string const &Parser::getFileExtension(void) {
	return (this->_file_extension);
}

bool		Parser::checkFileExtension(int argv_idx, std::string pattern) {
	std::string	to_parse;
	int			foundAt;

	to_parse = (std::string) (this->_argv[argv_idx]);
	if (to_parse.size() <= pattern.size())
		return (false);
	foundAt = to_parse.find(pattern, 0);
	if (foundAt == -1)
		return (false);
	if (to_parse.size() != pattern.size() + foundAt)
		return (false);
	return (true);

}

bool		Parser::checkEmptyArguments(void) {
	std::string str;

	for (int idx = 0; idx < this->_argc; idx++)
	{
		str = (std::string) (this->_argv[idx]);
		if (str.size() == 0)
			return (false);
	}
	return (true);
}
bool		Parser::fileExists(char *path_to_file) {
	struct stat buffer;
	return (stat(path_to_file, &buffer) == 0);
}
