MACHINE := $(shell uname -m)
CFLAGS ?= -std=gnu99
CFLAGS += -I../include/ -D_FORTIFY_SOURCE=3 -static -O2 -Wall -Wextra -Werror -Werror=pointer-arith
CFLAGS += -Wno-format -Wno-array-bounds -Wno-shift-count-negative -Wno-unused-variable -Wno-unused-parameter

RUNTIME_TARGETS= \
	test_FD_CLR_SETSIZE           \
	test_FD_CLR_negative          \
	test_FD_SET_SETSIZE           \
	test_FD_SET_negative          \
	test_bcopy_dynamic_read       \
	test_bcopy_dynamic_write      \
	test_bcopy_static_read        \
	test_bcopy_static_write       \
	test_bzero_dynamic_write      \
	test_bzero_static_write       \
	test_compile                  \
	test_confstr_dynamic          \
	test_fgets_dynamic            \
	test_fgets_static             \
	test_fgetws_dynamic           \
	test_fgetws_static            \
	test_fread_int_overflow       \
	test_fread_overwrite_dynamic  \
	test_fread_overwrite_static   \
	test_fwrite_int_overflow      \
	test_fwrite_overwrite_dynamic \
	test_fwrite_overwrite_static  \
	test_getcwd_dynamic           \
	test_getcwd_static            \
	test_getdomainname_dynamic    \
	test_getdomainname_static     \
	test_getgroups_dynamic        \
	test_getgroups_static         \
	test_gethostname_dynamic      \
	test_gethostname_static       \
	test_getlogin_r_dynamic       \
	test_getlogin_r_static        \
	test_memcpy_dynamic_read      \
	test_memcpy_dynamic_write     \
	test_memcpy_static_read       \
	test_memmove_dynamic_read     \
	test_memmove_dynamic_write    \
	test_memmove_static_read      \
	test_memmove_static_write     \
	test_mempcpy_dynamic_read     \
	test_mempcpy_dynamic_write    \
	test_mempcpy_static_read      \
	test_mempcpy_static_write     \
	test_memset_dynamic_write     \
	test_memset_static_write      \
	test_poll_dynamic             \
	test_poll_static              \
	test_ppoll_dynamic            \
	test_ppoll_static             \
	test_read_dynamic             \
	test_read_static              \
	test_readlink_dynamic         \
	test_readlink_static          \
	test_recv_dynamic             \
	test_recv_static              \
	test_recvfrom_dynamic         \
	test_recvfrom_static          \
	test_send_dynamic             \
	test_send_static              \
	test_sendto_dynamic           \
	test_sendto_static            \
	test_sprintf                  \
	test_sprintf_62               \
	test_stpcpy_dynamic_write     \
	test_stpcpy_static_write      \
	test_stpncpy_dynamic_write    \
	test_stpncpy_static_write     \
	test_strcat_static_write      \
	test_strcpy_dynamic_write     \
	test_strcpy_static_write      \
	test_strlcat_dynamic_write    \
	test_strlcat_static_write     \
	test_strlcpy_dynamic_write    \
	test_strlcpy_static_write     \
	test_strncat_dynamic_write    \
	test_strncat_static_write     \
	test_strncpy_dynamic_write    \
	test_strncpy_static_write     \
	test_swab_dynamic_read        \
	test_swab_dynamic_write       \
	test_swab_static_read         \
	test_ttyname_r_dynamic        \
	test_ttyname_r_static         \
	test_vsnprintf_dynamic        \
	test_vsnprintf_static         \
	test_vsprintf                 \
	test_wcscat_static_write      \
	test_wcscpy_static_write      \
	test_wcsncat_static_write     \
	test_wcsncpy_static_write     \
	test_wmemcpy_dynamic_write    \
	test_wmemcpy_static_write     \
	test_wmemmove_dynamic_write   \
	test_wmemmove_static_write    \
	test_wmemset_dynamic          \
	test_wmemset_static           \
	test_write_dynamic            \
	test_write_static             \

gcc: CC=../$(MACHINE)-linux-musl-native/bin/gcc
gcc: CFLAGS += -Wno-stringop-overread -Wno-stringop-overflow -ffreestanding
gcc: $(RUNTIME_TARGETS)

clang: CC=clang
clang: CFLAGS+=-I/usr/include/$(MACHINE)-linux-musl
clang: CFLAGS+=-I../$(MACHINE)-linux-musl-native/include/
clang: CFLAGS+=-I$(MACHINE)-linux-musl-native/include/
clang: CFLAGS+=-nostdinc
clang: CXX=clang++
clang: CXXFLAGS+=-I/usr/include/$(MACHINE)-linux-musl
clang: CXXFLAGS+=-I../$(MACHINE)-linux-musl-native/include/
clang: CXXFLAGS+=-I$(MACHINE)-linux-musl-native/include/
clang: CXXFLAGS+=-nostdinc
clang: $(RUNTIME_TARGETS) cpp

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

clean:
	$(foreach EXE, $(RUNTIME_TARGETS), \
		rm -f ./$(EXE) \
	)
	rm -f ./test_compile_cc

