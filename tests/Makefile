CFLAGS+=-I../include/ -D_FORTIFY_SOURCE=3 -static -O2 -DFORTIFY_PEDANTIC_CHECKS -Wno-format -Werror=pointer-arith

COMPTIME_TARGETS= \
	test_memcpy_overwrite_under  \
	test_memcpy_static_write     \


RUNTIME_TARGETS= \
	test_FD_CLR_SETSIZE          \
	test_FD_CLR_negative         \
	test_FD_SET_SETSIZE          \
	test_FD_SET_negative         \
	test_FD_ISSET_SETSIZE        \
	test_FD_ISSET_negative       \
	test_asprintf                \
	test_bcopy_dynamic_read      \
	test_bcopy_dynamic_write     \
	test_bcopy_static_read       \
	test_bcopy_static_write      \
	test_bzero_dynamic_write     \
	test_bzero_static_write      \
	test_compile                 \
	test_confstr_dynamic         \
	test_confstr_static          \
	test_fgets_dynamic           \
	test_fgets_static            \
	test_fgetws_dynamic          \
	test_fgetws_static           \
	test_fprintf                 \
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
	test_issue57                 \
	test_issue57_strcpy          \
	test_mbsrtowcs_dynamic       \
	test_mbsrtowcs_static        \
	test_mbstowcs_dynamic        \
	test_mbstowcs_static         \
	test_memchr_dynamic_read     \
	test_memchr_static_read      \
	test_memchr_null             \
	test_memcpy_dynamic_read     \
	test_memcpy_dynamic_write    \
	test_memcpy_overwrite_over   \
	test_memcpy_static_read      \
	test_memcpy_null_src         \
	test_memcpy_null_dst         \
	test_memmove_null_src        \
	test_memmove_null_dst        \
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
	test_memset_null             \
	test_poll_dynamic            \
	test_poll_static             \
	test_ppoll_dynamic           \
	test_ppoll_static            \
	test_pread_dynamic           \
	test_pread_static            \
	test_printf                  \
	test_pwrite_dynamic          \
	test_pwrite_static           \
	test_qsort_dynamic           \
	test_qsort_static            \
	test_read_dynamic            \
	test_read_static             \
	test_readlink_dynamic        \
	test_readlink_static         \
	test_recv_dynamic            \
	test_recv_static             \
	test_recvfrom_dynamic        \
	test_recvfrom_static         \
	test_select_dynamic          \
	test_select_static           \
	test_send_dynamic            \
	test_send_static             \
	test_sendto_dynamic          \
	test_sendto_static           \
	test_stpcpy_dynamic_write    \
	test_stpcpy_overwrite_over   \
	test_stpcpy_overwrite_under  \
	test_stpcpy_static_write     \
	test_stpncpy_dynamic_write   \
	test_stpncpy_overwrite_over  \
	test_stpncpy_overwrite_under \
	test_stpncpy_static_write    \
	test_strlen_static_read      \
	test_strcat_static_write     \
	test_strchr_dynamic_read     \
	test_strchr_static_read      \
	test_strcpy_dynamic_write    \
	test_strcpy_overwrite_over   \
	test_strcpy_overwrite_under  \
	test_strcpy_static_write     \
	test_strlcat_dynamic_write   \
	test_strlcat_static_write    \
	test_strlcpy_dynamic_write   \
	test_strlcpy_static_write    \
	test_strncat_dynamic_write   \
	test_strncat_static_write    \
	test_strncpy_dynamic_write   \
	test_strncpy_overwrite_over  \
	test_strncpy_overwrite_under \
	test_strncpy_static_write    \
	test_strrchr_dynamic_read    \
	test_strrchr_static_read     \
	test_ttyname_r_dynamic       \
	test_ttyname_r_static        \
	test_umask                   \
	test_vasprintf               \
	test_vfprintf                \
	test_vprintf                 \
	test_vsnprintf_dynamic       \
	test_vsnprintf_static        \
	test_vsprintf                \
	test_wcscat_static_write     \
	test_wcscpy_static_write     \
	test_wcsncat_static_write    \
	test_wcsncpy_static_write    \
	test_wmemcpy_dynamic_write   \
	test_wmemcpy_static_write    \
	test_wmemmove_dynamic_write  \
	test_wmemmove_static_write   \
	test_wmemset_dynamic         \
	test_wmemset_static          \
	test_write_dynamic           \
	test_write_static            \

.SILENT:

gcc: CC=../x86_64-linux-musl-native/bin/gcc
gcc: $(RUNTIME_TARGETS)

clang: CC=clang
clang: CFLAGS+=-I/usr/include/x86_64-linux-musl
clang: CFLAGS+=-I../x86_64-linux-musl-native/include/
clang: CFLAGS+=-Ix86_64-linux-musl-native/include/
clang: CFLAGS+=-nostdinc
clang: CXX=clang++
clang: CXXFLAGS=$(CFLAGS)
clang: comptime $(RUNTIME_TARGETS) cpp

coverage: CFLAGS += -fprofile-arcs -ftest-coverage
coverage: CC=../x86_64-linux-musl-native/bin/gcc
coverage: GCOV=../x86_64-linux-musl-native/bin/gcov
coverage: $(RUNTIME_TARGETS) run
	$(GCOV) *.c
	lcov --capture --directory . --output-file coverage.info
	lcov --remove ./coverage.info "*/tests/*" --output-file cleaned-coverage.info
	genhtml cleaned-coverage.info --output-directory coverage

all: gcc


$(RUNTIME_TARGETS): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

cpp: test_compile.cc
	$(CXX) $(CXXFLAGS) test_compile.cc -o ./test_compile_cc
	timeout 1s ./test_compile_cc 1234567890 2 3 4 5 6 7 8 9 0 >/dev/null && echo "$(EXE) OK" || echo "$(EXE) FAIL"; \

run: $(RUNTIME_TARGETS)
	$(foreach EXE, $(RUNTIME_TARGETS), \
		timeout 1s ./$(EXE) 1234567890 2 3 4 5 6 7 8 9 0 >/dev/null && echo "$(EXE) OK" || echo "$(EXE) FAIL"; \
	)

comptime:  # only works on clang, as gcc doesn't have the diagnose_if attribute
	$(foreach EXE, $(COMPTIME_TARGETS), \
		($(CC) $(CFLAGS) -o ./$(EXE) ./$(EXE).c 1>/dev/null 2>/dev/null && echo "$(EXE) FAIL" || echo "$(EXE) OK") || true ;\
	)

clean:
	$(foreach EXE, $(RUNTIME_TARGETS) $(COMPTIME_TARGETS), \
		rm -f ./$(EXE) \
	)
	rm -f ./test_compile_cc
	rm -rf ./*.gcno ./*.gcda ./*.gcov ./coverage.info ./coverage

