#  Macros
CC 	= gcc
CFLAGS 	= -g
SOURCE 	= lab02.c
OBJECT  = $(SOURCE:.c=.o)
HEADER 	= 
TARGET 	= lab02

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
