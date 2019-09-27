#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int state = 0;

void reorient() {
    // change display orientation

    switch (state) {
        case 0:
            system("xrandr --output eDP-1 --rotate normal");

            system("xsetwacom set 'Wacom HID 48ED Finger touch' rotate none");

            break;
        case 1:
            system("xrandr --output eDP-1 --rotate inverted");

            system("xsetwacom set 'Wacom HID 48ED Finger touch' rotate half");

            break;
        default:
            break;
    }

    system("nitrogen --restore");
}

int main (int argc, char const *argv[]) {
    FILE* orient = popen("monitor-sensor", "r");

    // read in accelerometer data

    char line[64];

    char test[] = "Accelerometer orientation changed: ";

    while (fgets(line, 64, orient)) {
        char* out = strstr(line, test);

        if (out) {
            out += sizeof(test) - 1;

            switch (out[0]) {
                case 'n':
                    state = 0;

                    reorient();

                    break;
                case 'b':
                    state = 1;
                    
                    reorient();

                    break;
                default:
                    break;
            }
        }
    }

    pclose(orient);
}

