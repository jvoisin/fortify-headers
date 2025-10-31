# What is it?

This is a [standalone implementation](https://git.2f30.org/fortify-headers/) of
[fortify source]( http://gcc.gnu.org/ml/gcc-patches/2004-09/msg02055.html )
level 3, providing compile time security checks. It is libc-agnostic and simply
overlays the system headers by using the
[`#include_next`](https://gcc.gnu.org/onlinedocs/cpp/Wrapper-Headers.html)
extension found in GCC, and [black
magic](https://github.com/jvoisin/fortify-headers/commit/fe149628eaae9748be08815d726cc56e8e492c73)
on Clang. It was initially intended to be used on
[musl](http://www.musl-libc.org/) based Linux
distributions like [Alpine Linux](https://alpinelinux.org),
[Chimera Linux](https://chimera-linux.org/).


# Features

- It is portable, works on *BSD, Linux, Solaris and possibly others.
- It will only trap non-conformant programs. This means that fortify
  level 2 is treated in the same way as level 1.
- Avoids making function calls when undefined behaviour has already been
  invoked. This is handled by using `__builtin_trap()`.
- Support for out-of-bounds read interfaces, such as send(), write(), fwrite() etc.
- No ABI is enforced. All of the fortify check functions are inlined
  into the resulting binary.
- It has a comprehensive suite of
  tests, running on multiple versions of Clang and GCC,
  as well as on C89, C99, C11 and C17.


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
cc -I<path-to-fortify-include-dir> -D_FORTIFY_SOURCE=3 -O1 fgets.c
./a.out
```

At this point, the program will safely crash.


Supported interfaces
====================

FD_CLR
FD_SET
bcopy
bzero
confstr
fgets
fgetws
fread
fwrite
getcwd
getdomainname
getgroups
gethostname
getlogin_r
mbsnrtowcs
mbsrtowcs
mbstowcs
memcpy
memmove
mempcpy
memset
poll
ppoll
pread
read
readlink
readlinkat
realpath
recv
recvfrom
send
sendto
snprintf
sprintf
stpcpy
stpncpy
strcat
strcpy
strlcat
strlcpy
strncat
strncpy
ttyname_r
vsnprintf
vsprintf
wcrtomb
wcscat
wcscpy
wcsncat
wcsncpy
wcsnrtombs
wcsrtombs
wcstombs
wmemcpy
wmemmove
wmemset
write
