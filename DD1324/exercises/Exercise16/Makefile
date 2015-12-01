#  Macros
CC 	= gcc
CFLAGS 	= -g
SOURCE 	= dynamicmemory.c
OBJECT  = $(SOURCE:.c=.o)
HEADER 	= 
TARGET 	= dynamicmemory

# Major targets
.PHONEY: all
 all: $(TARGET)

$(TARGET): $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -o $(TARGET)

# Minor targets
$(OBJECT): $(SOURCE) $(HEADER)
	$(CC) -c $(CFLAGS) $(SOURCE)

.PHONEY: clean
clean:
	rm $(TARGET) $(OBJECT)
