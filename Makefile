NAME=ansi-demo	

# since $(NAME) isn't an object nor
# a file until it's created:
#.DEFAULT_GOAL := $(NAME)

# enable full parallelism (because I can)
MAKEFLAGS+= -j

# but first rule is the .DEFAULT_GOAL
all: $(NAME)


# $(wildcard dir1/*.cpp)
SOURCES= \
	$(wildcard *.cpp)


DEFINES=\
	-D__PROGNAME__=ansi-demo \
	-D__PROGVER__=0.5

INCLUDES=-I.

CXXFLAGS= \
	-fwhole-program -flto \
	-O3 \
	-std=c++11 \
	-W \
	-Wall -Wextra \
	$(DEFINES) \
	$(INCLUDES)

LDFLAGS=

LIBS  =

OBJS=$(SOURCES:.cpp=.o)

$(NAME): $(OBJS)
	g++ $(OBJS) $(LDFLAGS) -o $(NAME) $(LIBS)

clean:
	@rm -v $(OBJS)
