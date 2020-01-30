/*      wzip.c
        a file compression tool, when you encounter n characters of the same
	type in a row, the compression tool (wzip) will turn that into the
	number n and a single instance of the character.

        author:	Athena Evans
        date:	Jan 29, 2020
        class:	CIS3207
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main
int main(int agrc, char *argv[]){
	int a = agrc;
	if(1<a){ // wzip on std args, 0 is wzip, 1 is file to compress, 2 is zip file name
		int size = sizeof(argv[1]);
		char line[size];
                FILE *f = fopen(argv[1], "r");
                if(f == NULL) printf("wzip cannot open %s\n", argv[1]);

		while( fgets(line, size, f) ){
			int i, c;
       			for (i = 0; i < size; i++) {// traverse the input string one by one
              			c = 1;// count the number of occurrences of the new character
                		while ( (i+1<size) && ( *(line+i) == *(line+i+1) ) ) {
                       			c++;
                       			i++;
               		 	}
		                fwrite( &c, sizeof(c), 1, stdout);// store c in a character array counted[]
               			printf( "%c", *(line+i)); // store character in ret
   			}
		}

		if( f != NULL ) fclose(f); // throws err when argv is not a file
	}
	else{ // technically false, no args besides wcat
		printf("\twzip: file1>[file2 ...]\n");
		exit(1);
	}
	return 0;
}
