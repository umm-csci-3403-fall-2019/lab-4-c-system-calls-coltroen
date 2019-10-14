#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>

#define BUF_SIZE 1024

bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */

	if(c == 'A' || c == 'E' || c == 'O' || c == 'I' || c == 'U' || c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u' )
	{
		return true;
	}
	else 
		return false;
}


char *copy_non_vowels(char *str) {

    char* copy;
    int j = 0; 
    int strlength = strlen(str);
    copy = (char*) calloc(strlength+1, sizeof(char));
    for (int i=0; i<strlength; ++i) {
        if (!is_vowel(str[i])){ //if not a vowel, copy over
        copy[j] = str[i];
	j++;
        }		
        
    }

    copy[strlength] = '\0';
    return (char*) copy;
}

void disemvowel(FILE* inputFile, FILE* outputFile){
    char *buffer = NULL;
    size_t buf_size = 100;
    char* str;

    while(getline(&buffer, &buf_size, inputFile) != -1){
        str = copy_non_vowels(buffer);
        fwrite(str, 1, strlen(str), outputFile);
        free(str);
    }

    free(buffer);
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;

     if(argc == 1) {
        inputFile = stdin;
        outputFile = stdout;
     }
     if (argc == 2) {
        inputFile = fopen(argv[1], "r");
        outputFile = stdout;
     }
     if (argc == 3){
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
    }
     disemvowel(inputFile, outputFile);
     fclose(inputFile);
     fclose(outputFile);
    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    

    return 0;
}
