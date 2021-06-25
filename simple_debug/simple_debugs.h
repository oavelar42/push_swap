#ifndef SIMPLE_DEBUGS_H
# define SIMPLE_DEBUGS_H

/*
**	Simple debug functions
*/
# include <unistd.h>
void debug_str(const char *s, char *name);
void debug_number(int i, char *name);

/*
**	Memory leak checker in C, courtesy of https://gist.github.com/drrost
*/

#include <stdio.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <string.h>
#include <stdlib.h>
void check_leaks();

#endif