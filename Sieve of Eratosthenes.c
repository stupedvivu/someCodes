/*
  problem: print prime numbers upto a given input N using Sieve of Eratosthenes method
*/

#include <stdio.h>
#include <stdlib.h>

void printPrimeUptoN(int n)
{
    int *table = (int *)malloc(sizeof(int)*(n+1));
    
    for( int i = 0; i <= n; i++ ) {
        table[i] = 1;
    }
    
    for( int i = 2; i <= n; i++ ) {
        int j = 2;
        
        while( (i*j) <= n ) {
            table[i*j] = 0;
            j++;
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
