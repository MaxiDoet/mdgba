CC = gcc
CFLAGS = -Iinclude -Iinclude/device

src_files := src/mdds.c src/device/device.c

md64: $(src_files)
	$(CC) $(CFLAGS) $^ -o mdds