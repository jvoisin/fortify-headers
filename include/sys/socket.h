#ifndef _FORTIFY_SYS_SOCKET_H
#define _FORTIFY_SYS_SOCKET_H

#include_next <sys/socket.h>

#if defined(_FORTIFY_SOURCE) && _FORTIFY_SOURCE > 0 && defined(__OPTIMIZE__) && __OPTIMIZE__ > 0

#ifndef __cplusplus
#undef recv
#undef recvfrom
#undef send
#undef sendto

extern ssize_t __recv_orig(int, void *, size_t, int)
	__asm__(__USER_LABEL_PREFIX__ "recv");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
ssize_t recv(int sockfd, void *buf, size_t n, int flags)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __recv_orig(sockfd, buf, n, flags);
}

extern ssize_t __recvfrom_orig(int, void *, size_t, int, struct sockaddr *, socklen_t *)
	__asm__(__USER_LABEL_PREFIX__ "recvfrom");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
ssize_t recvfrom(int sockfd, void *buf, size_t n, int flags,
                 struct sockaddr *sa, socklen_t *salen)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __recvfrom_orig(sockfd, buf, n, flags, sa, salen);
}

extern ssize_t __send_orig(int, const void *, size_t, int)
	__asm__(__USER_LABEL_PREFIX__ "send");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
ssize_t send(int sockfd, const void *buf, size_t n, int flags)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __send_orig(sockfd, buf, n, flags);
}

extern ssize_t __sendto_orig(int, const void *, size_t, int, const struct sockaddr *, socklen_t)
	__asm__(__USER_LABEL_PREFIX__ "sendto");
extern __inline __attribute__((__always_inline__,__gnu_inline__))
ssize_t sendto(int sockfd, const void *buf, size_t n, int flags,
               const struct sockaddr *sa, socklen_t salen)
{
	size_t bos = __builtin_object_size(buf, 0);

	if (n > bos)
		__builtin_trap();
	return __sendto_orig(sockfd, buf, n, flags, sa, salen);
}

#endif

#endif

#endif
