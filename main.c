#include <stdio.h>

int main(int argc, char **argv) {
	FILE *fp;

    if (argc < 2) { 
        fprintf(stderr, "lack of input files.\n");
        return -1;
    }
        
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "linker can't open the file %s.\n", argv[1]);
        return -1;
    }

	fclose(fp);
	return 0;
}
