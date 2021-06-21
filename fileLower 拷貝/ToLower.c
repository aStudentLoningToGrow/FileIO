#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char** argv){
	
	FILE* fin = fopen(argv[1], "r");; 
	FILE* fout = fopen("dest.txt", "w+"); 
	 
	char c; 
	while(( c = fgetc(fin)) != EOF){ 
	    if(isupper(c)){ 
	        c = tolower(c); 
	    } 
	    fprintf(fout,"%c",c); 
	} 
	 
	fclose(fout); 
	fclose(fin);
	remove(argv[1]);
	rename("dest.txt",argv[1]);
}
