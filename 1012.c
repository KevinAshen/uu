//输入x0(最大公约) y0(最小公倍)
//建立两个函数分别求最小公约 与 最大公倍
//依次搜索P Q 记录次数（x0与y0之间）
//输出次数
#include<stdio.h>
int Min_yue (int i,int j);
int Max_bei (int i,int j);
int main (void)
{
	int x0,y0,count;
	int i,j;
	count=0;
	scanf ("%d%d",&x0,&y0);
	//printf ("%d\n",Min_yue(x0,y0));
	//printf ("%d\n",Max_bei(x0,y0));
	for (i=x0;i<y0+1;i+=x0) {
		j=(x0*y0)/i; 
			if (Min_yue(i,j)==x0&&Max_bei(i,j)==y0) {
				count++;
				//printf ("%d %d\n",i,j);
			}
	}
	printf ("%d",count);
	return 0;
} 
int Min_yue (int i,int j)
{
	int sum=0;
	int i1;
	for (i1=2;i1<i+1;i1++) {
		if (i%i1==0&&j%i1==0) {
			sum=i1;
		}
	}
	return sum;
}
int Max_bei (int i,int j)
{
	int sum=0;
	int i1;
	for (i1=j;i1<i*j+1;i1++) {
		if (i1%j==0&&i1%i==0) {
			sum=i1;
			break;
		}
	}
	return sum;
}
