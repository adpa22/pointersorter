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

void  merge(int low, int mid, int high, char * a [], char * b[]){
        int l1, l2, i;
		for (l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++){
                if (strcmp(a[l1], a[l2]) <= 0)
                        b[i] = a[l1++];
                else
                        b[i] = a[l2++];

        }

        while (l1 <= mid){
        	b[i++] = a[l1++];
        }

        while(l2 <= high){
        	b[i++] = a[l2++];
        }

        for (i = low; i <= high; i++){
        	a[i] = b[i];
        }


}


void sort (int low, int high, char * a[], char * b[]){
	int mid;
	if (low < high){
		mid = (low+high)/2;
		sort(low,mid, a, b);
		sort(mid+1, high, a, b);
		merge(low,mid,high, a, b);
	} else {
		return;
	}
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
	//printf("INPUT: %s\n", input);
	int x = countTokens(input);
	//printf("\nNumtokens: %i\n", x);
	char * words [x];
	int j =0;
	int i = 0;
	for ( i; i < x; i++){ //iterate words array
		
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
		tok[wordEnd-wordStart + 1 ] = '\0';
		//printf("\nString: %s\n", tok);
		//printf("\nstart: %i \n end: %i\n", wordStart, wordEnd);
		words[i] = tok;
		
		j = index;
		if (j == strlen(input) || index == strlen(input)){
			//	free(tok);
		}
		
	}
	int test = 0;
	for ( test; test < x; test++){
	//	printf("%s\n", words[test]);
	}
	
	char * sorted[x];

	sort(0,x-1, words,sorted );
	//printf("\n");
	//printf("X: %i", x);
	int out = 0;
	for ( out; out < x; out ++){
		printf("%s\n", sorted[out]);
	}

	return 0;

}
