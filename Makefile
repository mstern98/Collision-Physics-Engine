C = gcc
CFLAGS = -c -Wall -g -Os 
LD = $(CC)

LDFLAGS = -lm 
TARGET = engine 

OBJECTS = $(patsubst %.c, %.o, $(shell find './src' -name "*.c"))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	        $(LD) -o $@ $^ $(LDFLAGS)

# You don't even need to be explicit here,
# # compiling C files is handled automagically by Make.
%.o: %.c
	$(CC) $(CFLAGS) $^ -o  $@ 

clean:
	rm $(TARGET) $(OBJECTS)
