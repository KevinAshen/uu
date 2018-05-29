#include<stdio.h>
#define maxn 30
int main (void)
{
	int a,b,max=0;
	int week[maxn];
	int p=0;
	week[0]=-1;
	while (p++<7) {
		scanf ("%d %d",&a,&b);
		week[p]=a+b;
		//printf ("%d##\n",week[p]);
		if (week[max]<week[p]) {
			max=p;
		}
		//printf ("%d##\n",max);
	}
	if (week[max]>8) {
		printf ("%d",max);
	} else {
		printf ("0");
	}
}
