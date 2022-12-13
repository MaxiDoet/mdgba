CC = gcc
CFLAGS = -Iinclude -Iinclude/system

src_files := src/md64.c src/system/system.c src/system/r4300.c

md64: $(src_files)
	$(CC) $(CFLAGS) $^ -o md64