/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:23:52 by hmochida          #+#    #+#             */
/*   Updated: 2023/03/11 21:50:28 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PARSER_CLASS_HPP
# define PARSER_CLASS_HPP

#include <iostream>
#include <string>

class Parser {
	public:
		Parser();
		Parser(int argc, char **argv);
		~Parser();
		bool		setArgc(int argc)
		const int	getArgc(void);
		bool		checkArgc(int argc);
		bool		setArgv(char **argv);
		const char	**getArgv(void);
		bool		setFileExtension(std::string file_extension);
		std::string const &getFileExtension(void);
		bool		checkFileExtension(int argv_idx, std::string pattern);

	private:
		int			_argc;
		char		**_argv;
		int			_is_verbose;
		std::string	_file_extension;
};


#endif // PARSER_CLASS_HPP
