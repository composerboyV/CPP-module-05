	NAME =Bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

RM = rm -rf

MPATH = ./main.cpp ./AForm.cpp ./Bureaucrat.cpp ./GradeTooHighException.cpp \
			PresidentialPardonForm.cpp ./RobotomyRequestForm.cpp ./GradeTooLowException.cpp \
			./ShrubberyCreationForm.cpp ./Intern.cpp


OBJ_M = $(MPATH:.cpp=.o)

%.o:	%.cpp
		@${CC} ${CFLAGS} -c $< -o $@
		
$(NAME):		$(OBJ_M)
				@$(CC) $(OBJ_M) $(THREAD) -o $(NAME)
				@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			all

clean:
				@$(RM) $(OBJ_M)
				@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m
