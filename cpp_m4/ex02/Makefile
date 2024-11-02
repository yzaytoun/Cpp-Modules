# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 12:21:00 by yzaytoun          #+#    #+#              #
#    Updated: 2024/11/02 15:41:05 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

INC = -IAAnimal.hpp -IDog.hpp -ICat.hpp -IBrain.hpp

SRC = main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp

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