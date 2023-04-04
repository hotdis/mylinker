#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __MYLINKER_HELPER_H__
#define __MYLINKER_HELPER_H__

bool has_prefix(FILE *fp, void *prefix, size_t size);

#endif