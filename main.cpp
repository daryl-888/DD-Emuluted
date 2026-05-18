#include <chrono>
#include <iostream>
#include "include/chip8.h"
#include "src/display/renderer.cpp"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <Scale> <Delay> <ROM>\n";
        std::cerr << "  Scale : video scale factor  (e.g. 10)\n";
        std::cerr << "  Delay : cycle delay in ms   (e.g. 2)\n";
        std::cerr << "  ROM   : path to ROM file\n";
        return EXIT_FAILURE;
    }

    int        videoScale = std::stoi(argv[1]);
    int        cycleDelay = std::stoi(argv[2]);
    char const* romFile   = argv[3];

    Platform platform(
        "CHIP-8 Emulator",
        VIDEO_WIDTH  * videoScale,
        VIDEO_HEIGHT * videoScale,
        VIDEO_WIDTH,
        VIDEO_HEIGHT
    );

    Chip8 chip8;
    chip8.LoadROM(romFile);

    int  videoPitch    = sizeof(chip8.video[0]) * VIDEO_WIDTH;
    auto lastCycleTime = std::chrono::high_resolution_clock::now();
    bool quit          = false;

    while (!quit)
    {
        quit = platform.processInput(chip8.keypad);

        auto  now = std::chrono::high_resolution_clock::now();
        float dt  = std::chrono::duration<float, std::chrono::milliseconds::period>(now - lastCycleTime).count();

        if (dt > cycleDelay)
        {
            lastCycleTime = now;
            chip8.Cycle();
            platform.update(chip8.video, videoPitch);
        }
    }

    return EXIT_SUCCESS;
}
