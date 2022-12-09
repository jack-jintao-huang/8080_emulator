/*
Header file for the emulator. Contains data structures, and function
headers.
*/
#ifndef EMULATOR_8080
#define EMULATOR_8080

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/*
8080 Condition codes. Set after a completed instruction. Used by conditional branching instructions.
*/
typedef struct ConditionCodes {
    uint8_t z: 1;       // zero. z = 1 if res = 0
    uint8_t s: 1;       // sign. s = 1 if bit7 = 1
    uint8_t p: 1;       // parity. p = 1 if even
    uint8_t cy: 1;      // carry. cy =1 if need a carry
    uint8_t ac: 1;      // auxillary carry. used mostly for binary coded decimal maths
    uint8_t pad: 3;     
} ConditionCodes;

typedef struct State8080
{
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
    uint16_t sp;
    uint16_t pc;
    uint8_t *memory;
    ConditionCodes cc;
    uint8_t int_enable;
} State8080;

/*
Emulates the 8080 cpu. Finds the current instruction in memory,
executes the opcode, and increment pc by 1
*/
int emulate8080Op(State8080* state);


#endif