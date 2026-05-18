<<<<<<< Updated upstream
=======
//include all opcodes
#include "../../include/chip8.h"
#include "/home/daryl/Projects/DungeonDwellers/DD-emulator/DD-Emuluted/src/system/memory.h"
#include <cstring>

// Do nothing
void OP_NULL();

// CLS
void Chip8::OP_00E0()
{
	memset(video, 0, sizeof(video));
}

// RET - sets program counter at the top of stack, then subtracts 1 from SP
void Chip8::OP_00EE()
{
    pc = stack[sp];
    --sp;
}

// JP address
void Chip8::OP_1nnn()
{
    uint16_t address = opcode & 0x0FFFu;
    pc = address;
}

// CALL address
void Chip8::OP_2nnn(){}

// SE Vx, byte
void Chip8::OP_3xkk(){}

// SNE Vx, byte
void Chip8::OP_4xkk(){}

// SE Vx, Vy
void Chip8::OP_5xy0(){}

// LD Vx, byte
void Chip8::OP_6xkk(){}

// ADD Vx, byte
void Chip8::OP_7xkk(){}

// LD Vx, Vy
void Chip8::OP_8xy0(){}

// OR Vx, Vy
void Chip8::OP_8xy1(){}

// AND Vx, Vy
void Chip8::OP_8xy2(){}

// XOR Vx, Vy
void Chip8::OP_8xy3(){}

// ADD Vx, Vy
void Chip8::OP_8xy4(){}

// SUB Vx, Vy
void Chip8::OP_8xy5(){}

// SHR Vx
void Chip8::OP_8xy6(){}

// SUBN Vx, Vy
void Chip8::OP_8xy7(){}

// SHL Vx
void Chip8::OP_8xyE(){}

// SNE Vx, Vy
void Chip8::OP_9xy0(){}

// LD I, address
void Chip8::OP_Annn(){}

// JP V0, address
void Chip8::OP_Bnnn(){}

// RND Vx, byte
void Chip8::OP_Cxkk(){}

// DRW Vx, Vy, height
void Chip8::OP_Dxyn(){}

// SKP Vx
void Chip8::OP_Ex9E(){}

// SKNP Vx
void Chip8::OP_ExA1(){}

// LD Vx, DT
void Chip8::OP_Fx07(){}

// LD Vx, K
void Chip8::OP_Fx0A(){}

// LD DT, Vx
void Chip8::OP_Fx15(){}

// LD ST, Vx
void Chip8::OP_Fx18(){}

// ADD I, Vx
void Chip8::OP_Fx1E(){}

// LD F, Vx
void Chip8::OP_Fx29(){}

// LD B, Vx
void Chip8::OP_Fx33(){}

// LD [I], Vx
void Chip8::OP_Fx55(){}

// LD Vx, [I]
void Chip8::OP_Fx65(){}
>>>>>>> Stashed changes
