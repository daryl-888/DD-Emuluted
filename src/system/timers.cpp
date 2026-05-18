//cycle
#include <cstdint>
#include "chip8.h"

viod Chip8::Cycle(){

    opcode = (memory[pc] << 8u) | memory[pc + 1];

    pc += 2;

    ((*this).*(table[(opcode & 0xF00u) >> 12u]))();

    if(delatTimer > 0)
    {
        --delayTimer;
    }

    if(soundTimer > 0)
    {
        --soundTimer;
    }
}