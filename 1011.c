//����n 
//�����ϰ�˵ݹ� ������һ�� 
//������� 
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
