#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FILE_SIZE 1288490188
#define TWO_MB 2097152
#define FIVE_MB 5242880

void random_read (FILE *fp) {
	char *read_buf = (char *) malloc (sizeof (char) * TWO_MB);
	fseek (fp, rand () % FILE_SIZE - TWO_MB, 0);
	fread (read_buf, TWO_MB, 1, fp);
	free (read_buf);
}

void random_write (FILE *fp) {
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c = alpha[rand () % strlen (alpha)];
	fseek (fp, rand () % FILE_SIZE - TWO_MB, 0);
	fwrite ((void *) &c, 1, TWO_MB, fp);
}

void sequential_read (FILE *fp) {
	char *read_buf = (char *) malloc (sizeof (char) * TWO_MB);
        fseek (fp, rand () % FILE_SIZE - TWO_MB, 0);
        fread (read_buf, TWO_MB, 1, fp);
	free (read_buf);
}

void sequential_write (FILE *fp) {
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char c = alpha[rand () % strlen (alpha)];
        fwrite ((void *) &c, 1, TWO_MB, fp);
} 

void random_rw (FILE *fp) {
	char *read_buf = (char *) malloc (sizeof (char) * TWO_MB);
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char c = alpha[rand () % strlen (alpha)];
	int i = rand () % 2;
	if (i == 0)
		fread (read_buf, FIVE_MB, 1, fp);
	else 
		fwrite ((void *) &c, 1, FIVE_MB, fp);
        free (read_buf);
}

int main () {
	time_t start, end;
	srand (time (NULL));
	char *filename = "sample.txt";
	long int t = 2;
	long int elapsed;
	FILE *fp = fopen (filename, "rb+");

	start = time(NULL);
	do {
		random_read (fp);
		end = time (NULL);
		elapsed = (end - start);
	} while (elapsed < t);
	
	//printf ("finished random reads\n");
	start = time (NULL);
	do {
		random_write (fp);
		end = time (NULL);
		elapsed = (end - start);
	} while (elapsed < t);

	//printf ("finished random writes\n");
	fseek (fp, 0, 0);
	start = time (NULL);
	do {
		sequential_write (fp);
		end = time(NULL);
		elapsed = (end - start);	
	} while (elapsed < t);

	//printf ("finished sequential reads\n");
	fseek (fp, 0, 0);
	start = time (NULL);
        do {
                sequential_read (fp);
                end = time (NULL);
		elapsed = (end - start);
        } while (elapsed < t);
	//printf ("finished sequential writes\n");
	
	do {
		random_rw (fp);
		end = time (NULL);
		elapsed = (end - start);
	} while (elapsed < t);
	fclose (fp);
}
