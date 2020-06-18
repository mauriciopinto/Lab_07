#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1288490188

int main () {
	FILE *fp;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	fp = fopen ("sample.txt", "w+");
	for (int i = 0; i < SIZE; i++) {
		char c = alpha[rand () % strlen (alpha)];
		fwrite ((void *) &c, 1, 1, fp);
	}
	fclose (fp);
}	
