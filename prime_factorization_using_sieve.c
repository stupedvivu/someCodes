//program to print all the prime factors of a number using
//Sieve of Eratosthenes
//O(logN)
//main optimization is to run sieve() function once
//the range of N is utpo 10^7
#include <stdio.h>
#define MAXN 1000001

int spf[MAXN];

void sieve()
{
	int i, j;
	
	//spf of all the numbers are the numbers itself
	for( i = 1; i < MAXN; i++ ) {
		spf[i] = i;
	}
	
	//all the even numbers have spf 2
	for( i = 2; i < MAXN; i+=2 ) {
		spf[i] = 2;
	}
	
	//remaining numbers are odds
	for( i = 3; i*i < MAXN; i++ ) {
		
		//if the number is prime
		if( spf[i] == i ) {
			
			//iterate through all the mulitples of i
			for( j = i*i; j < MAXN; j+=i ) {
				
				//if number is prime 
				//i is the spf 
				if( spf[j] == j ) {
					spf[j] = i;
				}
			} 	
		}
	}
		
}

void printPrimeFactors(int n)
{
	while( n != 1 ) {
		printf("%d ", spf[n]);
		n = n / spf[n];
	}
} 

int main()
{
	int n;
	printf("\nEnter the number: ");
	scanf("%d", &n);
	sieve();
	printf("\n");
	printPrimeFactors(n);
	return 0;
}
