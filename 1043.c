#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
#define MAX_STRING 100

// 104924 Accepted
// to 1043.c


//function to compare the string length
int comparison(const void *strOne, const void *strTwo) {
	
	//get the length of the strings
    int lengthOne = strlen((*(const char * const *)strOne));
    int lengthTwo = strlen((*(const char * const *)strTwo));

    //the actual length comparison
    if (lengthTwo > lengthOne)
        return 1;
    else if (lengthOne > lengthTwo)
        return -1;
    else 
   		return 0;

}


//funciton to print out the strings in the end
void printOut (int totalStrings, char**strings){
	for (int i = 0; i<totalStrings; i++){
		printf("%s\n", strings[i]);
	}
}


//operation function, where the memory is allocated, and
//hence, all the other functions are called from here 
void operations(char**strings, int*numberOfStringsN, int*numberOfStringsM){
	
	//get input for the first number (number n)
	scanf("%d", numberOfStringsN);

	//allocate memory for n strings
	strings = (char**) malloc (((*numberOfStringsN)*MAX_STRING) * sizeof(char));
	

	//get input of the n strings
	for(int i = 0; i<(*numberOfStringsN); i++){

    	//allocated memory for each input character
    	strings[i] = (char*) malloc (MAX_STRING * sizeof(char));
    	//store the string into the array
    	scanf("%s", strings[i]);

	}
	
	//get the number m
	scanf("%d", numberOfStringsM);

	//calculate how many strings will there be in total 
	//and create a pointer for it
	int totalStrings = (*numberOfStringsN)+(*numberOfStringsM);
	int*pTotalStrings = &totalStrings;

	//increase the amount of allocated memory 
	strings = realloc(strings, (totalStrings) * sizeof(char*));
	
	//get the strings from the user
	for (int i = (*numberOfStringsN); i < ((*numberOfStringsN)+(*numberOfStringsM)); i++) {
    	
    	//allocate memory for each input character
    	strings[i] = (char*) malloc (MAX_STRING * sizeof(char));
    	//store the strings in the array
    	scanf("%s", strings[i]);
	}

	//call the qsort function passing it the comparison function
	qsort(strings, *pTotalStrings, sizeof(char *), comparison);

	//print out the sorted strings
	printOut(*pTotalStrings, strings);

	//free the allocated memory
	free(strings);

}


//main function where the execution starts
int main () {

	//declaration of the variables and pointers to them
	int numberOfStringsN = 0;
	int*pStringNumN = &numberOfStringsN;
	int numberOfStringsM = 0;
	int*pStringNumM = &numberOfStringsM;
	char**strings;

	//calling operations function
	operations(strings, &numberOfStringsN, &numberOfStringsM);

	
}