/*      wunzip.c
        takes in a compressed file and writing (to standard output again)
	the uncompressed results

        author:	Athena Evans
        date:	Jan 29, 2020
        class:	CIS3207
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// main
int main(int agrc, char *argv[]){
	int a = agrc;
	if(1<a){ // argv[0] is system call wunzip
		int size = 1000;
		char line[size];
                FILE *f = fopen(argv[1], "r");
                if(f == NULL) printf("wcat cannot open %s\n", argv[1]);
                else{
			while( fgets(line, size, f) ){
				int c;
				for(int i=0; i<size; i++){
					while( isdigit( *(line+i) ) ){
						c++;
						i++;
					}
					for(int j=0; j<c; j++){
						printf("%c", *(line+i) );
					}
				}
			}
		}
		if( f != NULL ) fclose(f); // throws err when argv is not a file

	}
	else{ // technically false, no args besides wcat
		printf("\twunzip: file1\n");
		exit(1);
	}
        return 0;
}
