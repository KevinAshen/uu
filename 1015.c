//�����ȱ���һ���ҳ��ĸ�Сд��ĸ
//��ʾ������ֻ�ܳ����ڵ�һ���͵Ⱥź�һ��
//��ĸǰ���Ǹ��������ĳ˷�
#include<stdio.h>
#include<string.h>
#define maxn 500
int main (void)
{
	int len,sub_equal,sub_x,sum,res_x1,len_equ_num1,res_num1,res_x2,len_equ_num2,res_num2,res_num,res_x;
	int i,j,i1,j1,i2,j2,i3,j3,i4,j4,i5,j5,i6,j6,i7,j7;
	double result; 
	char equ[maxn],equ1[maxn],equ_num1[maxn],equ2[maxn],equ_num2[maxn];
	char x,sym_x;
	scanf ("%s",equ);
	getchar ();
	len=strlen(equ);
	if (equ[0]!='+'&&equ[0]!='-') {
		for (i3=0;i3<len;i3++) {
			equ1[i3+1]=equ[i3];
		}
		equ1[len+1]='\0';
		equ1[0]='+';
		strcpy(equ,equ1);
	}
	//printf ("%s\n",equ)
	len=strlen(equ);
	//printf ("%s",equ1);
	for (i=0;i<len;i++) {
		if (equ[i]>='a'&&equ[i]<='z') {
			x=equ[i];
			break;
		}
	}
	//printf ("%d123%c",len,x);
	for (j=0;j<len;j++) {
		if (equ[j]=='=') {
			sub_equal=j;
			break;
		}
	}
	strcpy(equ2,equ);
	res_x1=0;
	//�Ե�һ�ε���ĸ���� 
	for (i1=0;i1<sub_equal;i1++) {
		if (equ[i1]==x) {
			equ[i1]='$'; 
			sum=0;
			for (j1=i1-1;equ[j1]>='0'&&equ[j1]<='9';j1--) {
					;
			}
			sym_x=equ[j1];
			//printf ("%d\n",j1);
			for (i2=j1+1;i2<i1;i2++) {
				sum=sum*10+(equ[i2]-'0');
				equ[i2]='$';
			}
			//printf ("%d\t",sum);
			//printf ("%c\n",sym_x);
			if (sym_x=='-') {
				res_x1-=sum;
			} else {
				res_x1+=sum;
			}
		}
	}
	//printf ("%d\n",res_x1);
	//printf ("%s\n",equ);
	//�����������ֽ��д���
	//�������ҷ��� ����ǰ�棨�Ⱥ�Ҳ�㣩���������ĸ˵��
	//���� ��һ�� ���ڶ���ĸ������� �ܲ��ܰ���ĸ��һ��ȫȥ����
	//�ѳ�����ĸ����������֮��Ķ��������µ��ַ��� 
	//���ǲ��� ��ĸǰ���������� �������Ǳ��鷳�� md��ķ�
	//��������· �ӵڶ������ſ�ʼ ���ǰһ��������ĸ ��������  
	//���� ���ǵ����п���û�еڶ��� ���ǵ�д��
	//�������԰�x��ǰ��ϵ�����$ ���Ƿ���û��
	for (j3=0;j3<len;j3++) {
		if (equ[j3]=='$'&&(equ[j3-1]=='+'||equ[j3-1]=='-')) {
			equ[j3-1]='$';
		}
	} 
	//printf ("%s\n",equ);
	//��ʱ���в���Ҫ�Ķ���$ ���������ǰ�����ַ���д���µ� 
	j4=0;
	for (i4=0;i4<=sub_equal;i4++) {
		if (equ[i4]!='$') {
			equ_num1[j4++]=equ[i4];
		}
	} 
	equ_num1[j4]='\0'; 
	//printf ("%s\n",equ_num1);
	//���� �ѵȺ�ǰ���������йصķ���������
	//ʣ�µ�������
	//Ŀǰ�������ߵ����ֽ���� ����Ҫ������ô�����ұߵ�
	//Ҳ��������ʼ��һ��+ �������һ�����ں�
	//�����Ż��ǲ����Ż��� ����ճ��ע�ⲻҪ���� 
	//��δ������֣��ӿ�ʼ�����ڷ���֮�侭�еó�����
	len_equ_num1=strlen(equ_num1);
	res_num1=0;
	for (i5=0;i5<len_equ_num1;i5++) {
		if (equ_num1[i5]=='+'||equ_num1[i5]=='-') {
			sum=0;
			for (j5=i5+1;equ_num1[j5]>='0'&&equ_num1[j5]<='9';j5++) {
				sum=sum*10+equ_num1[j5]-'0';
			}
			//printf ("%d\n",sum);
			if (equ_num1[i5]=='+') {
				res_num1+=sum;
			} else {
				res_num1-=sum;
			}
			//printf ("%d\n",res_num1);
		}
	}
	//���� ����ȫ��������� δ֪������Ϊres_x ���ֲ���Ϊres_num1
	//��������ʼ�������Ұ�� �����Ǿ仰 ����ճ�� ע��ÿһ������ı� 
	//���޸��ұߵ�ʽ
	equ2[len]='=';
	equ2[len+1]='\0';
	//printf ("%s\n",equ2);
	//�����������һ���Ӻţ������һ�����Ƿ��ţ�
	if (equ2[sub_equal+1]=='-') {
		i6=0;
	} else {
		i6=1;
		equ1[0]='+';
	}
	for (i7=sub_equal+1;equ2[i7]!='\0';i7++) {
		equ1[i6++]=equ2[i7];
	}
	equ1[i6]='\0';
	//printf ("%s\n",equ1);
	strcpy(equ,equ1);
	//����equ�д�ŵ��Ǻ��� �ұ������ ������ ��ʼ���ƴ���
	sub_equal=i6-1;
	len=strlen(equ);
	res_x2=0;
	//�Ե�һ�ε���ĸ���� 
	for (i1=0;i1<sub_equal;i1++) {
		if (equ[i1]==x) {
			equ[i1]='$'; 
			sum=0;
			for (j1=i1-1;equ[j1]>='0'&&equ[j1]<='9';j1--) {
					;
			}
			sym_x=equ[j1];
			//printf ("%d\n",j1);
			for (i2=j1+1;i2<i1;i2++) {
				sum=sum*10+(equ[i2]-'0');
				equ[i2]='$';
			}
			//printf ("%d\t",sum);
			//printf ("%c\n",sym_x);
			if (sym_x=='-') {
				res_x2-=sum;
			} else {
				res_x2+=sum;
			}
			//printf ("%d**\n",res_x2);
		}
	}
//	printf ("%d\n",res_x2);
	//printf ("%s\n",equ);
	for (j3=0;j3<len;j3++) {
		if (equ[j3]=='$'&&(equ[j3-1]=='+'||equ[j3-1]=='-')) {
			equ[j3-1]='$';
		}
	} 
	//printf ("%s\n",equ);
	//��ʱ���в���Ҫ�Ķ���$ ���������ǰ�����ַ���д���µ� 
	j4=0;
	for (i4=0;i4<=sub_equal;i4++) {
		if (equ[i4]!='$') {
			equ_num2[j4++]=equ[i4];
		}
	} 
	equ_num2[j4]='\0'; 
	len_equ_num2=strlen(equ_num2);
	res_num2=0;
	for (i5=0;i5<len_equ_num2;i5++) {
		if (equ_num2[i5]=='+'||equ_num2[i5]=='-') {
			sum=0;
			for (j5=i5+1;equ_num2[j5]>='0'&&equ_num2[j5]<='9';j5++) {
				sum=sum*10+equ_num2[j5]-'0';
			}
			//printf ("%d\n",sum);
			if (equ_num2[i5]=='+') {
				res_num2+=sum;
			} else {
				res_num2-=sum;
			}
			//printf ("%d\n",res_num2);
		}
	}
	//�������иô���Ķ������� ��ʼ����
	//���챣�� ǧ������
	res_x=res_x1-res_x2;
	res_num=res_num2-res_num1;
	//printf ("%d %d",res_x,res_num);
	result=(double)res_num/res_x;
	printf ("%c=%.3lf",x,result);	
	return 0; 
} 
