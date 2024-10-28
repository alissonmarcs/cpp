NAME		= ex01
WFLAGS 		= -Wall -Werror -Wextra
CPPFLAGS	= -std=c++98 -O3 -I ./include/
DEBUG_FLAGS =
SOURCES_CPP	= $(wildcard ./src/*.cpp)
SOURCES_TPP	= $(wildcard ./src/*.tpp)
SOURCES		= $(SOURCES_CPP) $(SOURCES_TPP)
SOURCES		:= $(patsubst ./src/%,%, $(SOURCES))
OBJECTS		= $(addprefix ./.objs/,$(SOURCES:.cpp=.o))
OBJECTS		+= $(addprefix ./.objs/,$(SOURCES:.tpp=.o))
HEADERS 	= $(wildcard ./include/*.hpp)

ifdef REMOVE_W_FLAGS
    WFLAGS =
endif

ifdef DEBUG
        DEBUG_FLAGS := -g3 -O0
        CPPFLAGS := $(subst -O3,,$(CPPFLAGS))
endif

ifdef REMOVE_STD
        CPPFLAGS := $(subst -std=c++98,,$(CPPFLAGS))
endif

CYAN = \033[36m
RESET = \033[0m

all: ./.objs/ $(NAME)

./.objs/:
	@mkdir ./.objs/

$(NAME): $(OBJECTS)
	@printf "$(CYAN)Compiling...$(RESET)\n" 
	@c++ $(CPPFLAGS) $(DEBUG_FLAGS) $(WFLAGS) $(OBJECTS) -o $(NAME)
	@printf "$(CYAN)Target ./$(NAME) done$(RESET)\n" 

./.objs/%.o: ./src/%.cpp $(HEADERS)
	@c++ $(CPPFLAGS) $(DEBUG_FLAGS) $(WFLAGS) -c $< -o $@

./.objs/%.o: ./src/%.tpp $(HEADERS)
	@c++ -x c++ $(CPPFLAGS) $(DEBUG_FLAGS) $(WFLAGS) -c $< -o $@

clean:
	@rm -rf ./.objs/

fclean: clean
	@rm -rf $(NAME)

re: fclean all