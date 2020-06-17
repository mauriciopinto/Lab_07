#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILESIZE 1073741824
#define 2MB 2097152
#define 5MB 5242880

void random_read (FILE *fp) {
	char *read_buf = (char *) malloc (sizeof (char) * 2MB);
	fseek (fp, rand () % FILE_SIZE - 2MB, 0);
	fread (read_buf, 2MB, 1, fp);
}

void random_write (FILE *fp) {
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c = alpha[rand () % strlen (alpha)];
	fwrite (alpha[rand () % strlen (alpha)], 1, 2MB);
}

int main () {
	clock_t start, end;
	srand (time (NULL));
	char *filename = "1GB.bin";
	FILE *fp = open (filename, "rb+");

	start = clock ();
	do {
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
