# QuickSetup MAakefile

CC       = gcc 
LIBS     = `pkg-config --cflags --libs gtk+-2.0 gmodule-export-2.0` 
INCLUDES = ./Include/QuickSetup.h ./Include/Callbacks.h ./Include/Scripts.h
SOURCES  = ./Source/QuickSetup.c ./Source/Callbacks.c ./Source/Scripts.c

QuickSetup : $(SOURCES) $(INCLUDES)
	$(CC) $(LIBS) -o QuickSetup $(SOURCES)

