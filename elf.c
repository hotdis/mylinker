#include "include/elf.h"

#define msg_err(type) "linker cann't read enough bytes (%ld) to " #type " from file.\n"
#define ELF_READ(com, fp, target) do {\
    if (fread(target, 1, sizeof(struct elf_ ## com), fp) < sizeof(struct elf_ ## com)) {\
        fprintf(stderr, msg_err(elf_ ## com), sizeof(struct elf_ ## com));\
        fclose(fp);\
        exit(-1);\
    }\
} while(0)

void elf_read_header(FILE *fp, struct elf_header *hdr)  
{ ELF_READ(header, fp, hdr); }
void elf_read_section(FILE *fp, struct elf_section *sec) 
{ ELF_READ(section, fp, sec); }

#undef msg_err