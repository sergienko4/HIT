#include<stdio.h>
#include <math.h>

void getSum();
void getBinery();
int getTheBiggestBinery(int);
void getMinBetweenK();
int getMinBetween(int);
int getInputNum(int, int);
void getResultT();
void getResult(int);
void perfectNum();
int perfectnumLogic(int);



int  main(){
	int select=0, i, all_Ex_in_loop=0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
		if (scanf("%d", &all_Ex_in_loop) == 1)
			do
			{
				for (i=1; i<=5; i++)
					printf("Ex%d--->%d\n", i, i);
				printf("EXIT-->0\n");
				do {
					select=0;
					printf("please select 0-5 : ");
					scanf("%d",&select);
				} while ((select<0)||(select>5));
				switch (select)
				{
				case 1: getSum(); break;
				case 2: getBinery(); break;
				case 3: getMinBetweenK(); break;
				case 4: getResultT(); break;
				case 5: perfectNum(); break;
				}
			} while (all_Ex_in_loop && select);
			return 0;
}
void getSum(){
	// input = get inpur from UI, begin = the first num, sum = calc the sum, kefel = kefel, temp = cal the environment 
	int input = 0, i, begin = 1, sum = 1, kefel = 10, temp= 1;

	// get input from console
	input = getInputNum(0,0);

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
	int length, result;
	length = getInputNum(0,0);
	result = getTheBiggestBinery(length);
}
int getTheBiggestBinery(int length){
	int i, current, previous, counter =1 , index = 1, biggest=1;

	previous = getInputNum(0,0);
	for(i=2; i<=length; i++){
		current = getInputNum(0,0);
		// check if the same value
		if(current == previous){
			counter ++;
		}
		else 
		{
			// set the biggest and the position of the forst element
			if(counter >1 && counter> biggest){
				index = i-counter;
				biggest = counter;
			}
			// reset counter
			if(counter>1)
				counter = 1;
		}
		// save previous value
		previous = current;
	}
	return index;


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
void perfectNum(){
	int num, result;

	num = getInputNum(1,0);
	result = perfectnumLogic(num);
}
int perfectnumLogic(int n){

	int sum =0, result =0, number,j, i=0;
	number = n;
	// get how many digits the num has 
	while(number!=0){
		number/=10;
		i++;
	}
	// set the original num again
	number = n;
	// sum each num with pow
	for(j = i; j>0; j--){
		sum += (int)pow(number%10,i);
		number /=10;
	}
	// set conclusion
	if(sum == n)
		result = 1;
	return result;
}
int getInputNum(int hasSondition, int minNum){

	int input = -1;
	if(hasSondition==0)
	{
		printf("Please enter the number\n");
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