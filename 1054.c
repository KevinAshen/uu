//��ʼ��0 
//һ���жϵ�ǰ���ڲ� ������Ŀ������ ������ �ڼ���ͣ��ʱ��
#include<stdio.h>
int main (void)
{
	int N,level_now=0,level_next,time=0;
	int gap;
	scanf ("%d",&N);
	while (N--) {
		scanf ("%d",&level_next);
		gap=level_now-level_next;
		if (gap<0) { //���� 
			time+=5;
			time+=gap*(-1)*6;
		} else {
			time+=5;
			time+=gap*4;
		}
		level_now=level_next;
	}
	printf ("%d",time);
	return 0;
} 
