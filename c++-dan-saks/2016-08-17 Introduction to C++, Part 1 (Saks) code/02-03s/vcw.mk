# make xr using Visual Studio
# compile as C for Windows
# Copyright (c) 2016 by Dan Saks
# See _readme.txt

SRC = .c    # source
OBJ = .obj  # object
EXE = .exe  # executable
MAP = .map  # link map
ASM = .asm  # assembler

CC = cl
CFLAGS = /c /D_CRT_SECURE_NO_WARNINGS /W4
AFLAGS = $(CFLAGS) /FA

LL = $(CC)
LFLAGS = /Fm

$(OBJ)$(EXE):
	$(LL) $(LFLAGS) $**

$(SRC)$(OBJ):
	$(CC) $(CFLAGS) $<

$(SRC)$(ASM):
	$(CC) $(AFLAGS) $<

xr$(EXE): xr$(OBJ)

xr$(OBJ):

clean:
	cmd /c del *.bak *$(EXE) *$(OBJ) *$(MAP) *$(ASM)

