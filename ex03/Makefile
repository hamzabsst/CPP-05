NAME	= program
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS 	= 	src/main.cpp \
			src/Bureaucrat.cpp \
			src/AForm.cpp \
			src/PresidentialPardonForm.cpp \
			src/RobotomyRequestForm.cpp \
			src/ShrubberyCreationForm.cpp \
			src/Intern.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
