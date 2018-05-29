#include<stdio.h>
#define maxn 500
int main (void)
{
	int N,counter=1;
	int i=1,j=1,flag=1;
	scanf ("%d",&N);
	//N=N+1;
	while (1) {
		if (counter==N) {
			break;
		}
		j++;
		counter++;
		if (counter==N) {
			break;
		}
		//printf ("%d/%d\n",i,j);
		while (j!=1) {
			i++;
			j--;
			counter++;
			if (counter==N) {
				flag=0;
				break;
			}
			//printf ("%d/%d\n",i,j);
		}
		if (flag==0) {
			break;
		}
		i++;
		counter++;
		if (counter==N) {
			break;
		}
		//printf ("%d/%d\n",i,j);
		while (i!=1) {
			j++;
			i--;
			counter++;
			if (counter==N) {
				flag=0;
				break;
			}
			//printf ("%d/%d\n",i,j);
		}
		if (flag==0) {
			break;
		}
	}
	printf ("%d/%d",i,j);
	return 0;
}
