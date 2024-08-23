NAME		= megaphone
WFLAGS 		= -Wall -Werror -Wextra -Werror=unused-variable \
			-Werror=unused-parameter -Werror=unused-function
CPPFLAGS	= -std=c++98 -O3
DEBUG_FLAGS =
SOURCES		:= megaphone.cpp
OBJECTS		= $(addprefix ./objs/,$(SOURCES:.cpp=.o))

ifdef REMOVE_W_FLAGS
	WFLAGS =
endif

ifdef ADD_DEBUG_FLAGS
		DEBUG_FLAGS := -g3 -O0
		CPPFLAGS := $(subst -O3,,$(CPPFLAGS))
endif

all: ./objs/ $(NAME)

./objs/:
	mkdir ./objs/

$(NAME): $(OBJECTS)
	c++ $(CPPFLAGS) $(DEBUG_FLAGS) $(WFLAGS) $(OBJECTS) -o $(NAME)

./objs/%.o: megaphone.cpp
	c++ $(CPPFLAGS) $(DEBUG_FLAGS) $(WFLAGS) -c $< -o $@

clean:
	rm -rf ./objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all
