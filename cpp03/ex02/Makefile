NAME		= fragTrap
WFLAGS 		= -Wall -Werror -Wextra
CPPFLAGS	= -std=c++98 -O3 -I ./include/
DEBUG_FLAGS =
SOURCES		= $(wildcard ./src/*.cpp)
SOURCES		:= $(patsubst ./src/%,%, $(SOURCES))
OBJECTS		= $(addprefix ./objs/,$(SOURCES:.cpp=.o))
HEADERS 	= $(wildcard ./include/*.hpp)

ifdef REMOVE_W_FLAGS
	WFLAGS =
endif

ifdef DEBUG
		DEBUG_FLAGS := -g3 -O0
		CPPFLAGS := $(subst -O3,,$(CPPFLAGS))
endif

all: ./objs/ $(NAME)

./objs/:
	mkdir ./objs/

$(NAME): $(OBJECTS)
	c++ $(CPPFLAGS) $(DEBUG_FLAGS) $(WFLAGS) $(OBJECTS) -o $(NAME)

./objs/%.o: ./src/%.cpp $(HEADERS)
	c++ $(CPPFLAGS) $(DEBUG_FLAGS) $(WFLAGS) -c $< -o $@

clean:
	rm -rf ./objs/

fclean: clean
	rm -rf $(NAME)

re: fclean all
