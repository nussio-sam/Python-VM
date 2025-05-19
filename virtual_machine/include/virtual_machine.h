#ifndef VIRTUAL_MACHINE_H
#define VIRTUAL_MACHINE_H

#include <stdint.h>
#include <stdbool.h>
#include "bytecode.h"

#define STACK_SIZE 8192
#define MAX_CALL_DEPTH 1024
//This is roughly equivalent to cpython's recursion depth limit

typedef struct {
  int32_t stack[STACK_SIZE];
  int32_t stack_pointer;

  Instruction* instructions;
  int instruction_count;
  int instruct_pointer;
} VirtualMachine;

typedef enum {
  VM_GOOD = 0,
  VM_ERR_BAD_OPCODE,
  VM_ERR_STACK_OVERFLOW,
  VM_ERR_STACK_UNDERFLOW,
  VM_ERR_ZERO_DIV,
  VM_ERR_BAD_INPUT,
  VM_ERR_OUT_OF_MEMORY
} VMError;

VirtualMachine vm_create(Instruction* program, int instruction_count);
void vm_collect(VirtualMachine* vm);
void vm_run(VirtualMachine* vm);
void debug_print(VirtualMachine* vm); //prints straight bytecode

Instruction* load_vmc(const char* filename, int* out_count);
