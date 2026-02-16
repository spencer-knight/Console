#include <stdio.h>

//returns input command including '\n' character at end of input
char* getInput() {

	size_t buff;
	char* line;
	getline(&line, &buff, stdin);

	return line;
}

#define TOK_BUFFSIZE 64
char** getTokens(char* line) {

	//check for allocation error
	char** tokens = malloc(TOK_BUFFSIZE * sizeof(char*));


	return 0;
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

	return 0;
}
