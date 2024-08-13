# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 12:21:00 by yzaytoun          #+#    #+#              #
#    Updated: 2024/08/13 13:10:51 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ZombieHorde

INCLUDE = Zombie.hpp

SRC = main.cpp Zombie.cpp zombieHorde.cpp

CPPFLAGS := -Wall -Wextra -Werror -std=c++98 -I $(INCLUDE) -g

CXX := c++

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating..." $<
	$(CXX) $(CPPFLAGS) $(OBJ) -o $@

clean:
	@echo "Cleaning Object Files\n"
	@$(RM) $(OBJ)

fclean: clean
	@echo "Cleaning $(NAME)\n"
	@$(RM) $(NAME)

re: fclean all

.PHONY: re all fclean clean