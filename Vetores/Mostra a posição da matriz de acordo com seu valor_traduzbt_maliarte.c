/*
 * Show the array's position according its value
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CONTROL 20 // Element of division in rand(). void creatArray(int size)

void creatArray(int size);
void showArray(int array[], int elements);
int showPosition(int v[], int elements, int reference);

int main(void){
	int size;
	
	srand(time(NULL));
	
	printf("Enter the size of the array or 0 to exit the program: ");
	scanf("%d", &size);
	
	while(size > 0){
		creatArray(size);
		printf("Enter the size of the next array or 0 to exit the program: ");
		scanf("%d", &size);
	}
	
	return 0;
}

/////////////////////////////////////////////////////////////////////
///////////////////////////// FUNCTIONS /////////////////////////////
/////////////////////////////////////////////////////////////////////
void creatArray(int size){
	int array1[size];
	int value;
	int count;
	
	for(int i = 0; i < size; i++){
		array1[i] = rand() % CONTROL;
	}
	
	printf("Array: \n");
	showArray(array1, size);
	printf("\nEnter the value: ");
	scanf("%i", &value);
	
	count = showPosition(array1, size, value);
	printf("%d position(s)\n\n", count);
	
	return;
}

/////////////////////////////////////////////////////////////////////
void showArray(int array[], int elements){
	
	printf("[");
	
	for(int i = 0; i < elements; i++){
		if(i == elements-1){
			printf("%d]", array[i]);
		}else printf("%d, ", array[i]);
	} 
	
	printf("\n");
	
	return;
}

/////////////////////////////////////////////////////////////////////
int showPosition(int v[], int elements, int reference){
	int count = 0;		
    for(int i = 0; i < elements; i++){
		if(v[i] == reference){
			printf("(%d) ", v[i]);
			printf("- Position [%d]\n", i);
			count++;
		}
	}
	
	return count;
}
/////////////////////////////////////////////////////////////////////
    