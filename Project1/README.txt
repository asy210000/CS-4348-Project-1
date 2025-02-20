READ ME: CS-4348 Project 1 - Simple Hardware Simulator
Name: Austin Yatco
NetID: 2021616010

QUICK START:
1. Adjust config settings in main.c as described in the CONFIG section.
2. Run make to compile all files.
3. Execute with ./sim.exe.

DESCRIPTION:
This project simulates the hardware of a simplified computer, including disk, memory, and CPU functionalities. It reads a limited instruction set from a text file that mimics assembly language. It translates the program's assembly-like instructions into opcode and argument pairs, and then simulates the execution of those instructions.

FILES:
1. disk.c - Handles the translation of instructions from a text file into opcode and argument pairs.
2. memory.c - provides a memory array of size 1024x2 to store and retrieve instructions and data.
3. cpu.c - Simulates the execution of instructions stored in memory; fetches, decodes, and executes the instructions.
4. main.c - The main driver; loads the program into memory and does the execution simulation, which runs cycle by cycle. Also contains the function prototypes (which commonly should be in a separate header files).
5. Makefile - Used for compiling all of the source files together.

CONFIG:
1. **File Paths**: The simulator uses text files "program_add.txt" and "program_if.txt" for instructions. Make sure the file paths in `main.c` (line 21) point to the correct location. For example, adjust `char fname[] = "program_add.txt";` to match the directory path of the instruction text files.
   
2. **Memory Address & PC Counter**: Before running a new instruction set, ensure that the starting memory address and the Program Counter (PC) are correctly configured in `main.c`.
    - Set the starting memory address with `int addr = 4;` (default is 4, line 24).
    - Adjust the Program Counter (PC) with `int PC = 4;`. Ensure this value matches the starting memory address you've set (default is 4, line 25).

For example:
    for "program_add.txt", keep the default values of 4 for both the addr and PC.
    for "program_if.txt", change the values of addr and PC to 1.
    

HOW TO RUN:
1. Use the Makefile I've created to compile all the source files (disk.c, memory.c, cpu.c, main.c) and run it by typing "make".
2. It should create an executable named "sim.exe". Run it by typing "./sim"
or
3. Manually compile with gcc by entering this command - `gcc main.c disk.c memory.c cpu.c -o sim`
4. Then, run it by typing `./sim`