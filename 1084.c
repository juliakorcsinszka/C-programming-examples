#include<stdio.h>
#include<stdlib.h>

//118493 Wrong answer
//to 1084.c


//structure to store information about the vehicle
typedef struct Vehicle{
	int arrivalTime;
	int rowIndex;
	int display;//what is the position of the vehicle 
} vehicle;

//function to print out the resulting grid
void printOut(int*pNumRws, int*pNumClmns, int*pNumTmstps, vehicle*vehicleList, int*pIndex){
	for(int i = 0; i < *pNumRws; i ++){
		for(int j =0; j < *pNumClmns; j++){
			for(int k = 0; k < *pIndex; k++){
				//if vehicle is within the row
				if(vehicleList[k].rowIndex == i && vehicleList[k].display == k && vehicleList[k].display < *pNumClmns){
					printf("1");
				}
				//otherwise
				else{
					printf(".");
				}
			}//loop through all the vehicles
		}//loop through all the columns 
		printf("\n");

	}//loop through all the rows
}

//function to identify how the last row will look like
void calculations(int*pNumRws, int*pNumClmns, int*pNumTmstps, vehicle*vehicleList, int*pIndex){
	//go through all the elements of the array
	for(int i = 0; i < *pIndex; i ++){
		//determine the "relative" position of the vehicle at the output
		vehicleList[*pIndex].display = *pNumTmstps - (vehicleList[i].arrivalTime + 1);
	}
	//call function to print out the output
	printOut(pNumRws, pNumClmns, pNumTmstps, vehicleList, pIndex);
}

//function to get input from the user
void getInput(int*pNumRws, int*pNumClmns, int*pNumTmstps, vehicle*vehicleList, int*pIndex){
	//get the highway parameters
	scanf("%d %d %d", pNumRws, pNumClmns, pNumTmstps);
	//get the vehicle input
	int buffer1;
	int buffer2;
	vehicleList = (vehicle*) malloc (*pNumTmstps * sizeof(vehicle));
	while(scanf("%d %d", &buffer1, &buffer2)!=EOF){
		vehicleList[*pIndex].arrivalTime = buffer1;
		vehicleList[*pIndex].rowIndex = buffer2;
		(*pIndex)++; //move onto the next array element | count number of vehicles
	}
	//call function to perform calculations on what to output
	calculations(pNumRws, pNumClmns, pNumTmstps, vehicleList, pIndex); 
}

//the main function where the program execution starts
int main (){
	//initialising variables and pointers to them 
	int numberOfRows = 0;
	int*pNumRws = &numberOfRows;
	int numberOfColumns = 0;
	int*pNumClmns = &numberOfColumns;
	int numOfTimesteps = 0;
	int*pNumTmstps = &numOfTimesteps;
	int index = 0;//num of vehicles
	int*pIndex = &index;
	vehicle*vehicleList;

	//call function to get the input data from the user
	getInput(pNumRws, pNumClmns, pNumTmstps, vehicleList, pIndex);

}