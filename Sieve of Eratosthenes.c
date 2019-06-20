/*
  problem: print prime numbers upto a given input N using Sieve of Eratosthenes method
*/

#include <stdio.h>
#include <stdlib.h>

void printPrimeUptoN(int n)
{
    int i, j;
    
    int table[n+1];
    
    for( int i = 2; i <= n; i++ ) {
        table[i] = 1;
    }
    
    for( i = 2; i*i <= n; i++ ) {
        if( table[i] == 1 ) {
            for( j = i*i; j <= n; j += i ) {
                table[j] = 0;
            }
        }
    }
    
    for( int i = 2; i <= n; i++ ) {
        if( table[i] == 1 ) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
	//code
	int t;
	scanf("%d", &t);
	
	while( t > 0 ) {
	    int n;
	    scanf("%d", &n);
	    printPrimeUptoN(n);
	    t--;
	}
	return 0;
}
