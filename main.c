#include "include/main.h"

int main(int argc, char **argv) {
	FILE *fp;
    int retcode = 0;

    if (argc < 2) { 
        fprintf(stderr, "lack of input files.\n");
        return -1;
    }
        
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "linker can't open the file %s.\n", argv[1]);
        return -1;
    }

#define ELF_MAGIC "\x7f\x45\x4c\x46"
    if (!has_prefix(fp, ELF_MAGIC, strlen(ELF_MAGIC))) {
        fprintf(stderr, "%s is not an ELF file.\n", argv[1]);
        retcode = -1;
        goto end;
	}

end:
	fclose(fp);
    return retcode;
}
