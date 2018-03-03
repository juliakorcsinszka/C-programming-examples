#include<stdio.h>
#include<stdlib.h>
//105100 Wrong answer
//to 1081.c


//this function prints out the resulting grid after the steps
void output(char**grid, int*pRowsNum, int*pColumnNum){

	for (int i = 0; i < *pRowsNum; i++){
		for(int j = 0; j <*pColumnNum; j++){
			printf("%c", grid[i][j]);
		}

		printf("\n");

	}

	//free the memory allocated to the grid
	free(grid);
}

//this function counts the neighbours of the current element by testing conditions
int checkNeighbour(char**previousTimeStep, int*pJ, int*pK, int*pNeighbour){

					if (previousTimeStep[*pJ-1][*pK-1] == 'X')
						*pNeighbour+=1;
					if (previousTimeStep[*pJ-1][*pK] == 'X')
						*pNeighbour+=1;
					if (previousTimeStep[*pJ-1][*pK+1] == 'X')
						*pNeighbour+=1;
					if (previousTimeStep[*pJ][*pK-1] == 'X')
						*pNeighbour+=1;
					if (previousTimeStep[*pJ][*pK+1] == 'X')
						*pNeighbour+=1;
					if (previousTimeStep[*pJ+1][*pK-1] == 'X')
						*pNeighbour+=1;
					if (previousTimeStep[*pJ+1][*pK] == 'X')
						*pNeighbour+=1;
					if (previousTimeStep[*pJ+1][*pK+1] == 'X')
						*pNeighbour+=1;


return *pNeighbour;
}

//this function records the current view of the grid to be used as the reference for next step
void allocatePrevStep(char**grid, char**previousTimeStep, int*pRowsNum){

	//loop through the grid and copy it
	for (int i = 0; i < *pRowsNum; i++){
		previousTimeStep[i] = grid[i];
	}
}

//the function where the actual game is executed
void game (char**grid, int*pRowsNum, int*pColumnNum, int*pSteps, char**previousTimeStep, char*pCurrElement){
	for (int i = 0; i < *pSteps; i++){

		//call function to remember the current grid and use it for the next step
		allocatePrevStep(grid, previousTimeStep, pRowsNum);

		for(int j = 0; j < *pRowsNum; j++){

			int*pJ = &j;

			for(int k = 0; k < *pColumnNum; k++){

				int*pK = &k;

				//select the current element and perform actions with it
				*pCurrElement = previousTimeStep[j][k];

				int neighbour = 0;
				int*pNeighbour = &neighbour;
				//if the current element is alive
				if (*pCurrElement == 'X'){

					//call function to count the number of neighbours
					checkNeighbour(previousTimeStep, pJ, pK, pNeighbour);

					//check what to do with the neighbour number
					if (neighbour < 2 || neighbour > 3)
						*pCurrElement = '.';

				}


				//if the current element is dead, what are the options
				if(*pCurrElement == '.'){

					//call function to count the number of neighbours
					checkNeighbour(previousTimeStep, pJ, pK, pNeighbour);

					//check the neighbour number
					if(neighbour == 3)
						*pCurrElement = 'X';
				}

				//assign the value of the element to the current grid
				grid[j][k] = *pCurrElement;

			}
		}

	}

//free the memory allocated to the previous time step grid
free(previousTimeStep);
//call function to print out the final grid
output(grid, pRowsNum, pColumnNum);

}

//this function gets the input from the user
//it receives the number of rows, columns, and steps
//as well as the starting grid
void getInput(char**grid, int*pRowsNum, int*pColumnNum, int*pSteps, char**previousTimeStep, char*pCurrElement){

	//get number of rows
	scanf("%d", pRowsNum);
	//get number of columns
	scanf("%d", pColumnNum);
	//get number of steps
	scanf("%d", pSteps);


	//allocate memory for the number of rows 
	grid = (char**) malloc ((*pRowsNum) * sizeof(char));
	//allocate memory for the previous time step grid
	previousTimeStep = (char**) malloc ((*pRowsNum) * sizeof(char));

	//get all of the rows of the start grid from the user
	for (int i = 0; i < *pRowsNum; i++){

		//allocate memory for each column
		grid[i] = (char*) malloc ((*pColumnNum) * sizeof(char));

		//allocate memory for the rows of the previous time step grid
		previousTimeStep[i] = (char*) malloc ((*pColumnNum) * sizeof(char));

		scanf("%s", grid[i]);
	}

	//call function to start the game
	game(grid, pRowsNum, pColumnNum, pSteps, previousTimeStep, pCurrElement);

}

//main function where the execution of the program starts
int main (){

	//initialise variables and their pointers
	int numberOfRows= 0;
	int*pRowsNum = &numberOfRows;
	int numberOfSColumns = 0;
	int*pColumnNum = &numberOfSColumns;
	char currElement = 0;
	char*pCurrElement = &currElement; 
	int steps = 0;
	int*pSteps = &steps;
	char**grid;
	char**previousTimeStep;

	//call function to get the input
	getInput(grid, pRowsNum, pColumnNum, pSteps, previousTimeStep, pCurrElement);
}