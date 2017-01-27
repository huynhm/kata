
CC = g++
CFLAGS  = -g -Wall


# build executable printroman from arabicroman.cpp
default: all

# To create the executable file count we need the object files
#
all: 
	$(CC) $(CFLAGS) arabicroman.cpp -o printroman 


# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	rm -f printroman