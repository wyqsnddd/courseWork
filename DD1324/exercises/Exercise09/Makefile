# This is a general-purpose Makefile which you can use
# to automate compiling and linking in your single or
# multi-file projects.

# project name (generate executable with this name)
TARGET   = file_writer

# Compiler and compiler flags (CFLAGS)
CC       = gcc
CFLAGS   = -g -Wall

# The linker and linking flags
LINKER   = gcc -o
LFLAGS   = -Wall -lm

# Define the sub-directories where files should be
SRCDIR   = .
OBJDIR   = .
BINDIR   = .

# Define the source files, object files, header files
SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


# link the object files to make an executable
$(BINDIR)/$(TARGET): $(OBJECTS)
	@echo $(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "  Linking " $@ " executable complete!"

# compile the various object files
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo $(CC) $(CFLAGS) -c $< -o $@
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "  Compiled "$<" successfully!"

# clean up the objects
.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "  Cleaned up object files!"
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "  Executable removed!"

.PHONEY: all
all: $(BINDIR)/$(TARGET)