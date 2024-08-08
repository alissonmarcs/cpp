NAME		= phone_book
CPPFLAGS	= -std=c++98 -Wall -Werror -Wextra -O3
SOURCES		= main.cpp Contact.cpp PhoneBook.cpp utils.cpp
OBJECTS		= $(addprefix ./objs/,$(SOURCES:.cpp=.o))

ifdef REMOVE_W_FLAGS
	CPPFLAGS := $(subst -Wall -Werror -Wextra,,$(CPPFLAGS))
endif

ifdef ADD_DEBUG_FLAGS
	CPPFLAGS := $(subst -O3,-g3 -O0,$(CPPFLAGS))
endif

all: ./objs/ $(NAME)

./objs/:
	mkdir ./objs/

$(NAME): $(OBJECTS)
	c++ $(CPPFLAGS) $(OBJECTS) -o $(NAME)

./objs/%.o: ./src/%.cpp ./include/Contact.hpp ./include/PhoneBook.hpp
	c++ $(CPPFLAGS) -c $< -o $@ -I ./include/

clean:
	rm -rf ./objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all