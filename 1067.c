//看到这道题 脑中出现两个字 取余
#include<stdio.h>
#define maxn 1010
int main (void)
{
	int memory[maxn],article[maxn];
	int M,N,counter=0,word;
	int i,flag,order=0;
	scanf ("%d %d",&M,&N);
	while (N--) {
		flag=0;
		scanf ("%d",&word);
		for (i=0;i<M;i++) {
			if (word==memory[i]) {
				flag=1;
				break;
			}
		}
		if (flag==0) {
			memory[(order++)%M]=word;
			counter++;
		}
	}
	printf ("%d",counter);
	return 0;
} 
