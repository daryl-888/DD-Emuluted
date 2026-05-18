//set chip8 function pointer table
#include "../../include/chip8.h"
#include "/home/daryl/Projects/DungeonDwellers/DD-emulator/DD-Emuluted/src/system/memory.h"

#include <random>
#include <chrono>

Chip8::Chip8()

    : randGen(std::chrono::system_clock::now().time_since_epoch().count())
{

    pc = START_ADDRESS;

    for(unsigned int i = 0; i < FONTSET_SIZE; ++i)
    {
        memory[FONTSET_START_ADDRESS+i] = fontset[i];
    }

    randByte = std::uniform_int_distribution<uint8_t>(0, 255U);

    std::default_random_engine randGen;
    std::uniform_int_distribution<uint8_t> randByte;


}
