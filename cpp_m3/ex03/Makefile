# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 12:21:00 by yzaytoun          #+#    #+#              #
#    Updated: 2024/10/26 13:12:51 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

INC = -IClapTrap.hpp -IScavTrap.hpp -IFragTrap.hpp -IDiamondTrap.hpp

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

CPPFLAGS := -Wall -Wextra -Werror -std=c++98 $(INC) -g

CXX := c++

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating..." $@
	$(CXX) $(CPPFLAGS) $(OBJ) -o $@

clean:
	@echo "Cleaning Object Files\n"
	@$(RM) $(OBJ)

fclean: clean
	@echo "Cleaning $(NAME)\n"
	@$(RM) $(NAME)

memcheck:
	valgrind -leak-check=full ./$(NAME)

re: fclean all

.PHONY: re all fclean clean