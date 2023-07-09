CFLAGS=-I../include/ -D_FORTIFY_SOURCE=3 -static -O2

TARGETS= \
	test_fgets                   \
	test_bcopy_static_write      \
	test_bcopy_static_read       \
	test_bcopy_dynamic_read      \
	test_bcopy_dynamic_write     \
	test_bzero_dynamic_write     \
	test_bzero_static_write      \
	test_memcpy_static_write     \
	test_memcpy_dynamic_write    \
	test_memcpy_static_read      \
	test_memcpy_dynamic_read     \
	test_memcpy_overwrite_over   \
	test_memcpy_overwrite_under  \
        test_mempcpy_static_write    \
	test_mempcpy_dynamic_write   \
	test_mempcpy_static_read     \
	test_mempcpy_dynamic_read    \
	test_memmove_static_write    \
	test_memmove_dynamic_write   \
	test_memmove_static_read     \
	test_memmove_dynamic_read    \
	test_memset_static_write     \
	test_memset_dynamic_write    \
	test_stpcpy_overwrite_over   \
	test_stpcpy_overwrite_under  \
	test_stpcpy_static_write     \
	test_strcat_static_write     \
	test_strcpy_overwrite_over   \
	test_strcpy_overwrite_under  \
	test_strcpy_static_write     \
	test_strncat_static_write    \
	test_strncpy_overwrite_over  \
	test_strncpy_overwrite_under \
	test_strncpy_static_write    \
	test_stpncpy_overwrite_over  \
	test_stpncpy_overwrite_under \
	test_stpncpy_static_write    \
	test_confstr                 \
	test_getcwd                  \
	test_poll                    \
	test_ppoll                   \
	test_getdomainname           \
	test_getgroups               \
	test_gethostname             \
	test_getlogin_r              \
	test_pread                   \
	test_read                    \
	test_readlink                \
	test_ttyname_r               \
	test_write                   \
	test_fread_int_overflow      \
	test_fread_overwrite         \
	test_fwrite_int_overflow     \
	test_fwrite_overwrite        \
	test_vsnprintf               \
	test_vsprintf                \
	test_malloc                  \

.SILENT:

gcc: CC=../x86_64-linux-musl-native/bin/gcc
gcc: GCOV=../x86_64-linux-musl-native/bin/gcov
gcc: clean all

clang: CC=clang
clang: GCOV=gcov
clang: CFLAGS+=-I/usr/include/x86_64-linux-musl
clang: CLFAGS+=-nostdlib
clang: clean all


all: $(TARGETS) run

coverage: CFLAGS += -fprofile-arcs -ftest-coverage
coverage: CC=../x86_64-linux-musl-native/bin/gcc
coverage: GCOV=../x86_64-linux-musl-native/bin/gcov
coverage: all
	$(GCOV) *.c
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage

$(TARGETS): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGETS)
	$(foreach EXE, $(TARGETS), \
		timeout 1s ./$(EXE) 1 2 3 4 5 6 7 8 9 0 >/dev/null && echo "$(EXE) OK" || echo "$(EXE) FAIL" ; \
	)

clean:
	$(foreach EXE, $(TARGETS), \
		rm -f ./$(EXE) \
	)
	rm -rf ./*.gcno ./*.gcda ./*.gcov ./coverage.info ./coverage

