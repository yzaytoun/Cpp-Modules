# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 12:21:00 by yzaytoun          #+#    #+#              #
#    Updated: 2025/01/10 18:58:42 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

INC = -IBureaucrat.hpp

SRC = main.cpp Bureaucrat.cpp

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