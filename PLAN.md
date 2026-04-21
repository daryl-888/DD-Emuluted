# Virtual 8bit Machine - Project Plan

**Estimated Duration:** 4-6 weeks  
**Team Size:** 3  
**Stack:** C++, SDL2

---

## Overview

The project is split across three roles, each covering a different part of the emulator. Since all three parts rely on the same shared data structure, the team needs to align on that first before any development starts. From there, each member can work through their section on their own branch.

---

## Phase 0 - Shared Struct Agreement

The team goes through the CHIP-8 spec together before writing any code. The goal is to understand what state the machine tracks and settle on naming so everything fits together later. One member commits a header file with just the struct once the team has agreed. Nothing else is added at this point.

A good starting point, specifically the Memory, Registers, Stack, Timers, Display, and Keyboard sections:

https://tobiasvl.github.io/blog/write-a-chip-8-emulator/

---

## Phase 1 - Development

Each member works on their own branch in parallel once Phase 0 is done.

**Person 1 - CPU / Opcodes (Daryl)**
Covers the fetch-decode-execute cycle, all CHIP-8 instructions, registers, and the stack. This is the largest section of the three, budgeted at around 3-4 weeks.

**Person 2 - Display / Input (Jimmy)**
Covers rendering through SDL2 and keyboard input mapping. Budgeted at around 1-2 weeks.

**Person 3 - Memory / Audio / Integration (Michael)**
Covers ROM loading, font data, timers, and audio. Michael also owns `main.cpp` and is responsible for bringing all three parts together. Budgeted at around 2-3 weeks.

---

## Phase 2 - Integration

Michael connects all components in `main.cpp` after Daryl and Jimmy have finished. The first test should be a ROM that only needs to draw to the screen, no input required, just to confirm everything is talking to each other before moving on.

---

## Branching Rules

- Nothing is pushed directly to `main`. All changes go through a pull request.
- Each member works on their own branch.
- Michael's integration pull request is the last one merged.

---

## References

- https://chip-8.github.io/links/
- https://tobiasvl.github.io/blog/write-a-chip-8-emulator/
- https://austinmorlan.com/posts/chip8_emulator/
