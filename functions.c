#include "header.h"


char **separar_tokens(char *linea, char *delim)
{
	char **tokens = malloc(MAX_SIZE * sizeof(char*));
	char *token;
	int i = 0;

	/* obtiene el primer token */
	token = strtok(linea, delim);
	tokens[0] = token;

	/* recorre todos los tokens */
	while( token != NULL ) {
		token = strtok(NULL, delim);
		tokens[++i] = token;
	}

	tokens[i] = NULL;
	return tokens;
}

