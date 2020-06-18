#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define MINUTES 1

int main (void) {
    sleep (60 * MINUTES);
    char *buffer = (char *) malloc (sizeof (char) * INT_MAX);
    srand(time(NULL));

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < MINUTES * 60) {
        int i = rand () % INT_MAX;
    	char j = buffer[i];
    }

    return 0;
}
