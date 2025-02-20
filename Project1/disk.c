#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mem_write(int addr, int* data); //function prototype

void translate(char* instruction, int translation[2]) {

    char* command = strtok(instruction,"\n \r"); // split to grab the first word
    char* argument = strtok(NULL,"\n \r");

    if (strncmp(command, "//", 2) == 0) {
        translation[0] = -1;  // for comments
        translation[1] = 0;
        return;
    }

    if (strcmp(command, "exit") == 0) {
        translation[0] = 0;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "load_const") == 0) {
        translation[0] = 1;
        translation[1] = atoi(argument); //converts string to integer
        return;
    }
    if (strcmp(command, "move_from_mbr") == 0) {
        translation[0] = 2;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "move_from_mar") == 0) {
        translation[0] = 3;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "move_to_mbr") == 0) {
        translation[0] = 4;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "move_to_mar") == 0) {
        translation[0] = 5;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "load_at_addr") == 0) {
        translation[0] = 6;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "write_at_addr") == 0) {
        translation[0] = 7;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "add") == 0) {
        translation[0] = 8;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "multiply") == 0) {
        translation[0] = 9;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "and") == 0) {
        translation[0] = 10;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "or") == 0) {
        translation[0] = 11;
        translation[1] = 0;
        return;
    }
    if (strcmp(command, "ifgo") == 0) {
        translation[0] = 12;
        translation[1] = atoi(argument) - 1;
        return;
    }
    if (strcmp(command, "sleep") == 0) {
        translation[0] = 13;
        translation[1] = 0;
        return;
    }
    
    printf("Unknown command: %s\n", command);
    exit(1);
}

void load_prog(char fname[], int addr) {
    FILE* file_pointer = fopen(fname, "r");
    if (!file_pointer) {
        perror("Error opening file");
        exit(1);
    }
    
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int translation[2];

    while((read = getline(&line, &len, file_pointer)) != -1) {
        translate(line, translation);

        // Skip comments
        if (translation[0] == -1) {
            continue;
        }
        // Store the translated values into memory
        mem_write(addr, translation);
        addr++;  // Increment the address for the next instruction
    }

    free(line);
    fclose(file_pointer);
}