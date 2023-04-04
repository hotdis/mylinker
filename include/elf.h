#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#ifndef __MYLINKER_ELF_H__
#define __MYLINKER_ELF_H__

struct elf_header {
    uint8_t  ident[16];
    uint16_t type;
    uint16_t machine;
    uint32_t version;
    uint64_t entry;
    uint64_t ph_off;
    uint64_t sh_off;
    uint32_t flags;
    uint16_t eh_size;
    uint16_t phEnt_size;
    uint16_t ph_num;
    uint16_t shEnt_size;
    uint16_t sh_num;
    uint16_t shStrndx;
};

struct elf_section {
    uint32_t name;
    uint32_t type;
    uint64_t flags;
    uint64_t addr;
    uint64_t offset;
    uint64_t size;
    uint32_t link;
    uint32_t info;
    uint64_t addr_align;
    uint64_t ent_size;
};

void elf_read_header(FILE *fp, struct elf_header *dhr);
void elf_read_section(FILE *fp, struct elf_section *sec);

#endif