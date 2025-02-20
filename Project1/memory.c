#include <stdio.h>
#include <stdlib.h>


// Defining the memory as a 2D array
int memory[1024][2];

// Function to read from the memory
int* mem_read(int addr) {
    if (addr < 0 || addr >= 1024) {  // Checking for invalid memory access
        fprintf(stderr, "Error: Memory address out of bounds.\n");
        exit(1);
    }
    return memory[addr];
}

// Function to write data into the memory
void mem_write(int addr, int* data) {
    if (addr < 0 || addr >= 1024) {
        fprintf(stderr, "Error: Invalid memory address or data.\n");
        exit(1);
    }
    memory[addr][0] = data[0];
    memory[addr][1] = data[1];
}

