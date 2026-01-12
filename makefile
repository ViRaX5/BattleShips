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
# ============================================================

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

# ============================================================
# VALGRIND_STRESS_TEST:
stress: $(TARGET)
	@for i in $$(seq 1 1000); do \
		echo "=== run $$i ==="; \
		./$(TARGET) >/dev/null || exit 1; \
	done

vgloop: $(TARGET)
	@for i in $$(seq 1 100); do \
		echo "=== valgrind $$i ==="; \
		valgrind $(VGFLAGS) --error-exitcode=1 ./$(TARGET) >/dev/null 2>vg_$$i.log || exit 1; \
	done

# -------------------------------------------------------------
# in Ubuntu/Terminal: "./battleships > run.log 2>&1" ->
# ->   in dir to get logFile generated for test puposes
# = Redirect output to a file
# -------------------------------------------------------------
# COMMANDS (makeFile) :
# make clean
# make
# make valgrind

# make clean && make && ./battleships
# make vgloop     # 100 valgrind runs
# make stress     # 1000 normal runs

# -------------------------------------------------------------
# =============================================================