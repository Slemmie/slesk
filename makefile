CXX_FLAGS = -std=c++17 -Wshadow -Wall
CXX_RELEASE_FLAGS = -O2
CXX_DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

modules = ./src/modules/
MODULE_SRC = $(modules)dummy/*.cpp
SRC = ./src/*.cpp $(MODULE_SRC)
INCLUDE = -I ./src/

all: release export

export:
	if [ ! -d "/opt/slesk/" ]; then mkdir /opt/slesk/; fi;
	@if [ ! -f "./slesk" ]; then echo "missing executable 'slesk'"; fi;
	cp ./slesk /opt/slesk/slesk;

release:
	g++ $(CXX_FLAGS) $(SRC) -o slesk $(CXX_RELEASE_FLAGS) $(INCLUDE)

debug:
	g++ $(CXX_FLAGS) $(SRC) -o slesk $(CXX_DEBUG_FLAGS) $(INCLUDE)
