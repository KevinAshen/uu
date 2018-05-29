//可以先遍历一遍找出哪个小写字母
//表示负数的只能出现在第一个和等号后一个
//字母前面那个数是做的乘法
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
	//对第一段的字母处理 
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
	//接下来对数字进行处理
	//我们先找符号 符号前面（等号也算）如果不是字母说明
	//不对 想一下 现在对字母处理过了 能不能把字母那一块全去掉？
	//把除了字母和所带符号之外的东西放入新的字符串 
	//还是不对 字母前可能有数字 这样还是便麻烦了 md真的烦
	//还是走老路 从第二个符号开始 如果前一个不是字母 就是数字  
	//不行 考虑到还有可能没有第二个 还是得写入
	//这样可以把x与前面系数变成$ 但是符号没变
	for (j3=0;j3<len;j3++) {
		if (equ[j3]=='$'&&(equ[j3-1]=='+'||equ[j3-1]=='-')) {
			equ[j3-1]='$';
		}
	} 
	//printf ("%s\n",equ);
	//此时所有不需要的都是$ 接下来我们把这个字符串写入新的 
	j4=0;
	for (i4=0;i4<=sub_equal;i4++) {
		if (equ[i4]!='$') {
			equ_num1[j4++]=equ[i4];
		}
	} 
	equ_num1[j4]='\0'; 
	//printf ("%s\n",equ_num1);
	//至此 把等号前的与数字有关的放入了数组
	//剩下的明天来
	//目前在算出左边的数字结果后 最重要的是怎么处理右边的
	//也许可以在最开始加一个+ 最后面填一个等于好
	//反正优化是不会优化了 复制粘贴注意不要出错 
	//如何处理数字？从开始遍历在符号之间经行得出数字
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
	//至此 左半边全部处理完毕 未知数参数为res_x 数字参数为res_num1
	//接下来开始处理有右半边 还是那句话 复制粘贴 注意每一项参数改变 
	//先修改右边等式
	equ2[len]='=';
	equ2[len+1]='\0';
	//printf ("%s\n",equ2);
	//接下来放入第一个加号（如果第一个不是符号）
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
	//至此equ中存放的是后半端 且被处理过 接下来 开始复制代码
	sub_equal=i6-1;
	len=strlen(equ);
	res_x2=0;
	//对第一段的字母处理 
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
	//此时所有不需要的都是$ 接下来我们把这个字符串写入新的 
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
	//至此所有该处理的都处理了 开始算结果
	//上天保佑 千万别错了
	res_x=res_x1-res_x2;
	res_num=res_num2-res_num1;
	//printf ("%d %d",res_x,res_num);
	result=(double)res_num/res_x;
	printf ("%c=%.3lf",x,result);	
	return 0; 
} 
