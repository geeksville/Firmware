/****************************************************************************
 *
 *   Copyright (C) 2012 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file	Lua bindings for NuttX
 */

#include <string.h>

#include "nuttx_lua_compat.h"

static void
_unimplemented(const char *what)
{
	// Only print when testing...
	//printf("Lua: %s() unimplemented\n", what);
	//fflush(stdout);
}

/*
 * Functions that aren't implemented and which affect Lua or 
 * Lua code in some fashion.
 */

int
ferror(FILE *f)
{
	// don't print this - Lua calls it all the time
	_unimplemented("ferror");
	return 0;
}

void
clearerr(FILE *stream)
{
	_unimplemented("clearerr");
}

int
feof(FILE *f)
{
	/* XXX this needs to be fixed inside NuttX */
	_unimplemented("feof");
	return 0;
}

FILE *
tmpfile(void)
{
	_unimplemented("tmpfile");
	return NULL;
}

int
fscanf(FILE *restrict stream, const char *restrict format, ...)
{
	_unimplemented("fscanf");
	return 0;
}

int
setvbuf(FILE *stream, char *buf, int type, size_t size)
{
	_unimplemented("setvbuf");
	return 0;
}

clock_t
clock(void)
{
	_unimplemented("clock");
	return -1;
}

/*
 * Some functions that Lua wants but NuttX doesn't/may never implement.
 */

FILE *
freopen(const char *filename, const char *mode, FILE *stream)
{
	/* This is only used to change from 'ascii' to 'binary' mode and can probably
	 * safely be ignored.
	 */
	return stream;
}

int
strcoll(const char *s1, const char *s2)
{
	/* this is good enough for us */
	return strcmp(s1, s2);
}

char *
tmpnam(char *buf)
{
	static char name[L_tmpnam];
	static int tmpidx;
	char *p;

	p = buf ? buf : name;

	sprintf(p, "/tmp/luatmp.%04d", tmpidx++);
	
	return p;
}

int remove(const char *path)
{
	return unlink(path);
}

double
difftime(time_t time1, time_t time0)
{
	return (double)time1 - (double)time0;
}

int
system(const char *command)
{
	_unimplemented("system");
	return -1;
}

char *
setlocale(int category, const char *locale)
{
	return NULL;
}
