/*	wcat.c
	a command line program, in the directory wcat use to read files line
	by line
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
	if(1<a){ // argv[0] is system call wcat
		int i = 1, size = 1000;
		char line[size];
		while(i<a){ // while only 2 or more args, no loop if only wcat given
                        FILE *f = fopen(argv[i], "r");
                        if(f == NULL) printf("wcat cannot open %s\n", argv[i]);
                        else{
				while( fgets(line, size, f) ){
					printf("%s\n", line);
				}
			}
			i++;
			if( f != NULL ) fclose(f); // throws err when argv is not a file
		}
	}
	else{ // technically false, no args besides wcat
		printf("No arguments given\n");
	}
	return 0;
}
