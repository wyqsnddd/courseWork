#  Macros
CC 	= gcc
CFLAGS 	= -g -Wall
SOURCE 	= scope.c
OBJECT  = $(SOURCE:.c=.o)
HEADER 	= 
TARGET 	= myprogram

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
