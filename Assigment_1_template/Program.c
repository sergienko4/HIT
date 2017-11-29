#include<stdio.h>
#include <math.h>

void getSum();
void getBinery();
int getTheBiggestBinery(int, int);
void getMinBetweenK();
int getMinBetween(int);
int getInputNum(int, int);
void getResultT();
void getResult(int);

void main(){
	//getSum();
	//getBinery();
	//getMinBetweenK();
	getResultT();

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

	int input, result;
	// get K  num from console
	input = getInputNum(0,0);
	// call for logic function
	result=getMinBetween(input);

}

int getMinBetween(int num){

	// flag is found smaller sum than my num
	int hasMaller = 0;
	
	int min, input = 0;
	
	// get num from console
	min = getInputNum(0,0);
	
	while(hasMaller == 0 && input != -1){
		input = getInputNum(0,0);

		// check if samller than num 
		if(input + min <num)
			hasMaller = 1;
		// save the smaller num between two inputs
		else if(input<min)
			min = input;

	}
	// return result
	return hasMaller;
}
void getResultT(){
	int num;

	num = getInputNum(1,7);
	getResult(num);

}
void getResult(int num){
	// temp var for manipulation of logic
	int x=3, y=5, temp, tempX, tempY;
	
	// will save the first and the last result 
	int result_x_a, result_y_a, result_x_b, result_y_b;
	
	int sq;
	// flag to know if i have more than one solution also to get the smallest betwwen results;
	int flag = 0;
	// to chekc if ZERO 
	int flagsqZero = 0;
	sq = num;

	while (sq>0){
		sq = (int) sqrt(sq);
		
		if(sq==1)
			flagsqZero ++;
		if(flagsqZero == 2)
			sq = 0;
		
		// check if it right for X
		tempX = x*sq;
		tempY = (num-tempX)/y;

		temp = tempX + (y*tempY);
		// check if the nums are correct for X
		if(temp == num)
		{	if(flag == 0)	
			{	
				result_x_a=sq;
				result_y_a=tempY;
			}
			else
			{
				result_x_b=sq;
				result_y_b=tempY;
			}
		// update if theres more then one result
				flag++;

		}
		else
		{
			// check if it right for Y  
			tempY = y*sq;
			tempX = (num-tempY)/x;
			temp = (x*tempX) + tempY;

		// check if the nums are correct for Y
			if(temp == num)
			{	if(flag == 0)
				{
					result_x_a=tempX;
					result_y_a=sq;
				}
				else	
				{
					result_x_b=tempX;
					result_y_b=sq;
				}
			flag++;
		}
	}
}

	// summery

	// no result was found 
	if(flag == 0)
		printf("No solution!!");
	else{
		// how many results 
		if(flag>1){
			// get the distance 
			tempX = (result_x_a - result_y_a);
			tempY = (result_x_b - result_y_b);

			if(tempX<0)
			tempX *=-1;
				if(tempY<0)
			tempY *=-1;
			// update to the shortest 
			if(tempX> tempY)
			{
				result_x_a = result_x_b;
				result_y_a = result_y_b;
			}
		}

		// print conclusion 
		printf("The result: (%d - %d)",result_x_a,result_y_a);
	}
}


			  







int getInputNum(int hasSondition, int minNum){
	
	int input = 0;
	if(hasSondition==0){
	printf("PLeaze enter the number\n");
		scanf("%d",&input);
	}
	else{
		while(input<=minNum)
		{
			printf("Please enter the number, the number must be bigger than %d\n",minNum);
			scanf("%d",&input);
		}
	}
	return input;
}