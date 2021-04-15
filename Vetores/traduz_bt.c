#include <stdio.h>

#define REF(r) (r)/10 - 1
#define SIZE 6

void aSolution(void);
void bSolution(void);
int verifyCod(int array[], int cod);

int main(void){
		int version;

		printf("Choose the version\n");
		printf("(1- For non-aleatory codes) or (2- For aleatory codes): ");
		scanf("%i", &version);
		switch(version){
			case 1:
				aSolution();
				break;
			case 2:
				bSolution();
				break;
		}

	return 0;
}

////////////////////////////////////////////////
///////////////// FUNCTIONS ////////////////////
////////////////////////////////////////////////
void aSolution(void){
	/*
	 * category 10 - position 0
	 * category 20 - position 1
	 * category 30 - position 2
	 * category 40 - position 3
	 * category 50 - position 4
	 * category 60 - position 5
	 */
	float vAdjustment[SIZE] = { 1.06, 1.08, 1.075, 1.0695, 1.072, 1.063 };
	int profReg, category;
	float salary, newSalary;

	printf("Enter your registration or 0 to exit the program: ");
	scanf("%i", &profReg);
	while(profReg > 0){
		printf("Enter your current salary: ");
		scanf("%f", &salary);
		printf("Enter your professional category: ");
		scanf("%i", &category);
		if(category <= 60 && category >= 10 && category%10==0){
			newSalary = salary * (vAdjustment[REF(category)]);
		}else{
			newSalary = salary;
		}
		if(newSalary == salary){
			printf("(%d). His salary didn't increase: R$ %.2f\n\n",profReg, newSalary);
		}else{
			printf("(%d). His new salary is: R$ %.2f\n\n",profReg, newSalary);
		}

		printf("Enter a new registration or 0 to exit the program: ");
		scanf("%i", &profReg);
	}

	return;
}

////////////////////////////////////////////////
void bSolution(void){
	int vCatCod[SIZE] = {11, 23, 27, 8, 41, 55};
	float vAdjustment[SIZE] = { 1.06, 1.08, 1.075, 1.0695, 1.072, 1.063 };
	int profReg, category, position;
	float salary, newSalary;

	printf("Enter your registration or 0 to exit the program: ");
	scanf("%i", &profReg);
	while(profReg > 0){
		printf("Enter your current salary: ");
		scanf("%f", &salary);
		printf("Enter your professional category: ");
		scanf("%i", &category);
		position = verifyCod(vCatCod, category);
		if(position >= 0){
			newSalary = salary * (vAdjustment[position]);
		}else{
			newSalary = salary;
		}
		if(newSalary == salary){
			printf("(%d). His salary didn't increase: R$ %.2f\n\n",profReg, newSalary);
		}else{
			printf("(%d). His new salary is: R$ %.2f\n\n",profReg, newSalary);
		}

		printf("Enter a new registration or 0 to exit the program: ");
		scanf("%i", &profReg);
	}
	return;
}

////////////////////////////////////////////////
int verifyCod(int array[], int cod){

	for(int i = 0; i < SIZE; i++){
		if(cod == array[i]){
			return i;
		}
	}
	return -1;
}
////////////////////////////////////////////////