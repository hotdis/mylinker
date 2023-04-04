#include "include/main.h"

int main(int argc, char **argv) {
	FILE *fp;
    int retcode = 0;
    struct elf_header hdr; struct elf_section sec; 

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
	
    //  
    fseek(fp, 0, SEEK_SET);
    elf_read_header(fp, &hdr);
    printf("section headers starting at offset 0x%lx\n", hdr.sh_off);
    fseek(fp, hdr.sh_off, SEEK_SET);
    elf_read_section(fp, &sec);

    int num_sec = hdr.sh_num;
    if (!num_sec) 
        num_sec = sec.size;
    printf("number of section %d\n", num_sec);

end:
	fclose(fp);
    return retcode;
}
