#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define N 1024
#define MINUTES 1

int main (void) {
    sleep (60 * MINUTES);
    char *buffer = (char *) malloc (sizeof (char) * 8589934592);
    srand(time(NULL));

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < MINUTES * 60) {
        buffer[rand() % N];
    }

    return 0;
}
