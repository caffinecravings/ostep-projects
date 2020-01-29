/*      wgrep.c
        This tool looks through a file, line by line, trying to find a
	user-specified search term in the line. If a line has the word within
	it, the line is printed out, otherwise it is not.

        author: Athena Evans
        date:	Jan 29, 2020
        class:	CIS3207
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int agrc, char *argv[]){
	int a = agrc;
	FILE *k = fopen(argv[1],"r"); // k==NULL means search key, k!=NULL means file/no search key
	if(k != NULL){ // normal search term not found, first arg is a file
		printf("No search key given\n");
		printf("No lines matching\n");
		exit(1);
	}
	else if(a==2){ // search term and no file case, file direct to stdin
		const char* k = argv[1];
		printf("The search key is: %s\n", k);
		printf("Enter text to search, to stop writing type [exit]\n\t");
		char fakeFile[1000];
		while( fgets(fakeFile, 1000, stdin) ){
			if( strstr(fakeFile, k)!= NULL) printf("\tThe key, %s, was found in: \n\t%s\n", k, fakeFile);
			else if ( strstr(fakeFile, "exit") != NULL ) break;
			else printf("\t");
		}
		exit(1);
	}
	else if(2<a){ // regular wgrep case, given key search files
		const char* key = argv[1]; // agrv[0] is the wgrep call, first term after is the key
		int i = 2,  size = 1000; // i=2, 0 is wgrep, 1 is key, 2 is the first file ...
		char line[size];
		printf("The search key is: %s\n", key);
		while(i<=a){ // while only when 3 or more args, by design
			FILE *f = fopen(argv[i], "r");
			if(f == NULL) {
				printf("\twgrep cannot open file %s\n", argv[i]);
				exit(1);
			}
			else{
				while( fgets(line, size, f) ){
					if( strstr(line, key)!= NULL) printf("\t%s\n", line);
					// test -- reads all lines
					// else printf("---\n\t");
				}
			}
			i++;
			fclose(f); // throws seg fault in case of not a file
			exit(0);
		}
	}
	else{ // a == 1, only wgrep called
		printf("wgrep: searchterm [file ...]\n");
		exit(1);
	}
	fclose(k);
	return 0;
}
