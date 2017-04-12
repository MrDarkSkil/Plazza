
ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[1;31m"
YELLOW		=	"\033[1;33m"
BLUE		=	"\033[1;34m"

CC              =       g++ -g -g3

RM              =       rm -f

NAME            =       plazza

CXXFLAGS	+=	-I./includes
CXXFLAGS	+=	-Wextra -Wall -W

SRC             =       src/main.cpp

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
