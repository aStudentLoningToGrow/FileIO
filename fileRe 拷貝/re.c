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
	char string[1024];
	int idx=0;
	while(( c = fgetc(fin)) != EOF){ 
	    string[idx] = c;
	    idx++; 
	} 
	idx--;
	for(int i=idx-1;i>=0;i--){
		fprintf(fout,"%c",string[i]);
	}  
	string[idx+1]='\0';
	fclose(fout); 
	fclose(fin);
	remove(argv[1]);
	rename("dest.txt",argv[1]);
}
