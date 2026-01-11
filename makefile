# ============================================================
# Battleships - Makefile (build / run / valgrind)
# ============================================================
                                                            
#    ▄▄▄               ▄▄         ▄▄▄▄▄                       
#   ██▀▀█▄       █▄  █▄ ██       ██▀▀▀▀█▄ █▄                  
#   ██ ▄█▀      ▄██▄▄██▄██       ▀██▄  ▄▀ ██    ▀▀            
#   ██▀▀█▄ ▄▀▀█▄ ██  ██ ██ ▄█▀█▄   ▀██▄▄  ████▄ ██ ████▄ ▄██▀█
# ▄ ██  ▄█ ▄█▀██ ██  ██ ██ ██▄█▀ ▄   ▀██▄ ██ ██ ██ ██ ██ ▀███▄
# ▀██████▀▄▀█▄██▄██ ▄██▄██▄▀█▄▄▄ ▀██████▀▄██ ██▄██▄████▀█▄▄██▀
#                                                  ██         
#                                                  ▀          
# Dor Mandel;      ID : 315313825
# Amit Lachmann;   ID : 207448267
CXX      := g++
TARGET   := battleships

# Auto-find cpp files (root + src/)
SRCS     := $(wildcard *.cpp) $(wildcard src/*.cpp)
OBJS     := $(SRCS:.cpp=.o)

# Flags
CXXFLAGS := -std=c++17 -Wall -Wextra -g
LDFLAGS  :=

# Valgrind settings
VGFLAGS  := --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1

.PHONY: all run valgrind clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind $(VGFLAGS) ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
