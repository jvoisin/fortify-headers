CFLAGS=-I../include/ -D_FORTIFY_SOURCE=3 -static -O2

TARGETS= \
	test_FD_CLR_SETSIZE          \
	test_FD_CLR_negative         \
	test_FD_SET_SETSIZE          \
	test_FD_SET_negative         \
	test_bcopy_dynamic_read      \
	test_bcopy_dynamic_write     \
	test_bcopy_static_read       \
	test_bcopy_static_write      \
	test_bzero_dynamic_write     \
	test_bzero_static_write      \
	test_confstr_dynamic         \
	test_confstr_static          \
	test_fgets_dynamic           \
	test_fgets_static            \
	test_fread_int_overflow      \
	test_fread_overwrite_dynamic \
	test_fread_overwrite_static  \
	test_fwrite_int_overflow     \
	test_fwrite_overwrite_dynamic \
	test_fwrite_overwrite_static \
	test_getcwd_dynamic          \
	test_getcwd_static           \
	test_getdomainname_dynamic   \
	test_getdomainname_static    \
	test_getgroups_dynamic       \
	test_getgroups_static        \
	test_gethostname_dynamic     \
	test_gethostname_static      \
	test_getlogin_r_dynamic      \
	test_getlogin_r_static       \
	test_malloc                  \
	test_memcpy_dynamic_read     \
	test_memcpy_dynamic_write    \
	test_memcpy_overwrite_over   \
	test_memcpy_overwrite_under  \
	test_memcpy_static_read      \
	test_memcpy_static_write     \
	test_memmove_dynamic_read    \
	test_memmove_dynamic_write   \
	test_memmove_static_read     \
	test_memmove_static_write    \
	test_mempcpy_dynamic_read    \
	test_mempcpy_dynamic_write   \
	test_mempcpy_static_read     \
	test_mempcpy_static_write    \
	test_memset_dynamic_write    \
	test_memset_static_write     \
	test_poll_dynamic            \
	test_poll_static             \
	test_ppoll_dynamic           \
	test_ppoll_static            \
	test_pread_dynamic           \
	test_pread_static            \
	test_read_dynamic            \
	test_read_static             \
	test_readlink_dynamic        \
	test_readlink_static         \
	test_recv_dynamic            \
	test_recv_static             \
	test_recvfrom_dynamic        \
	test_recvfrom_static         \
	test_send_dynamic            \
	test_send_static             \
	test_sendto_dynamic          \
	test_sendto_static           \
	test_stpcpy_overwrite_over   \
	test_stpcpy_overwrite_under  \
	test_stpcpy_static_write     \
	test_stpncpy_overwrite_over  \
	test_stpncpy_overwrite_under \
	test_stpncpy_static_write    \
	test_strcat_static_write     \
	test_strcpy_overwrite_over   \
	test_strcpy_overwrite_under  \
	test_strcpy_static_write     \
	test_strncat_static_write    \
	test_strncpy_overwrite_over  \
	test_strncpy_overwrite_under \
	test_strncpy_static_write    \
	test_ttyname_r_dynamic       \
	test_ttyname_r_static        \
	test_vsnprintf_dynamic       \
	test_vsnprintf_static        \
	test_vsprintf                \
	test_write_dynamic           \
	test_write_static            \

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

