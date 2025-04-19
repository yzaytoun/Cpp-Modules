# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 12:21:00 by yzaytoun          #+#    #+#              #
#    Updated: 2025/01/11 19:16:10 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

INC = -IBureaucrat.hpp -IAForm.hpp -IShrubberyCreationForm.hpp -IPresidentialPardonForm.hpp -IRobotomyRequestForm.hpp

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp

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