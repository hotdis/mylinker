#include "include/helper.h"

bool has_prefix(FILE *fp, void *prefix, size_t size) {
    char *buffer = (char*)malloc(size*sizeof(char));
    if (fread(buffer, 1, size, fp) < size) {
        fprintf(stderr, "linker cann't read enough bytes (%ld) from file.\n", size);
        fclose(fp);
        exit(-1);
    }
    return !memcmp(buffer, prefix, size);
}