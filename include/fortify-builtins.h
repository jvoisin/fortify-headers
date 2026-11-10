/* Cache ordinary builtin availability before native declarations.  GCC C's
 * __has_builtin stops recognizing a builtin after an ordinary declaration.
 * Include it before manual libc declarations, or first inside a PCH.
 * Keep this catalogue aligned with the _FORTIFY_FN/_FORTIFY_FNB wrappers.
 */
#ifndef FORTIFY_HEADERS_INTERNAL_BUILTINS_H
#define FORTIFY_HEADERS_INTERNAL_BUILTINS_H

#if defined(__GNUC__) && !defined(__clang__) && defined(__has_builtin)

#if __has_builtin(bcopy)
#define FORTIFY_HEADERS_INTERNAL_CALL_bcopy __builtin_bcopy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_bcopy __orig_bcopy
#endif

#if __has_builtin(bzero)
#define FORTIFY_HEADERS_INTERNAL_CALL_bzero __builtin_bzero
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_bzero __orig_bzero
#endif

#if __has_builtin(confstr)
#define FORTIFY_HEADERS_INTERNAL_CALL_confstr __builtin_confstr
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_confstr __orig_confstr
#endif

#if __has_builtin(fgets)
#define FORTIFY_HEADERS_INTERNAL_CALL_fgets __builtin_fgets
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_fgets __orig_fgets
#endif

#if __has_builtin(fgetws)
#define FORTIFY_HEADERS_INTERNAL_CALL_fgetws __builtin_fgetws
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_fgetws __orig_fgetws
#endif

#if __has_builtin(fread)
#define FORTIFY_HEADERS_INTERNAL_CALL_fread __builtin_fread
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_fread __orig_fread
#endif

#if __has_builtin(fwrite)
#define FORTIFY_HEADERS_INTERNAL_CALL_fwrite __builtin_fwrite
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_fwrite __orig_fwrite
#endif

#if __has_builtin(getcwd)
#define FORTIFY_HEADERS_INTERNAL_CALL_getcwd __builtin_getcwd
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_getcwd __orig_getcwd
#endif

#if __has_builtin(getdomainname)
#define FORTIFY_HEADERS_INTERNAL_CALL_getdomainname __builtin_getdomainname
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_getdomainname __orig_getdomainname
#endif

#if __has_builtin(getgroups)
#define FORTIFY_HEADERS_INTERNAL_CALL_getgroups __builtin_getgroups
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_getgroups __orig_getgroups
#endif

#if __has_builtin(gethostname)
#define FORTIFY_HEADERS_INTERNAL_CALL_gethostname __builtin_gethostname
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_gethostname __orig_gethostname
#endif

#if __has_builtin(getlogin_r)
#define FORTIFY_HEADERS_INTERNAL_CALL_getlogin_r __builtin_getlogin_r
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_getlogin_r __orig_getlogin_r
#endif

#if __has_builtin(mbsnrtowcs)
#define FORTIFY_HEADERS_INTERNAL_CALL_mbsnrtowcs __builtin_mbsnrtowcs
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_mbsnrtowcs __orig_mbsnrtowcs
#endif

#if __has_builtin(mbsrtowcs)
#define FORTIFY_HEADERS_INTERNAL_CALL_mbsrtowcs __builtin_mbsrtowcs
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_mbsrtowcs __orig_mbsrtowcs
#endif

#if __has_builtin(mbstowcs)
#define FORTIFY_HEADERS_INTERNAL_CALL_mbstowcs __builtin_mbstowcs
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_mbstowcs __orig_mbstowcs
#endif

#if __has_builtin(memcpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_memcpy __builtin_memcpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_memcpy __orig_memcpy
#endif

#if __has_builtin(memmove)
#define FORTIFY_HEADERS_INTERNAL_CALL_memmove __builtin_memmove
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_memmove __orig_memmove
#endif

#if __has_builtin(mempcpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_mempcpy __builtin_mempcpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_mempcpy __orig_mempcpy
#endif

#if __has_builtin(memset)
#define FORTIFY_HEADERS_INTERNAL_CALL_memset __builtin_memset
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_memset __orig_memset
#endif

#if __has_builtin(poll)
#define FORTIFY_HEADERS_INTERNAL_CALL_poll __builtin_poll
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_poll __orig_poll
#endif

#if __has_builtin(ppoll)
#define FORTIFY_HEADERS_INTERNAL_CALL_ppoll __builtin_ppoll
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_ppoll __orig_ppoll
#endif

#if __has_builtin(pread)
#define FORTIFY_HEADERS_INTERNAL_CALL_pread __builtin_pread
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_pread __orig_pread
#endif

#if __has_builtin(read)
#define FORTIFY_HEADERS_INTERNAL_CALL_read __builtin_read
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_read __orig_read
#endif

#if __has_builtin(readlink)
#define FORTIFY_HEADERS_INTERNAL_CALL_readlink __builtin_readlink
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_readlink __orig_readlink
#endif

#if __has_builtin(readlinkat)
#define FORTIFY_HEADERS_INTERNAL_CALL_readlinkat __builtin_readlinkat
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_readlinkat __orig_readlinkat
#endif

#if __has_builtin(realpath)
#define FORTIFY_HEADERS_INTERNAL_CALL_realpath __builtin_realpath
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_realpath __orig_realpath
#endif

#if __has_builtin(recv)
#define FORTIFY_HEADERS_INTERNAL_CALL_recv __builtin_recv
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_recv __orig_recv
#endif

#if __has_builtin(recvfrom)
#define FORTIFY_HEADERS_INTERNAL_CALL_recvfrom __builtin_recvfrom
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_recvfrom __orig_recvfrom
#endif

#if __has_builtin(send)
#define FORTIFY_HEADERS_INTERNAL_CALL_send __builtin_send
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_send __orig_send
#endif

#if __has_builtin(sendto)
#define FORTIFY_HEADERS_INTERNAL_CALL_sendto __builtin_sendto
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_sendto __orig_sendto
#endif

#if __has_builtin(snprintf)
#define FORTIFY_HEADERS_INTERNAL_CALL_snprintf __builtin_snprintf
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_snprintf __orig_snprintf
#endif

#if __has_builtin(sprintf)
#define FORTIFY_HEADERS_INTERNAL_CALL_sprintf __builtin_sprintf
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_sprintf __orig_sprintf
#endif

#if __has_builtin(stpcpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_stpcpy __builtin_stpcpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_stpcpy __orig_stpcpy
#endif

#if __has_builtin(stpncpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_stpncpy __builtin_stpncpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_stpncpy __orig_stpncpy
#endif

#if __has_builtin(strcat)
#define FORTIFY_HEADERS_INTERNAL_CALL_strcat __builtin_strcat
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_strcat __orig_strcat
#endif

#if __has_builtin(strcpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_strcpy __builtin_strcpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_strcpy __orig_strcpy
#endif

#if __has_builtin(strlcat)
#define FORTIFY_HEADERS_INTERNAL_CALL_strlcat __builtin_strlcat
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_strlcat __orig_strlcat
#endif

#if __has_builtin(strlcpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_strlcpy __builtin_strlcpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_strlcpy __orig_strlcpy
#endif

#if __has_builtin(strncat)
#define FORTIFY_HEADERS_INTERNAL_CALL_strncat __builtin_strncat
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_strncat __orig_strncat
#endif

#if __has_builtin(strncpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_strncpy __builtin_strncpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_strncpy __orig_strncpy
#endif

#if __has_builtin(swab)
#define FORTIFY_HEADERS_INTERNAL_CALL_swab __builtin_swab
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_swab __orig_swab
#endif

#if __has_builtin(ttyname_r)
#define FORTIFY_HEADERS_INTERNAL_CALL_ttyname_r __builtin_ttyname_r
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_ttyname_r __orig_ttyname_r
#endif

#if __has_builtin(vsnprintf)
#define FORTIFY_HEADERS_INTERNAL_CALL_vsnprintf __builtin_vsnprintf
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_vsnprintf __orig_vsnprintf
#endif

#if __has_builtin(vsprintf)
#define FORTIFY_HEADERS_INTERNAL_CALL_vsprintf __builtin_vsprintf
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_vsprintf __orig_vsprintf
#endif

#if __has_builtin(wcrtomb)
#define FORTIFY_HEADERS_INTERNAL_CALL_wcrtomb __builtin_wcrtomb
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wcrtomb __orig_wcrtomb
#endif

#if __has_builtin(wcscat)
#define FORTIFY_HEADERS_INTERNAL_CALL_wcscat __builtin_wcscat
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wcscat __orig_wcscat
#endif

#if __has_builtin(wcscpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_wcscpy __builtin_wcscpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wcscpy __orig_wcscpy
#endif

#if __has_builtin(wcsncat)
#define FORTIFY_HEADERS_INTERNAL_CALL_wcsncat __builtin_wcsncat
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wcsncat __orig_wcsncat
#endif

#if __has_builtin(wcsncpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_wcsncpy __builtin_wcsncpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wcsncpy __orig_wcsncpy
#endif

#if __has_builtin(wcsnrtombs)
#define FORTIFY_HEADERS_INTERNAL_CALL_wcsnrtombs __builtin_wcsnrtombs
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wcsnrtombs __orig_wcsnrtombs
#endif

#if __has_builtin(wcsrtombs)
#define FORTIFY_HEADERS_INTERNAL_CALL_wcsrtombs __builtin_wcsrtombs
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wcsrtombs __orig_wcsrtombs
#endif

#if __has_builtin(wcstombs)
#define FORTIFY_HEADERS_INTERNAL_CALL_wcstombs __builtin_wcstombs
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wcstombs __orig_wcstombs
#endif

#if __has_builtin(wmemcpy)
#define FORTIFY_HEADERS_INTERNAL_CALL_wmemcpy __builtin_wmemcpy
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wmemcpy __orig_wmemcpy
#endif

#if __has_builtin(wmemmove)
#define FORTIFY_HEADERS_INTERNAL_CALL_wmemmove __builtin_wmemmove
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wmemmove __orig_wmemmove
#endif

#if __has_builtin(wmemset)
#define FORTIFY_HEADERS_INTERNAL_CALL_wmemset __builtin_wmemset
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_wmemset __orig_wmemset
#endif

#if __has_builtin(write)
#define FORTIFY_HEADERS_INTERNAL_CALL_write __builtin_write
#else
#define FORTIFY_HEADERS_INTERNAL_CALL_write __orig_write
#endif

#define FORTIFY_HEADERS_INTERNAL_CALL(fn) FORTIFY_HEADERS_INTERNAL_CALL_##fn
#else
#define FORTIFY_HEADERS_INTERNAL_CALL(fn) __orig_##fn
#endif

#endif
