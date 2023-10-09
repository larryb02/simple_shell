#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_BUFFERSIZE 1024
#define TOK_BUFFER 64
#define DELIM '-'



void programLoop(void);
char *readLine(void);
char *parseArgs(const char *input);

//setup program loop

int main(int argc, char **argv){

	programLoop();


	EXIT_SUCCESS;
}


void programLoop(void){
char *input;
char *args;
	
    do{
	printf("%s", "-> ");
	input = readLine();
	//args = parseArgs(input);
	}while(1);
	

}

char *readLine(void){

int bufferSize = DEF_BUFFERSIZE;
int position = 0;
char *buffer = malloc(sizeof(char) * bufferSize);
int c;

	if(!buffer){
		fprintf(stderr, "allocation error.\n");
		exit(EXIT_FAILURE);
	}

	while(1){
	
	 c = getchar();

	 if(c == EOF || c == '\0'){
		buffer[position] = '\0'; 
		return buffer;
	 }
	 else{
	 	buffer[position] = c;
	 }
	 position++;

	if(position >= bufferSize){
		bufferSize += DEF_BUFFERSIZE;
		buffer = realloc(buffer, bufferSize);

		if(!buffer){
			fprintf(stderr, "allocation error.\n");
			exit(EXIT_FAILURE);
			}
		}
	
	}
	

}

char **parseArgs(const char *input){

char *token;
char **tokens = malloc(sizeof(char) * TOK_BUFFER);
int position = 0;


token = strtok(input, DELIM);
	while(token != null){
		tokens[position] = args; 		
		position++;	

	}
return args;
}
