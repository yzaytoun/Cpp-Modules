# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 12:21:00 by yzaytoun          #+#    #+#              #
#    Updated: 2024/09/20 20:20:32 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

INC = -IHarl.hpp

SRC = main.cpp Harl.cpp

CPPFLAGS := -Wall -Wextra -Werror -std=c++98 $(INC) -g

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

memcheck:
	valgrind -leak-check=full ./$(NAME)

re: fclean all

.PHONY: re all fclean clean