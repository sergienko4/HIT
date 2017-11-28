#include<stdio.h>
void getSum();
void getBinery();
int getTheBiggestBinery(int, int);
void getMinBetweenK();
int getMinBetween(int);

void main(){
	//getSum();
	//getBinery();
	getMinBetweenK();
}

void getSum(){
	// input = get inpur from UI, begin = the first num, sum = calc the sum, kefel = kefel, temp = cal the environment 
	int input = 0, i, begin = 1, sum = 1, kefel = 10, temp= 1;
	
	printf("Enter number \n");
	// get input from console
	scanf("%d",&input);

	for(i = 1; i<input; i++){
		// calculation 
		temp = temp *kefel +begin;
		// sum val
		sum += temp;
	}

	// print result
	printf("The num u entered is: %d the sum is: %d \n",input, sum);
	

	

}
void getBinery(){
	int input, length, result = 0;
    printf("enter the number of nums \n");
    scanf("%d",&length);

    printf("enter the \n");
    scanf("%d",&input);
	result = getTheBiggestBinery(input, length);


}

int getTheBiggestBinery(int input, int length){
 int current,previous,counter=0,indexStart, j;

	indexStart = length+1;
	previous = input %10;
	input = input /10;
	for(j=2; j<length; j++){
		current = input%10;
		// check if the same number;
        if(previous==current){
            counter++;
        }
		else
		// save previous num
		previous=current;
		indexStart--;
	}
}
void getMinBetweenK(){

	int input;
	printf("Enter the num \n");
	scanf("%d",&input);
	getMinBetween(input);

}

int getMinBetween(int num){

	int hasMaller = 0;
	int sum = 0;
	int temp, input;

	while (hasMaller == 0){


	}

}