#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//115962 Accepted
//to 1048.c

//the structure to store an input date
typedef struct Date {
	char month [10];
	int day;
	int year;
	int monthNum;
	int yearFormat;
} date;

//function to print out the resulting sorted array and the result of the query
void printOut(date*datesArray, int*pNumDates, char*pResponse){
	for (int i = 0; i < *pNumDates; i++){
		//print out the sorted elements
		printf("%s ", datesArray[i].month);
		printf("%d ", datesArray[i].day);
		printf("%02d\n", datesArray[i].year);	
	}
	//print out the query result
	printf("%s\n", pResponse);
	free(datesArray);
}

//function to find out whether the date is present in the array
void handleQuery(date*datesArray, int*pQueryDay, int*pQueryMonth, int*pQueryYear, int*pNumDates){
	char response [4];
	char*pResponse = response;
	int identifier = 0;
	//go through all the items and change the identifier if the date is found
	for(int i = 0; i < *pNumDates; i ++){
		//check that the date is present in the array
		if(datesArray[i].day == *pQueryDay && datesArray[i].monthNum == *pQueryMonth && datesArray[i].year == *pQueryYear){
			identifier = 1;
		}
	}
	//assign value to the response variable
	if(identifier == 1){
		strcpy(response, "Yes");
	}
	else{
		strcpy(response, "No");
	}
	//call funciton to print out the sorted elements and the response
	printOut(datesArray, pNumDates, pResponse);
}

//fucntion called by qsort to compare and sort 2 elements of the array
int compareStructs(const void *a, const void *b){

	//elements to be compared
	date *pa = (date*) a;
	date *pb = (date*) b;

	//compare the year of the elements
	if ((pa->yearFormat) > (pb->yearFormat)){
		return -1;
	}
	else if ((pa->yearFormat) < (pb->yearFormat)){
		return 1;
	}
	//if the year is the same, compare the month
	else {
		if((pa->monthNum) > (pb->monthNum)){
			return -1;
		}
		else if ((pa->monthNum) < (pb->monthNum)){
			return 1;
		}
		//if the month is the same, comapre the date
		else {
			if((pa->day)>(pb->day)){
				return -1;
			}
			else{
				return 1;
			}
		}
	}

}

//get the input from the user
void getInput (int*pNumDates, date*datesArray, int*pQueryDay, int*pQueryMonth, int*pQueryYear){

	//get input for the number of dates
	scanf("%d", pNumDates);
	//allocate memory for n structures
	datesArray = (date*) malloc (*pNumDates * sizeof(date));

	//get input of specified number of dates and format them for processing
	for (int i = 0; i < *pNumDates; i++){

		//get input for elements of the structs and store it in there
		scanf("%s %d %02d", datesArray[i].month, &datesArray[i].day, &datesArray[i].year);
		//determine the number of the month
		if(strcmp(datesArray[i].month, "January")==0){
			datesArray[i].monthNum = 1;
		}
		if (strcmp(datesArray[i].month, "February")==0){
			datesArray[i].monthNum = 2;
		}
		if (strcmp(datesArray[i].month, "March")==0){
			datesArray[i].monthNum = 3;
		}
		if (strcmp(datesArray[i].month, "April")==0){
			datesArray[i].monthNum = 4;
		}
		if (strcmp(datesArray[i].month, "May")==0){
			datesArray[i].monthNum = 5;
		}
		if (strcmp(datesArray[i].month, "June")==0){
			datesArray[i].monthNum = 6;
		}
		if (strcmp(datesArray[i].month, "July")==0){
			datesArray[i].monthNum = 7;
		}
		if (strcmp(datesArray[i].month, "August")==0){
			datesArray[i].monthNum = 8;
		}
		if (strcmp(datesArray[i].month, "September")==0){
			datesArray[i].monthNum = 9;
		}
		if (strcmp(datesArray[i].month, "October")==0){
			datesArray[i].monthNum = 10;
		}
		if (strcmp(datesArray[i].month, "November")==0){
			datesArray[i].monthNum = 11;
		}
		if (strcmp(datesArray[i].month, "December")==0){
			datesArray[i].monthNum = 12;
		}

		//format year for comparison
		if(datesArray[i].year >= 90 && datesArray[i].year <= 99){
			datesArray[i].yearFormat = 1900+datesArray[i].year;
		}
		else{
			datesArray[i].yearFormat = 2000+datesArray[i].year;
		}
	}

	//get input of query 
	scanf ("%d %d %02d", pQueryDay, pQueryMonth, pQueryYear);

	//using qsort to sort dates 
	qsort (datesArray, (*pNumDates), sizeof(date), compareStructs);

	//handle the query
	handleQuery(datesArray, pQueryDay, pQueryMonth, pQueryYear, pNumDates);
}

//main function where the execution of the program starts 
int main(){

	//initialise variables and pointers
	int numberOfDates = 0;
	int*pNumDates = &numberOfDates;
	date*datesArray = 0;
	int queryMonth = 0;
	int*pQueryMonth = &queryMonth;
	int queryDay = 0;
	int*pQueryDay = &queryDay;
	int queryYear = 0;
	int*pQueryYear = &queryYear;

	//call function to get input from the user
	getInput(pNumDates, datesArray, pQueryDay, pQueryMonth, pQueryYear);

}
