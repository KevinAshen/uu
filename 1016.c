//����������������볬����󵥼۵�����������޵��أ� 
//��Ҫ֪����Ӧ����Ϊ���� 
//
#include<stdio.h>
#define maxn 100 
int main (void)
{
	int con,len,cost,sales_cost,sales_out,price_out,change_out;
	int price_con,sales_con;
	int i=0,j=0,t,copy,flag;
	int price[maxn],sales[maxn];
	double change_in,profit,max,profit_con;
	scanf ("%d",&price_con);//��������
	//scanf ("%d %d",&cost,&price_cost);
	while (1) {
		scanf ("%d %d",&price[i],&sales[i]);
		//���뵥�������� ��-1 -1�� 
		if (price[i]==-1) {
			break;
		}
		//iΪ-1�±�
		i++; 
	}
	cost=price[0];
	sales_cost=sales[0];
	scanf ("%d",&change_out);
	//for (j=0;j<i;j++) {
	//	printf ("%d %d\n",price[j],sales[j]);
	//}
	len=i;//��Ч���ݵĳ��� 
	for (i=0;i<len-1;i++) {
		for (j=i+1;j<len;j++) {
			if (price[i]>price[j]) {
				t=price[i];
				price[i]=price[j];
				price[j]=t;
				t=sales[i];
				sales[i]=sales[j];
				sales[j]=t;
			}
		}
	}
	//�����۴�С�������� Ҳ����ζ����������������
	//for (j=0;j<len;j++) {
	//	printf ("%d %d\n",price[j],sales[j]);
	//}
	max=0;
	for (i=0;i<len-1;i++) {
		change_in=(double)(sales[i+1]-sales[i])/(price[i+1]-price[i]);
		for (j=price[i];j<=price[i+1];j++) {
			if (j==price_con) {
				sales_con=(j-price[i])*change_in+sales[i];
			}
			profit=(j-cost)*((j-price[i])*change_in+sales[i]);
			//printf ("%.2lf\n",profit);
			if (max<profit) {
				max=profit;
			}
		}
	}
	//�ó����������ڵ��������
	sales_out=sales[len-1];
	price_out=price[len-1];
	//copy=price_out;
	while (sales_out>0) {
		price_out++;
		sales_out-=change_out;
		if (price_out==price_con) {
			sales_con=sales_out;
		}
		profit=(price_out-cost)*sales_out;
		if (max<profit) {
			max=profit;
		}
	}
	//printf ("%.2lf",max);
	//����޵��ص�������� 
	//printf ("%d %d",price_con,sales_con);
	//�ҵ���������
	
	
	//profit_con=(double)(price_con-cost)*sales_con;
	//printf("%.2lf %.2lf\n",profit_con,max); 
	con=0;
	flag=1;
	//int ojbk=10;
	while (1) {
	//	printf ("%.2lf\n",max);
		profit_con=(double)(price_con-cost+con)*sales_con;
	//	printf ("%.2lf\n",profit_con);
		if (profit_con>=max) {
			break;
		}
		max=0;
		//printf ("%.2lf\n",max);
		//printf ("1324");
		if (flag==1) {
			con*=-1;
			con++;
			flag*=-1;
		} else {
			con*=-1;
			flag*=-1;
		}
		for (i=0;i<len-1;i++) {
			change_in=(double)(sales[i+1]-sales[i])/(price[i+1]-price[i]);
		for (j=price[i];j<=price[i+1];j++) {
			if (j==price_con) {
				sales_con=(j-price[i])*change_in+sales[i];
			}
			profit=(j-cost+con)*((j-price[i])*change_in+sales[i]);
			//printf ("%.2lf\n",profit);
			if (max<profit) {
				max=profit;
			}
		}
		//printf ("%.2lf\n",max);
	}
	//�ó����������ڵ��������
	sales_out=sales[len-1];
	price_out=price[len-1];
	//copy=price_out;
	while (sales_out>0) {
		price_out++;
		sales_out-=change_out;
		if (price_out==price_con) {
			sales_con=sales_out;
		}
		profit=(price_out-cost+con)*sales_out;
		if (max<profit) {
			max=profit;
		}
	}
	}
	//printf ("%.2lf",profit_con);
	printf ("%d",con);
	return 0;
} 
