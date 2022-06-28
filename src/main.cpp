#include <iostream>

Uint32 frame_start;
Uint32 frame_end;
Uint32 frame_duration;
float target_frame_duration = 1000/60; // milliseconds per frame at 60 frames per second.

while (true) {
    frame_start = GetCurrentTimeMS(); // Current time in milliseconds
    Input();
    Update();
    Render();
    frame_end = get_current_time_in_ms();

    frame_duration = frame_end - frame_start;

    if (frame_duration < target_frame_duration ) {
        Sleep(target_frame_duration - frame_duration);
    }
}