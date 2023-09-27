# What is it?

This is a standalone implementation of
[fortify source]( http://gcc.gnu.org/ml/gcc-patches/2004-09/msg02055.html )
based on [the one](https://git.2f30.org/fortify-headers/) from
[sin](https://u.2f30.org/sin/). It provides compile time buffer checks.
It is libc-agnostic and simply overlays the system headers by using the
[`#include_next`](https://gcc.gnu.org/onlinedocs/cpp/Wrapper-Headers.html)
extension found in GCC, and
[black magic](https://github.com/jvoisin/fortify-headers/commit/fe149628eaae9748be08815d726cc56e8e492c73)
on Clang. It was initially intended to be used on
[musl](http://www.musl-libc.org/) based
[Linux distributions](https://git.alpinelinux.org/aports/commit/?id=067a4f28825478911bb62be3b8da758d9722753e).


# Features

- It is portable, works on *BSD, Linux, Solaris and possibly others.
- It will only trap non-conformant programs.  This means that fortify
  level 2 is treated in the same way as level 1.
- Avoids making function calls when undefined behaviour has already been
  invoked.  This is handled by using `__builtin_trap()`.
- Support for out-of-bounds read interfaces, such as send(), write(),
  fwrite() etc.
- No ABI is enforced.  All of the fortify check functions are inlined
  into the resulting binary.
- It has a [comprehensive suite of tests](https://github.com/jvoisin/fortify-headers/tree/master/tests),
  running both on Clang and on GCC for every commit, with
  [significant coverage](https://jvoisin.github.io/fortify-headers/)
- Defining `USE_NATIVE_CHK` will make use of compiler-provided builtin `_chk`
  functions, which might be a bit better in term of diagnostics,
  but won't necesarily provide the same amount of security checks.


# Sample usage

If you want to quickly test it, you can try something like the following:

```
cat > fgets.c <<EOF
#include <stdio.h>
int
main(void)
{
	char buf[BUFSIZ];
	fgets(buf, sizeof(buf) + 1, stdin);
	return 0;
}
EOF
cc -I<path-to-fortify-include-dir> -D_FORTIFY_SOURCE=1 -O1 fgets.c
./a.out
```

At this point, the program will safely crash.


# Supported interfaces

- `FD_CLR`
- `FD_SET`
- `bcopy`
- `bzero`
- `confstr`
- `fgets`
- `fgetws`
- `fread`
- `fwrite`
- `getcwd`
- `getdomainname`
- `getgroups`
- `gethostname`
- `getlogin_r`
- `mbsnrtowcs`
- `mbsrtowcs`
- `mbstowcs`
- `memcpy`
- `memmove`
- `mempcpy`
- `memset`
- `poll`
- `ppoll`
- `pread`
- `read`
- `readlink`
- `readlinkat`
- `realpath`
- `recv`
- `recvfrom`
- `send`
- `sendto`
- `snprintf`
- `sprintf`
- `stpcpy`
- `stpncpy`
- `strcat`
- `strchr`
- `strcpy`
- `strlcat`
- `strlcpy`
- `strncat`
- `strncpy`
- `strrchr`
- `ttyname_r`
- `vsnprintf`
- `vsprintf`
- `wcrtomb`
- `wcscat`
- `wcscpy`
- `wcsncat`
- `wcsncpy`
- `wcsnrtombs`
- `wcsrtombs`
- `wcstombs`
- `wctomb`
- `wmemcpy`
- `wmemmove`
- `wmemset`
- `write`
