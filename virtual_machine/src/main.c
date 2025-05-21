#include "virtual_machine.h"

int main(int argc, char *argv[]) {
    //deal with creating program from python code HERE
    Instruction program = { //example program for clarity
        OP_PUSH_INT,
        10,
    };

    VirtualMachine vm = vm_create(&program, sizeof(program));

    vm_collect(&vm);
    return 0;
}
