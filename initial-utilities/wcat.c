/* wcat.c
	think about what this is supposed to do lol



**/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char str[100];
	for(int i = 0; i<argc; i++){
		FILE *fp = fopen("agrv[i]","r");
		if( fp == NULL ){
			printf("\n\tcannot open file");
			exit(1);
		}
		else{
			if( fgets(str, 100, fp) != NULL){
			puts(str);
			}
		}
		fclose(fp);
	}
	exit(0);
	return 0;
}
