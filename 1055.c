//Ҳ����Ҫ��Ƶ�ʽ��н������� Ȼ���ڰ����ֵ�˳��������ε���ɫ 
#include<stdio.h>
#include<string.h>
struct balloon {
	char colour [20];
	int counter;
}kid[100];
int main (void)
{
	struct balloon t;
	int N,num_colour,num_now;
	int i,j,flag,max,i1;
	char colour[20];
	for (i=0;i<101;i++) {
		kid[i].counter=0;
	}
	i=0;
	scanf ("%d",&N);
	while (N--) {
		flag=0;
		scanf ("%s",colour);
		for (j=0;j<i+1;j++) {
			if (strcmp(colour,kid[j].colour)==0) {
				kid[j].counter++;
				flag=1;
				break;
			}
		}
		if (flag==0) {
			kid[i].counter++;
			strcpy(kid[i++].colour,colour);
		}
	} 
	//printf ("%s %d %s %d",kid[0].colour,kid[0].counter,kid[1].colour,kid[1].counter);
	//���Ͻ���ɫд�� ��ͳ����ÿ����ɫ����Ŀ ��ʱi�����м�����ɫ
	num_colour=i;
	//for (i=0;i<num_colour;i++) {
	//	printf ("%s %d\n*************\n",kid[i].colour,kid[i].counter);
	//}
	for (i=0;i<num_colour-1;i++) {
		for (j=i+1;j<num_colour;j++) {
			if ((kid[i].counter<kid[j].counter)||(kid[i].counter==kid[j].counter&&(strcmp(kid[i].colour,kid[j].colour)>0))) {
				t=kid[i];
				kid[i]=kid[j];
				kid[j]=t;
			}
		}
	}
	//for (i=0;i<num_colour;i++) {
	//	printf ("%s %d\n",kid[i].colour,kid[i].counter);
	//}
	//printf ("%s %d %s %d",kid[0].colour,kid[0].counter,kid[1].colour,kid[1].counter);
	//���� ����ɫ����Ƶ�ʽ������� ������Ҫ����ͬ�İ��ֵ����� 
	//??������ȫ�����Ȱ����ֵ����� ���� ������ʵ���
	//��������е��鷳�������� 
	//���� �����ֲ��ỳ�� 
	//������ ��û���� ��ʵ��� 
	//�����ҳ�ͬһcounter��kid 
	max=0;
	for (i=0;i<num_colour;i++) {
		if (max<kid[i].counter) {
			max=kid[i].counter;
		}
	}
	num_now=max;
	printf ("%d\n",num_colour);
	printf ("%d\n",num_now);
	for (i=0;i<num_colour;i++) {
		if (num_now==kid[i].counter) {
			printf ("%s\n",kid[i].colour);
		} else {
			num_now=kid[i].counter;
			printf ("%d\n",num_now);
			printf ("%s\n",kid[i].colour);
		}
	}
	return 0;
} 
