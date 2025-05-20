#include <stdio.h>
#include "virtual_machine.h"
#include "bytecode.h"

int main(int argc, char *argv[]) {
  VirtualMachine* vm = NULL;
  VMStatus status;

  //deal with creating program from python code HERE
  program = NULL;
  
  status = vm_create(&vm, program, sizeof(program) / sizeof(program[0]));
  if (status != VM_OK) {
    fprintf(stderr, "creating VM failure: %s\n", status);
    return 1;
  }

  vm_collect(vm);
  return 0;
}
