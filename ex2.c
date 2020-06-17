#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILE_SIZE 1073741824
#define TWO_MB 2097152
#define FIVE_MB 5242880

void random_read (FILE *fp) {
	char *read_buf = (char *) malloc (sizeof (char) * TWO_MB);
	fseek (fp, rand () % FILE_SIZE - TWO_MB, 0);
	fread (read_buf, FIVE_MB, 1, fp);
	printf ("%s\n", read_buf);
}

void random_write (FILE *fp) {
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c = alpha[rand () % strlen (alpha)];
	fwrite ((void *) &alpha[rand () % strlen (alpha)], 1, TWO_MB, fp);
}

void sequential_read (FILE *fp) {
	char *read_buf = (char *) malloc (sizeof (char) * TWO_MB);
        fseek (fp, rand () % FILE_SIZE - TWO_MB, 0);
        fread (read_buf, TWO_MB, 1, fp);
}

void sequential_write (FILE *fp) {
	
} 

int main () {
	clock_t start, end;
	srand (time (NULL));
	char *filename = "1GB.bin";
	FILE *fp = fopen (filename, "rb+");

	start = clock ();
	do {
		printf ("Reading 2MB\n");
		random_read (fp);
		end = clock ();
	} while (((double) (end - start) / CLOCKS_PER_SEC) < 60);

	start = clock ();
	do {
		random_write (fp);
		end = clock ();
	} while (((double) (end - start) / CLOCKS_PER_SEC) < 60);

	fclose (fp);
}
