#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define N 850000000
#define MINUTES 1

int main (void) {
    sleep (60 * MINUTES);
    long *buffer_1 = (long *) malloc (sizeof (long) * N);
    long *buffer_2 = (long *) malloc (sizeof (long) * N);
    long *buffer_3 = (long *) malloc (sizeof (long) * N);
    long *buffer_4 = (long *) malloc (sizeof (long) * N);
    
    srand(time(NULL));

    time_t start_time = time(NULL);
    long i, b;
    long j;
    while (time(NULL) - start_time < MINUTES * 60) {
	b = rand () % 4 + 1;
	i = rand () % N;
	switch (b) {
		case 1: ;
			j += buffer_1[i];
			break;
		case 2: ;
                        j += buffer_2[i];
                        break;
		case 3: ;
                        j += buffer_3[i];
                        break;
		case 4: ;
                        j += buffer_4[i];
                        break;
	}
    }
    free (buffer_1);
    free (buffer_2);
    free (buffer_3);
    free (buffer_4);

    return 0;
}
