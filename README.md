# DD Emulated — CHIP-8 Emulator

A CHIP-8 emulator written in C++ with SDL2. Emulates the full CHIP-8 instruction set (35 opcodes) including display, keyboard input, delay/sound timers, and ROM loading.

## Prerequisites

- [CMake](https://cmake.org/) 3.16+
- [SDL2](https://www.libsdl.org/) development libraries
  - Ubuntu/Debian: `sudo apt install libsdl2-dev`
  - Arch: `sudo pacman -S sdl2`
  - macOS: `brew install sdl2`
  - Windows (vcpkg): `vcpkg install sdl2`

## Building

```sh
cmake -B build
cmake --build build
```

## Running a ROM

```sh
./build/DD_Emulated <Scale> <Delay> <ROM>
```

| Argument | Description | Example |
| --- | --- | --- |
| Scale | Window scale factor | `10` (640×320 window) |
| Delay | Cycle delay in milliseconds | `2` |
| ROM | Path to `.ch8` ROM file | `roms/ibm_logo.ch8` |

ROMs with spaces in the filename must be quoted:

```sh
./build/DD_Emulated 10 2 "roms/Tetris [Fran Dachille, 1991].ch8"
```

## Key Mapping

| CHIP-8 Key | Keyboard |
| --- | --- |
| 0 | X |
| 1–3 | 1, 2, 3 |
| 4–7 | Q, W, E, A |
| 8–B | S, D, Z, C |
| C–F | 4, R, F, V |
| Quit | ESC |

## Included ROMs

| File | Description |
| --- | --- |
| `ibm_logo.ch8` | IBM logo display test |
| `petdog.ch8` | Pet dog demo |
| `Tetris [Fran Dachille, 1991].ch8` | Tetris |

## Project Structure

```text
├── main.cpp                  # Entry point and main loop
├── include/chip8.h           # Chip8 class definition
├── src/
│   ├── cpu/
│   │   ├── cpu.cpp           # CPU init and opcode dispatch tables
│   │   └── opcodes.cpp       # All 35 CHIP-8 instruction implementations
│   ├── display/
│   │   ├── renderer.cpp      # SDL2 window and framebuffer rendering
│   │   └── input.cpp         # Keyboard input mapping
│   └── system/
│       ├── memory.h          # Memory constants and fontset
│       ├── rom_loader.cpp    # ROM file loading
│       ├── timers.cpp        # CPU cycle, delay/sound timers
│       └── audio.cpp         # Audio (sound timer)
└── roms/                     # Sample ROM files
```

## References

- [Building a CHIP-8 Emulator](https://austinmorlan.com/posts/chip8_emulator/)
- [Guide to making a CHIP-8 Emulator](https://tobiasvl.github.io/blog/write-a-chip-8-emulator/)
- [CHIP-8 Resources](https://chip-8.github.io/links/)
