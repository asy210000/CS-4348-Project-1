#include <stdio.h>

// Global Variables (extern if defined in another file)
extern int memory[1024][2];
extern int PC;

// Function prototypes for disk.c
void load_prog(char fname[], int addr);

// Function prototypes for memory.c
int* mem_read(int addr);
void mem_write(int addr, int* data);

// Function prototypes for cpu.c
void fetch_instruction(int addr);
void execute_instruction();
int mem_address(int l_addr);
int clock_cycle();

int main() {
    char fname[] = "program_add.txt"; // file path
    int running = 1;

    int addr = 4; //start at address # (Adjust accordingly)
    PC = 4; //PC Counter starts at # (Adjust accordingly)
    
    load_prog(fname, addr);

    while (running) {
        running = clock_cycle();
    }

    for (int i = addr; i < addr + 20; i++) {  // Print the first 20 locations in memory
        int* data = mem_read(i);
        printf("Memory[%d] - Opcode: %d Argument: %d\n", i, data[0], data[1]);
    }

    return 0;
}
