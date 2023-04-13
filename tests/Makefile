CC=../x86_64-linux-musl-native/bin/gcc
CFLAGS=-I../include/ -D_FORTIFY_SOURCE=3 -static -O2

TARGETS=test_memcpy_static_write  \
	test_memcpy_dynamic_write  \
	test_memcpy_static_read    \
	test_memcpy_dynamic_read   \
	test_memmove_static_write  \
	test_memmove_dynamic_write \
	test_memmove_static_read   \
	test_memmove_dynamic_read  \
	test_memset_static_write   \
	test_memset_dynamic_write  \

.SILENT:

all: $(TARGETS) run

$(TARGETS): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGETS)
	$(foreach EXE, $(TARGETS), \
		./$(EXE) 1 2 3 4 5 6 7 8 9 0 >/dev/null && echo "$(EXE) OK" || echo "$(EXE) FAIL" ; \
	)

clean:
	$(foreach EXE, $(TARGETS), \
		rm -f ./$(EXE) \
	)

