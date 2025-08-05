#include <stdio.h>
#include <stdlib.h>
#include "bytecode.h"

const char* OP_NAMES[] = {
  "NOP",
  "PUSH_INT",
  "PUSH_STR",
  "ADD",
  "SUB",
  "MUL",
  "DIV",
  "PRINT",
  "STORE_VAR",
  "LOAD_VAR",
  "JMP",
  "CALL",
  "RET",
  "STOP"
};

void print_instruct(Instruction instruct, int index) {
  const char* name = "UNKNOWN";
  if (instruct.opcode >= 0 && instruct.opcode <= OP_STOP) {
    name = OP_NAMES[instruct.opcode];
  }
  printf("%04d: %-14s %d\n", index, name, instr.operand);
}

void disassemble(Instruction* program, int count) {
  for(int i = 0; i < count; i++) {
    print_instruct(program[i], i);
  }
}

Instruction* load_vmc(const char* filename, int* out_count) {
  FILE* vmc = fopen(filename, 'rb');
  if(!vmc) {
    fprintf(stderr, "Could not open VMC file %s\n", filename);
    return NULL;
  }

  int count;
  if (fread(&count, sizeof(int), 1, vmc) != 1) {
    fprintf(stderr, "Failed to read instruction count from %s\n", filename);
    fclose(vmc);
    return NULL;
  }
  Instruction* program = calloc(count, sizeof(Instruction));
  if (!program) {
    fprintf(stderr, "Out of Memory\n");
    fclose(vmc);
    return NULL;
  }
  
  if (fread(program, sizeof(Instruction), count, vmc) != count) {
    fprintf(stderr, "Failed to read instruction data from %s\n", filename);
    free(program);
    fclose(vmc);
    return NULL;
}

  *out_count = count;
  fclose(vmc)
  return program;
}
