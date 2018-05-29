#include<stdio.h>
int main (void)
{
	int k,n;
	int i=1;
	double sum=1;
	scanf ("%d",&k);
	while (i++) {
		sum+=1.0/i;
		if (sum>k) {
			printf ("%d",i);
			break;
		}
	}
	return 0;
} 
