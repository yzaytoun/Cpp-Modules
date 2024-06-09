# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 12:21:00 by yzaytoun          #+#    #+#              #
#    Updated: 2024/06/08 17:54:12 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = PhoneBook.cpp main.cpp Contact.cpp

CXX := c++

INC = -IPhoneBook.hpp -IContact.hpp

CPPFLAGS := -Wall -Wextra -Werror -std=c++98 $(INC) -g

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating..." $@
	@$(CXX) $(CPPFLAGS) $(OBJ) -o $@

clean:
	@echo "Cleaning Object Files\n"
	@$(RM) $(OBJ)

fclean: clean
	@echo "Cleaning $(NAME)\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY: re all fclean clean