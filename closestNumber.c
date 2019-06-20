/*
  problem: Given two integers n and m. The problem is to find the number closest to n and divisible by m. 
           If there are more than one such number, then output the one having maximum absolute value. 
           If n is completely divisible by m, then output n only.
  closestNumber(n, m)
    Declare q, n1, n2
    q = n / m
    n1 = m * q

    if (n * m) > 0
        n2 = m * (q + 1)
    else
        n2 = m * (q - 1)

    if abs(n-n1) < abs(n-n2)
        return n1
    return n2 
*/

#include<stdio.h>

int closestNumber(int n, int m)
{
    int q = n / m;
    int n1 = q * m;
    
    int n2 = (n*m)>0?(m*(q+1)):(m*(q-1));
    
    return abs(n-n1)<abs(n-n2)?n1:n2;
}

int main()
{
	//code
	int t;
	int n, m;
	scanf("%d", &t);
	
	while( t > 0 ) {
	    scanf("%d", &n);
	    scanf("%d", &m);
	    
	    printf("%d\n", closestNumber(n,m));
	    t--;
	}
	return 0;
}
