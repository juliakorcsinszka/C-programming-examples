#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//104446 Accepted
//to 1080.c

//this function outputs the result of the calculations
void output(double*vector, long*pNumOfElements){
	for (int i = 0; i < (*pNumOfElements); i++){
		//output to 3 digit precision
		printf("%.3lf ", vector[i]);
	}

	//free the allocated memory
	free(vector);
}

//this function normalises the vector
void normalise(double*vector, double*pLength, long*pNumOfElements){
	//for all of the elements of the vector, normalise the vector
	for (int i = 0; i < (*pNumOfElements); i++){
		//override the old elements of the vector with its normalised version
		vector[i] = vector[i]/(*pLength);
	}

	//call function to print out the result
	output(vector, pNumOfElements);
}

//this function calculates the length of the vector
void calcuateLength(double*vector, long*pNumOfElements, double*pSum, double*pLength){

	//calculate the sum of the elements
	for(int i = 0; i < (*pNumOfElements); i++){
		//calculate sum of squared elements
		*pSum = *pSum + pow(vector[i], 2);
	}

	//get the square root of the sum to get the length
	*pLength = sqrt(*pSum);

	//call function to normalise the vector
	normalise(vector, pLength, pNumOfElements);

}

//this function receives users input of number of elements
//and of the elements of the vector
void getInput (double*vector, long*pNumOfElements, double*pSum, double*pLength) {

	//get the number of elements of the vector
	scanf("%ld\n", pNumOfElements);

	//allocate enough memory to store the vector
	vector = (double*)  malloc (sizeof(double)*(*pNumOfElements));

	//get all the elements of the vector
	for(int i = 0; i < (*pNumOfElements); i++){
		scanf("%lf", &vector[i]);
	}

	//calling a function to calculate the length of the obtained vector
	calcuateLength(vector, pNumOfElements, pSum, pLength);

}


//maiin function where the program exectution starts
int main (){

	//creating variables and their pointers
	double  length;
	double*pLength = &length;
	long numOfElements = 0;
	long*pNumOfElements = &numOfElements;
	double*vector;
	double sum = 0;
	double*pSum = &sum;

	//calling initial function to start execution
	getInput(vector, pNumOfElements, pSum, pLength);


}