CC ?= cc
HOSTCC ?= cc
AR ?= ar

INCLUDE = $(PWD)/include
SRC = $(PWD)/src
BUILD = $(PWD)/build
INT_CFLAGS = -I$(INCLUDE) -std=gnu18 -Ofast -g0 -pipe

OBJ = $(SRC)/abort.o \
	$(SRC)/memcmp.o \
	$(SRC)/memcpy.o \
	$(SRC)/memmove.o \
	$(SRC)/memset.o \
	$(SRC)/printf.o \
	$(SRC)/putchar.o \
	$(SRC)/puts.o \
	$(SRC)/strlcat.o \
	$(SRC)/strlcpy.o \
	$(SRC)/strlen.o

all: libc.a

create_build: clean
	mkdir -p $(BUILD)

.c.o:
	$(CC) -MD -c $< -o $@ $(CPPFLAGS) $(INT_CFLAGS) $(CFLAGS)
 
.S.o:
	$(CC) -MD -c $< -o $@ $(CPPFLAGS) $(INT_CFLAGS) $(CFLAGS)

libc.a: create_build $(OBJ)
	$(AR) rcs $(BUILD)/$@ $(OBJ)

clean:
	rm -f $(OBJ)
	rm -rf $(BUILD)
