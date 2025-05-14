#ifndef BYTECODE_H
#include BYTECODE_H

typedef enum {
  OP_NOP,
  OP_PUSH_INT,
  OP_PUSH_STR,
  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV,
  OP_PRINT,
  OP_STORE_VAR,
  OP_LOAD_VAR,
  OP_JMP,
  OP_CALL,
  OP_RET,
  OP_STOP
} OpCode;

typedef struct{
  OpCode opcode;
  int operand;
}Instruction;

#endif
