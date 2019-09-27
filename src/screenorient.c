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
            break;
        case 1:
            system("xrandr --output eDP-1 --rotate inverted");
            break;
        default:
            break;
    }

    system("nitrogen --restore");
}

int main (int argc, char const *argv[]) {
    FILE* orient = popen("monitor-sensor", "r");

    while (1) {
        // read in accelerometer data

        char line[64];

        while (fgets(line, 64, orient)) fprintf(stderr, line);

        // wait for 2 seconds

        sleep(1);
    }

    pclose(orient);
}

