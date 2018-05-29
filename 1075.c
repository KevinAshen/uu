//输入T组数据 n个随机数 分别写入  
//放入数组stu_num 放入bocket桶 
//有就输出个数M 与分别 
#include<stdio.h>
#include<string.h>
#define maxn1 1050
//#define maxn2 150
int main (void)
{
	int n,M;
	int i,stu_num;
	int bocket [maxn1];
	//int stu_num [maxn2];
	M=0;
	memset(bocket,0,sizeof(bocket));
	scanf("%d",&n);
	while (n--) {
		scanf ("%d",&stu_num);
		bocket[stu_num]++;
		if (bocket[stu_num]==1) {
			M++;
		}
	}
	printf ("%d\n",M);
	for (i=0;i<maxn1;i++) {
		if (bocket[i]>0) {
			printf ("%d ",i);
		}
	}
	printf ("\n"); 
}
