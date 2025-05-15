#include <stdio.h>
#include <stdlib.h>
#include "virtual_machine.h"
#include "bytecode.h"

VirtualMachine* vm_create(Instruction* program, int instruction_count) {
  if (!program || instruction_count <= 0) {
    fprintf(stderr, "Invalid input parameters\n");
    exit(1);
  }
  
  VirtualMachine* vm = calloc(1, sizeof(VirtualMachine)); //better to zero-init for safety cuz Im not memory pooling manually
  if(!vm) {
    fprintf(stderr, "Failed to allocate memory\n");
    exit(1);
  }
  vm->instructions = program;
  vm->instruction_count = instruction_count;
  vm->instruct_pointer = 0; //not necessary but more readable
  vm->stack_pointer = 0;

  return vm;
  
}
void vm_collect(VirtualMachine* vm) {
  if(vm) {
    free(vm);
  } else {
    fprintf(stderr, "No VM running!\n");
    return;
  }
}
