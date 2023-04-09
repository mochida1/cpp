/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmochida <hmochida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:00:27 by hmochida          #+#    #+#             */
/*   Updated: 2023/04/09 16:59:35 by hmochida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain{
	public:
	Brain(void);
	Brain(const Brain & instance);
	Brain & operator=(const Brain & instance);
	~Brain(void);
	Brain(std::string serialIdea);

	const std::string* getIdeas(void) const;
	const std::string getIdeas(int ideaIdx) const;
	void printIdeas(void) const;
	void printIdeas(int idx) const;
	void setIdeas(const std::string * ideas);

	protected:
	private:
	std::string _ideas[100];
};

#endif //
