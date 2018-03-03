#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//116086 Wrong Answer
//to 1082.c

//function to print out the resulting list
void printOut(int*list, long*pNumEl){
	for(int i = 0; i < *pNumEl; i ++){
		printf("%d ", list[i]);
	}	
	free(list);
}


//function to insert back the osrted values at their new locations
int* pasteBack(int*list, int*temp, long*pNumEl, int*origTemp, int*pToSort, int*origList){
	//loop through all the elements to be pasted
	for (int i = 0; i < *pToSort; i ++){
		//loop through all the elements of the original array
		for (int j = 0; j < *pNumEl; j ++){
			if (origList[j] == origTemp[i]){ //if the elements original location is found
				list[j] = temp[i]; //paste new value on the location 
			}
		}
	} 
	free(temp);
	free(origTemp);
	free(origList);

return list;
}

//funciton that sorts the temporary array
int* sortTemp(int*temp, int*pToSort){
	//identifier to break the loop
	int identifier = 0;
	while (identifier == 0){
		identifier = 1;
		//search through all of the elements
		for(int i = 0; i < *pToSort-1; i ++){
			//if the elements are unordered
			if (temp[i] > temp[i+1]){
				//swap the elements
				int temporary  = temp[i];
				temp[i] = temp[i+1];
				temp[i+1] = temporary;
				//reset identifier, so that the loop is not broken
				identifier = 0;
			}
		}
		//if identifier has not changed (all the elements are sorted), break the while-loop
		if(identifier == 1){
			break;
		}
	}
//return the sorted list
return temp;
}

//function that determines what numbers should be ordered
void sort(long*pNumEl, char*pParity, int*list, int*temp, int*origTemp, int*pToSort, int*origList){
	//if the elements to be sorted are odd
	if(!(strcmp(pParity, "odd"))){
		int j = 0;
		//copy the odd numbers into the temporary array for sorting
		for (int i = 0; i < *pNumEl; i ++){
			if(list[i]%2!=0){
				//if the number is odd, copy it into the temporary array 
				temp[j] = list[i];
				origTemp[j] = list[i];
				j++;
			}
		}
		*pToSort = j;
		//call the sort function
		sortTemp(temp, pToSort);
		//call funciton to paste back the values into the original array
		pasteBack(list, temp, pNumEl, origTemp, pToSort, origList);
		//call function to print out the result
		printOut(list, pNumEl);
	}
	//else(if the elements to be sorted are even)
	else{
		int l = 0;
		//copy the even numbers into the temporary array for sorting
		for (int k = 0; k < *pNumEl; k ++){
			if(list[k]%2==0){
				//if the number is even, copy it into the temporary arrays 
				temp[l] = list[k];
				origTemp[l] = list[k];
				l++;
			}
		}
		*pToSort = l;
		//call the sort function
		sortTemp(temp, pToSort);
		//call funciton to paste back the values into the original array
		pasteBack(list, temp, pNumEl, origTemp, pToSort, origList);
		//call function to print out the result
		printOut(list, pNumEl);
	}
}

//this function gets input from the user
void getInput(long*pNumEl, char*pParity, int*list, int*temp, int*origTemp, int*pToSort, int*origList){

	//get the parity of the elements to be switched
	scanf("%s", pParity);
	//get the number of elements
	scanf("%ld\n", pNumEl);
	//dynamiclly allocate enough memory for all of the elements in all arrays
	list = (int*) malloc (*pNumEl * sizeof(int));
	temp = (int*) malloc (*pNumEl * sizeof(int));
	origTemp = (int*) malloc (*pNumEl * sizeof(int));
	origList = (int*) malloc (*pNumEl * sizeof(int));

	//get all of the elements of the list
	for(int i = 0; i < *pNumEl; i++){
		scanf("%d", &list[i]);
		origList[i] = list[i];//copy array into another one for comparison
	}

	//call function to sort input
	sort(pNumEl, pParity, list, temp, origTemp, pToSort, origList);

}


//main function where all of the variables and pointers to them are initialised
int main (){

	long numberOfElements = 0; //use long, since it is mentioned that the number of elements could be possible large
	long*pNumEl = &numberOfElements;
	int toSort = 0;
	int*pToSort = &toSort;
	char parity [5];
	char*pParity = parity;
	int*list;
	int*temp; //temporary array for sorting
	int*origTemp; //temporary array to store presorted selected values
	int*origList;//original list for future pasting of the values

	//call the function to get the input
	getInput(pNumEl, pParity, list, temp, origTemp, pToSort, origList);
}