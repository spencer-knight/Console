#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//returns input command including '\n' character at end of input
char* getInput() {

	size_t buff;
	char* line;
	//aesthetic
	printf("> ");
	getline(&line, &buff, stdin);

	return line;
}

//create NULL terminated string array 
#define TOK_BUFFSIZE 2
char** getTokens(char* line) {

	//check for allocation error
	size_t buff = TOK_BUFFSIZE;
	char** tokens = malloc(buff * sizeof(char*));
	
	//loop until all tokens have been put into array
	char* delimiters = "\n \t";
	int pos = 0;
	char* token = strtok(line , delimiters);	
	while(token != NULL) {

		//show allocated memory
		printf("tokens: %p, tokens end: %p, pos: %p\n", tokens, tokens + buff, tokens + pos);

		//Prevent segfault
		if(pos >= buff) {
			buff += TOK_BUFFSIZE;	
			tokens = realloc(tokens, buff * sizeof(char*));
		}

		//iterate
		tokens[pos] = token;
		pos++;
		token = strtok(NULL, delimiters);
	}

	//NULL terminate array
	tokens[pos] = NULL;

	return tokens;
}

int execute(char** tokens) {
	return 0;
}

int main() {

	int status = 1;
	char* input;
	char** tokens;

	while(status) {
		input = getInput();
		tokens = getTokens(input);
		status = execute(tokens);
	}

	//print tokens
	char** tmp = tokens;
	while(*tmp != NULL) {
		printf("%s, %p, %ld\n", *tmp, tmp, tmp - tokens);
		tmp++;
	}

	return 0;
}
