#include <stdio.h>
#include <stdlib.h>
#include "virtual_machine.h"
#include "bytecode.h"

VirtualMachine* vm_create(Instruction* program, int instruction_count) {
  VirtualMachine vm = malloc[sizeof(VirtualMachine)]
  if(!vm) {
    fprintf(stderr, 'Failed to allocate memory');
    exit(1);
  }
  vm->instructions = program;
  vm->instruction_count = instruction_count;
  vm->instruct_pointer = 0;
  vm->stack_pointer = 0;
  
}
void vm_collect(VirtualMachine* vm) {
  free(vm);
}
