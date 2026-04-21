# Virtual 8bit Machine Group Project

We will be creating an emulator that can decode roms into something playable. It will simulate an 8bit chip and emulating a CPU, memory, and manipulate the sound visual instructions.

## Getting started

### Prerequisites 

- [Visual Studio Code](https://code.visualstudio.com/download)
- [Git](https://git-scm.com/)

### Roles

#### Person 1 — CPU / Opcodes (Daryl)
Responsible for the core of the emulator. This includes implementing the fetch-decode-execute cycle, all ~35 CHIP-8 instructions, registers, the program counter, and the stack. Every other component depends on this working correctly.

#### Person 2 — Display / Input ()
Responsible for rendering the 64x32 pixel framebuffer using SDL2 and mapping the host keyboard to CHIP-8's 16-key hex keypad. Works closely with the CPU role to handle draw instructions.

#### Person 3 — Memory / Audio / Integration ()
Responsible for the 4KB memory map, loading ROM files, storing the built-in font sprites, and implementing the sound timer beep via SDL2. Also owns `main.cpp` and is responsible for connecting all components into a working program.

---

> **Note:** All three roles share a common `Chip8` struct. Must agree on struct

### Setting up your workspace

> [!Warning]
> Make sure to never force push into main branches.

## Relevant links

- [CHIP-8 Resources](https://chip-8.github.io/links/)

## References

- [Building a CHIP-8 Emulator](https://austinmorlan.com/posts/chip8_emulator/)
- [Guide to making a CHIP-8 Emulator](https://tobiasvl.github.io/blog/write-a-chip-8-emulator/)
