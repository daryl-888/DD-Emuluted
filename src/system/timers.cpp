//cycle
#include "../../include/chip8.h"

void Chip8::Cycle(){

    opcode = (memory[pc] << 8u) | memory[pc + 1];

    pc += 2;

    ((*this).*(table[(opcode & 0xF000u) >> 12u]))();

    if(delayTimer > 0)
    {
        --delayTimer;
    }

    if(soundTimer > 0)
    {
        --soundTimer;
    }
}