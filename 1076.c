#include<stdio.h>
#define maxn 105
int main (void)
{
	int n,len;
	int i=0,j,t;
	int sum[maxn];
	scanf ("%d",&n);
	while (n--) {
		scanf ("%d",&sum[i++]);
	}
	len=i;
	for (i=0;i<len-1;i++) {
		for (j=i+1;j<len;j++) {
			if (sum[i]>sum[j]) {
				t=sum[i];
				sum[i]=sum[j];
				sum[j]=t;
			}
		}
	}
	for (i=0;i<len;i++) {
		printf ("%d ",sum[i]);
	}
	return 0;
} 
