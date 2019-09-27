#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char state[512];

int count = 1;

void reconfigure() {
    // change monitor configuration

    switch (count) {
        case 1:
            system("mons -o");
            break;
        case 2:
            system("mons -e right");
            break;
        default:
            break;
    }

    system("xsetwacom set 'Wacom HID 48ED Finger touch' MapToOutput eDP-1");

    system("nitrogen --restore");
}

int main (int argc, char const *argv[]) {
    while (1) {
        // read in output from mons command

        FILE* mons = popen("mons", "r");

        char line[64];

        while (fgets(line, 64, mons) != NULL) strcat(state, line);

        pclose(mons);

        // check for change in state

        int new_count = state[10] - '0';

        if (new_count != count) {
            count = new_count;

            reconfigure();
        }

        state[0] = '\0';

        // wait for 2 seconds

        sleep(1);
    }
}
