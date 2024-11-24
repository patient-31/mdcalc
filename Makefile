# Define the target executable
TARGET := mdcalc

# Define the compiler and flags
C_COMPILER := gcc
CFLAGS := $(shell pkg-config --cflags sdl2) $(shell pkg-config --cflags SDL2_ttf)
LDFLAGS := $(shell pkg-config --libs sdl2) $(shell pkg-config --libs SDL2_ttf) -lm
FLAGS := -Wextra 
ADDSAN := -fsanitize=address

# Define source and object directories
SRC_DIR := source/
OBJ_DIR := object/

# Find all .c files in the source directory
SOURCE := $(wildcard $(SRC_DIR)*.c)

# Convert source files to object files
OBJECTS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))

# Linking command
LINK := $(C_COMPILER) $(FLAGS) $(ADDSAN) -o $(TARGET) $(OBJECTS) $(CFLAGS) $(LDFLAGS)


test: all


# Default rule to build the target executable
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	echo "CREATING EXECUTABLE..."
	$(LINK)

# Rule to compile source files into object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "COMPILING OBJECTS ($@)"
	$(C_COMPILER) $(FLAGS) $(ADDSAN) -c $< -o $@ $(CFLAGS)

# Rule to create the object directory
$(OBJ_DIR):
	echo "CREATING OBJECT DIRECTORY..."
	mkdir -p $(OBJ_DIR)

# Rule to clean up compiled files
clean:
	echo "REMOVING OBJECT FILES..."
	rm -rf $(OBJ_DIR) $(TARGET)

aptlibs:	
	sudo apt install libsdl2-dev
	sudo apt install libsdl2-ttf-dev
	
dnflibs:
	sudo dnf install SDL2-devel
	sudo dnf install SDL2_ttf-devel

pacmanlibs:
	sudo pacman -S sdl2
	sudo pacman -S sdl2_ttf

zypperlibs:
	sudo zypper install libSDL2-devel
	sudo zypper install libSDL2_ttf-devel

help:
	echo "Usage:"
	echo "  make [target]"
	echo ""
	echo "Targets:"
	echo "  all           Build the project"
	echo "  clean         Clean the project"
	echo "  aptlibs       Install SDL2 libraries on Debian-based distributions"
	echo "  dnflibs       Install SDL2 libraries on Fedora-based distributions"
	echo "  pacmanlibs    Install SDL2 libraries on Arch-based distributions"
	echo "  zypperlibs    Install SDL2 libraries on openSUSE"
	echo "  help          Display this help message"


# Phony targets
.PHONY: clean all help
.SILENT: