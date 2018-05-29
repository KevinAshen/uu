//输入n 
//最近复习了递归 正好试一下 
//输出个数 
#include<stdio.h>
int fun(int n)
{
	int m=0,i;
	if(n==1||n==0){
		m=1;
	} else {
		for(i=0;i<=n/2;i++){
			m+=fun(i);
		}
	}
	return m;
}
int main(void)
{
	int n,m=0,i;
	scanf("%d",&n);
	printf("%d",fun(n));
	return 0;
}
