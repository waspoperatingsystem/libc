CC ?= cc
HOSTCC ?= cc
AR ?= ar

INCLUDE = $(PWD)/include
SRC = $(PWD)/src
BUILD = $(PWD)/build
INT_CFLAGS = -I$(INCLUDE) -Ofast -g0 -pipe

OBJ = $(SRC)/abort.o \
	$(SRC)/memmove.o \
	$(SRC)/strlen.o

all: libc.a

create_build: clean
	mkdir -p $(BUILD)

.c.o:
	$(CC) -MD -c $< -o $@ -std=gnu18 $(CPPFLAGS) $(INT_CFLAGS) $(CFLAGS)
 
.S.o:
	$(CC) -MD -c $< -o $@ $(CPPFLAGS) $(INT_CFLAGS) $(CFLAGS)

libc.a: create_build $(OBJ)
	$(AR) rcs $(BUILD)/$@ $(OBJ)

clean:
	rm -f $(OBJ)
	rm -rf $(BUILD)
