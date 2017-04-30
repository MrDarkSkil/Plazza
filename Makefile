##
## Makefile for Plazza in /home/gastal_r/rendu/Plazza/
##
## Made by gastal_r
## Login   <remi.gastaldi@epitech.eu>
##
## Started on  Sat Apr 29 23:26:33 2017 gastal_r
## Last update Sun Apr 30 19:34:56 2017 gastal_r
##

ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[1;31m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"

CC              =       g++ -g -g3 -lpthread

RM              =       rm -f

NAME            =       plazza

CXXFLAGS	+=	-I./includes
CXXFLAGS	+=	-Wextra -Wall -W

SRC             =       src/main.cpp		\
			src/Orders.cpp		\
			src/Parser.cpp		\
			src/Process.cpp		\
			src/Thread.cpp		\
			src/Mutex.cpp		\
			src/Plazza.cpp		\
			src/NamedPipe.cpp	\
			src/Crypted.cpp

OBJ             =       $(SRC:.cpp=.o)

all             :	title $(NAME)

title		:
			@$(ECHO) $(YELLOW) [ $(TEAL)PLAZZA$(YELLOW) ] $(DEFAULT)

$(NAME)         :	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS) && \
			 $(ECHO) $(YELLOW)[$(GREEN)OK$(YELLOW)]$(BLUE) $(NAME) $(DEFAULT)  || \
			 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME) $(DEFAULT)

clean           :
			@rm -f $(OBJ)

fclean          :       clean
			@$(RM) $(NAME)

re              :       fclean all

.PHONNY         :       all clean fclean re

.cpp.o		:
			@$(CC) $(CXXFLAGS) -c $< -o $@  && \
			 $(ECHO) $(YELLOW)[$(GREEN)OK$(YELLOW)] $(BLUE)$< $(DEFAULT) || \
			 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)
