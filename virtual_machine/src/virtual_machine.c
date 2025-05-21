#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "virtual_machine.h"
#include "bytecode.h"

VirtualMachine vm_create(Instruction* program, int instruction_count) {
  if (!program || instruction_count <= 0) {
    perror("Invalid input parameters\n");
    exit(1); //REMEMBER FOR DOCUMENTATION PLZ FUTURE ME
  }

  VirtualMachine* vm = calloc(1, sizeof(VirtualMachine)); //better to zero-init for safety cuz Im not memory pooling manually
  if(!vm) {
    perror("Failed to allocate memory\n");
    exit(1);
  }
  vm->instructions = program;
  vm->instruction_count = instruction_count;
  vm->instruct_pointer = 0; //not necessary but more readable
  vm->stack_pointer = -1;

  return *vm;

}
void vm_collect(VirtualMachine* vm) {
  if(vm) {
    free(vm);
  } else {
    perror("No VM running!\n");
    return;
  }
}
static bool push(VirtualMachine* vm, int32_t val) {
  if (vm->stack_pointer >= STACK_SIZE) {
    perror("Stack overflow!");
    return false;
  }
  vm->stack[vm->stack_pointer++] = val;
  return true;
}

static int32_t pop(VirtualMachine* vm) {
  if (vm->stack_pointer <= 0) {
    perror("Stack underflow");
    return 0;
  }
  return vm->stack[--vm->stack_pointer];
}

struct IntPair {
  int a;
  int b;
};
struct IntPair pop_two(VirtualMachine* vm) {
  struct IntPair result;
  result.a = pop(vm);
  result.b = pop(vm);
  return result;
}

void vm_run(VirtualMachine* vm) {
  while(vm->instruct_pointer < vm->instruction_count) {
    Instruction instr = vm->instructions[vm->instruct_pointer++];
    switch(instr.opcode) {
      case OP_NOP:
        break;
      case OP_PUSH_INT:
        push(vm, instr.operand);
        break;
      case OP_ADD:
        {
        struct IntPair operands = pop_two(vm);
        push(vm, operands.a + operands.b);}
        break;
      case OP_SUB:
      {
        struct IntPair operands = pop_two(vm);
        push(vm, operands.a - operands.b);}
        break;
      case OP_MUL:
      {
        struct IntPair operands = pop_two(vm);
        push(vm, operands.a * operands.b);}
        break;
      case OP_DIV:
      {
        struct IntPair operands = pop_two(vm);
        if( operands.b == 0) {
          perror("Division by zero");
          return;
        }
        push(vm, operands.a / operands.b);}
        break;
      case OP_PRINT:
        printf("%d\n", pop(vm));
        break;
      case OP_STORE_VAR:
        //ADD CODE HERE
        break;
      case OP_LOAD_VAR:
        //ADD CODE HERE
        break;
      case OP_JMP:
        vm->instruct_pointer = instr.operand;
        break;
      case OP_STOP:
        return;
      default:
        perror("Unknown opcode");
        exit(1);
    }
  }
}
