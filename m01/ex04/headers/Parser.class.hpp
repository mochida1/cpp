/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:23:52 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/12 18:43:09 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PARSER_CLASS_HPP
# define PARSER_CLASS_HPP

#include <iostream>
#include <string>
#include <sys/stat.h>

class Parser {
	public:
		Parser(void);
		Parser(int argc, char **argv);
		~Parser(void);
		bool		setArgc(int argc);
		int			getArgc(void);
		bool		checkArgc(int argc_min, int argc_max);
		bool		setArgv(char **argv);
		char		**getArgv(void);
		bool		setFileExtension(std::string file_extension);
		std::string	const &getFileExtension(void);
		bool		checkFileExtension(int argv_idx, std::string pattern);
		bool		checkEmptyArguments(void);
		bool		fileExists(char *path_to_file);

	private:
		int			_argc;
		char		**_argv;
		int			_is_verbose;
		std::string	_file_extension;
};


#endif // PARSER_CLASS_HPP
