#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int countTokens(char * input){
	int counter = 1;

	//to count the number of "tokens"
	int j =0;
	while(!isalpha(input[j]) && j<strlen(input)){
				j++;
	}
	int i;
	for ( i = j ; i < strlen(input); i++){
		
		if (!isalpha(input[i]) && i < strlen(input) ){
			counter++;
			while(!isalpha(input[i]) && i<strlen(input)){
				i++;
			}
		}
		//printf("%c\n", input[i]);

	}

	if (!isalpha(input[i-1])){
		counter--;
	}
	return counter;

}


int main (int argc, char ** argv){
	if (argc > 2){
		fprintf(stderr, "%s\n", "Too many arguments" );
		exit(0);
	}

	if (argc<2){
		fprintf(stderr, "Too few arguments\n");
		exit(0);
	}

	char * input = argv[1];
	printf("INPUT: %s\n", input);
	int x = countTokens(input);

	char * words [x];
	int j =0;
	for (int i = 0; i < x; i++){ //iterate words array
		
		while(!isalpha(input[j]) && j<strlen(input)){ //skip delimators in the beginning
			j++;
		}
		int wordStart = j; // start of new word
		int index = wordStart;
		while (isalpha(input[index]) && index < strlen(input)){
			index++;
		}
		int wordEnd = index -1;
		char * tok = (char *)malloc (wordEnd- wordStart);
		strncpy(tok, input + wordStart, wordEnd - wordStart + 1);
		printf("\nString: %s\n", tok);
		printf("\nstart: %i \n end: %i\n", wordStart, wordEnd);
		words[i] = tok;
		
		j = index;
		if (j == strlen(input) || index == strlen(input)){
			free(tok);
		}
		
	}
		
	for (int test = 0; test < x; test++){
		printf("%s\n", words[test]);
	}

	return 0;

}