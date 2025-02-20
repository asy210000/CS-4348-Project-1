#include <stdio.h>

// Registers
int Base = 0;  // Base Register
int PC = 0;    // Program Counter
int IR0 = 0;   // Instruction Register 0 (OP Code)
int IR1 = 0;   // Instruction Register 1 (Argument)
int AC = 0;    // Accumulator Register
int MAR = 0;   // Memory Address Register
int MBR = 0;   // Memory Buffer Register

//function protoypes
int* mem_read(int addr);
void mem_write(int addr, int* data);

void fetch_instruction(int addr) {
    int* instruction = mem_read(addr);  // reads memory and returns a pointer to int[2]
    IR0 = instruction[0];  // Opcode
    IR1 = instruction[1];  // Argument
}

void execute_instruction() {
    switch(IR0) {
        case 0: // exit
            break;

        case 1: // load_const
            AC = IR1;
            break;

        case 2: // move_from_mbr
            AC = MBR;
            break;

        case 3: // move_from_mar
            AC = MAR;
            break;

        case 4: // move_to_mbr
            MBR = AC;
            break;

        case 5: // move_to_mar
            MAR = AC;
            break;

        case 6: // load_at_addr
            {
                int* load_result = mem_read(MAR);
                MBR = load_result[1];
                break;
            }

        case 7: // write_at_addr
            {
                int* mem_location = mem_read(MAR);
                mem_location[1] = MBR;
                break;
            }

        case 8: // add
            AC += MBR;
            break;

        case 9: // multiply
            AC *= MBR;
            break;

        case 10: // and
            AC = AC && MBR ? 1 : 0; // if AC and MBR are both non-zero, then AC = 1, else AC = 0
            break;

        case 11: // or
            AC = AC || MBR ? 1 : 0;
            break;

        case 12: // ifgo
            if (AC == 0) {
                PC = IR1 + Base - 1;
            } else {
                PC++; // Skip the next instruction
            }
            break;

        case 13: // sleep
            // Do nothing. Just advance the program counter.
            break;

        default:
            printf("Invalid Opcode: %d\n", IR0);
            break;
    }
}

int mem_address(int l_addr) {
    return Base + l_addr;
}

int clock_cycle() {
    fetch_instruction(mem_address(PC));  // Fetch instruction from current PC relative to Base
    execute_instruction();  // Execute the fetched instruction
    PC++;
    int* data = mem_read(MAR);

    // If exit opcode is encountered, return 0
    if (IR0 == 0) {
        return 0;
    }
    return 1;
}


