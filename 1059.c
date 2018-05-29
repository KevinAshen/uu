//我们可以不去考虑环形的事 自己去截 另一种就是干脆放在新的数组中 感觉就比较好 
#include<stdio.h>
#define maxn 550
int main (void)
{
	int station[maxn],gasoline[maxn],station_new[maxn],gasoline_new[maxn],sum;
	int N;
	int i,j,i1,j1,flag,flag2=0;
	scanf ("%d",&N);
	for (i=0;i<N;i++) {
		scanf ("%d",&station[i]);
	}
	for (i=0;i<N;i++) {
		scanf ("%d",&gasoline[i]);
	}
	for (i=0;i<N;i++) {
		i1=0;
		j1=0;
		sum=0;
		flag=1;
		for (j=i;j<N;j++) {
			station_new[i1++]=station[j];
			gasoline_new[j1++]=gasoline[j];
		} 
		for (j=0;j<i;j++) {
			station_new[i1++]=station[j];
			gasoline_new[j1++]=gasoline[j];
		}
		//for (j=0;j<N;j++) {
		//	printf ("%d %d\n",station_new[j],gasoline_new[j]);
		//}
		for (j=0;j<N;j++) {
			sum+=station_new[j];
			sum-=gasoline_new[j];
			//printf ("%d %d\n",sum,i);
			if (sum<0) {
				flag=0;
				break;
			}
		}
		if (flag==1) {
			printf ("%d ",i+1);
			flag2=1;
		}
	}
	//至此我们将每一种可能都放在新数组中 接下来考虑汽油 
	if (flag2==0) {
		printf ("No Result!");
	}
	return 0;
} 
