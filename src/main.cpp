#include <windows.h>
#include <thread>

#include "memory.h"
#include "overlay.h"
#include "config.h"

int main() {
    SetConsoleTitle("Fortnite Ultimate Free");
    while (!Memory::Attach("FortniteClient-Win64-Shipping.exe"))
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    Config::LoadProfile(Config::Current());
    Overlay::Init();
    Overlay::Run();
    return 0;
}
