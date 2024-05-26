#include <iostream>
#include <chrono>
#include <thread>

#define BEEP_COUNT 100
#define BEEP_REPEAT_DELAY 500

void playBeepSounds(unsigned int count,
                    unsigned int repeatDelay = BEEP_REPEAT_DELAY) {
    for(auto n = 0; n < count; n++) {
        std::cout << "beep " << n + 1 << '\a' << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(repeatDelay));
    }
}

int main() {
    playBeepSounds(BEEP_COUNT);
    
    return 0;
}
