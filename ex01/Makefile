NAME= PhoneBook

CFLAGS= -Wall -Werror -Wextra -std=c++98 -g

SRCS=Contact.cpp PhoneBook.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
