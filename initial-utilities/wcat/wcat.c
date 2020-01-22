/*	wcat.c
	a command line program, in the directory wcat use to read files
        ex -    to run wcat on test.txt
                ./wcat test.txt

	author:	Athena Evans
	date:	Jan 29, 2020
	class:	CIS3207
*/
#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char *argv[]){
	int a = agrc;
	if(1<a){
		int i = 0, size = 10000;
		char line[size];
		while(i<a){
			FILE *f = fopen(argv[i], "r");
			if(f == NULL) printf("wcat cannot open file\n");
			else{
				while( fgets(line, size, f) ){
					printf("%s\n", line);
				}
			}
			i++;
			fclose(f);
		}
	}
	else{
		printf("No arguments given\n");
	}
	return 0;
}
