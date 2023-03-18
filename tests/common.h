/* Copyright (C) 2004-2020 Free Software Foundation, Inc.
   This snippet is taken from debug/tst-chk1 in the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <setjmp.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

volatile int chk_fail_ok;
volatile int ret;
jmp_buf chk_fail_buf;

static void
handler (int sig)
{
  if (chk_fail_ok)
    {
      chk_fail_ok = 0;
      longjmp (chk_fail_buf, 1);
    }
  else
    _exit (127);
}

void
__attribute__((constructor))
set_fortify_handler (void)
{
  struct sigaction sa;

  sa.sa_handler = handler;
  sa.sa_flags = 0;
  sigemptyset (&sa.sa_mask);

  sigaction (SIGILL, &sa, NULL);
}

#define FAIL() \
  do { fprintf (stderr, "Failure on line %d\n", __LINE__); ret = 1; } while (0)
#define CHK_FAIL_START \
  chk_fail_ok = 1;                              \
  if (! setjmp (chk_fail_buf))                  \
    {
#define CHK_FAIL_END \
      chk_fail_ok = 0;                          \
      FAIL ();                                  \
    }

