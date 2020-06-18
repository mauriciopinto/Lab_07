#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define N 1288490188
#define MINUTES 1

int main (void) {
    //sleep (60 * MINUTES);
    int *buffer = (int *) malloc (sizeof (int) * N);
    srand(time(NULL));

    time_t start_time = time(NULL);

    while (time(NULL) - start_time < MINUTES * 60) {
        int i = rand () % N;
    	int j = buffer[i];
    }

    return 0;
}
