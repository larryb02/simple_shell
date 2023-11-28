#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_BUFFERSIZE 1024
#define TOK_BUFFER 64
#define DELIM " "



void programLoop(void);
char *readLine(void);
char **parseArgs(char *input);

//setup program loop

int main(int argc, char **argv){

	programLoop();


	EXIT_SUCCESS;
}


void programLoop(void){
	char *input;
	char **args;

	while(1){
		printf("%s", "-> ");
		input = readLine();
		//args = parseArgs(input);

		free(input);
		free(args);
	}


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

		if(c == '\n' || c == EOF){
			buffer[position] = '\0'; 
			return buffer;
		}
		else{
			buffer[position] = (char)c;
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

char **parseArgs(char *input){
	int bufferSize = TOK_BUFFER;
	char *token;
	char **tokens = malloc(sizeof(char) * TOK_BUFFER);
	int position = 0;

	if(!tokens){
		fprintf(stderr, "Allocation error.");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, DELIM);
	while(token != NULL){
		tokens[position] = token; 		
		position++;	
		if(position >= bufferSize){
			bufferSize += TOK_BUFFER;
			tokens = realloc(tokens, bufferSize);
			if(!tokens){
				fprintf(stderr, "Allocation error.");
				exit(EXIT_FAILURE);
			}

		}
	}
	return tokens;
}
