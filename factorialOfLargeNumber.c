/*
	program to find the factorial of a very large number
	idea is to use an array to store very large number
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

int multiply(int x, int *result, int curr_size)
{
	int carry = 0;
	int i;
	
	for( i = 0; i < curr_size; i++ ) {
		
		int temp_product = result[i] * x + carry;
		result[i] = temp_product % 10;
		carry = temp_product / 10;
	}
	
	while( carry ) {
		result[curr_size] = carry % 10;
		carry = carry / 10;
		curr_size++;
	}
	
	return curr_size;
	
}

void printFactorial(int n)
{
	int i;
	int *result = (int *)malloc(sizeof(int)*MAX_SIZE);
	int curr_size = 1;
	
	result[0] = 1;
	
	for( i = 2; i <= n; i++ ) {
		curr_size = multiply(i, result, curr_size);
	}
	
	printf("\nCalculated factorial: ");
	for( i = curr_size-1; i >= 0; i-- ) {
		printf("%d", result[i]);
	}
}

int main()
{
	int n;
	printf("Enter the number: ");
	scanf("%d", &n);
	printFactorial(n);
	return 0;
}
